//============================================================================
// Name        : EnvSim.cpp
// Author      : Tyler Wardle and Candace Allison
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "Environment.h"
#include "Creature.h"
#include "Trait.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Omnivore.h"

using namespace std;

//global variables
int const NUMSPECIES = 10;
int const NUMCREATURES = 100;
int const NUMSEASONS = 4;
int sUsed = 0;
int cUsed = 0;
int hUsed = 0;
int oUsed = 0;

struct cCoords{
	string species;
	int creature;
	bool alive = true;
};

int iterateSeason(Environment&, Creature [], cCoords [], cCoords [], cCoords []);

void creatureInstantiation(Environment,Creature[],cCoords[],cCoords[],cCoords[]);

int translateSeed(string);

int main()
{
	//Main Variables
	Environment Env = Environment(); //Create environment
	Creature * sList = NULL;
	cCoords * cList = NULL;
	cCoords * hList = NULL;
	cCoords * oList = NULL;
	sList = new Creature[NUMSPECIES * NUMCREATURES];
	cList = new cCoords[NUMSPECIES * NUMCREATURES];
	hList = new cCoords[NUMSPECIES * NUMCREATURES];
	oList = new cCoords[NUMSPECIES * NUMCREATURES];
	int numDead = 0;
	string userSeed;

	//Get user input for program seed
	cout << "INPUT SEED:\t";
	std::cin >> userSeed;
	int seed = translateSeed(userSeed);
	srand( seed );
	int random_biome = (rand() % 5);
	Env = Environment(random_biome);
	Env.readTraits(); //Get traits

	creatureInstantiation(Env,sList,cList,hList,oList);

	//calculate stats for every creature
	for(int i = 0; i < sUsed; i++){
			sList[i].calcStats(Env);
	}

	//iterate seasons
	for(int i = 0; i < NUMSEASONS; i++){
		numDead += iterateSeason(Env, sList, cList, oList, hList);

		Env.changeseason();
	}

	cout << "\nWater Supply:\t" << Env.get_water_supply() << "\nNumber Dead:\t" << numDead << "\nBiome:\t" << Env.get_biome();
	delete [] cList;

	return 0;
}

int translateSeed(string userSeed){
	int seed = 0;
	for (unsigned int i = 0; i < userSeed.length(); i++)
		    {
		        char x = userSeed.at(i);
		        seed += int(x);
		    }
	return seed;
}

int iterateSeason(Environment & Env, Creature sList[], cCoords cList[], cCoords oList[], cCoords hList[]){
	int numDead = 0;

	for(int i = 0; i < hUsed; i++){
		if(hList[i].alive){
			if(sList[oList[i].creature].getHealth() < 0){
				hList[i].alive = false;
				numDead++;
			}
			((Herbivore)(sList[oList[i].creature])).herd();
		}
	}

	for(int i = 0; i < oUsed; i++){
		int num = rand() % 2;
		if(oList[i].alive){
			if(sList[oList[i].creature].getHealth() < 0){
				oList[i].alive = false;
				numDead++;
			}
			else if(num == 1){
				int creature = rand() % sUsed;
				if(sList[creature] != sList[oList[i].creature])
					((Omnivore)(sList[oList[i].creature])).hunt(sList[creature]);
			}
			else{
				((Omnivore)(sList[oList[i].creature])).herd();
			}
		}
	}

	for(int i = 0; i < cUsed; i++){
		if(cList[i].alive){
			if(sList[cList[i].creature].getHealth() < 0){
				cList[i].alive = false;
				numDead++;
			}
			else{
				int creature = rand() % sUsed;
				if(sList[creature] != sList[cList[i].creature])
					((Carnivore)(sList[cList[i].creature])).hunt(sList[creature]);
			}
		}
	}

	for(int i = 0; i < sUsed; i++){
		if(sList[i].getHealth() > 0)
			if (sList[i].updateHealth(Env)){
				cout << sList[i].toString() << endl;
			}
		}

	return numDead;
}

void creatureInstantiation(Environment Env, Creature sList[], cCoords cList[], cCoords hList[], cCoords oList[]){
	for(int i = 0; i < NUMSPECIES; i++)
	{
		int cType = rand() % 3;
		bool dominance;
		string species = "";
		Carnivore newCarnivore;
		Omnivore newOmnivore;
		Herbivore newHerbivore;
		switch (cType){
		case 0:
			newCarnivore.setTrait(0,Env.traitList[0][2]);
			for(int i = 1; i < 5 ; i++){
				for(int j = 0; j < 6; j++){
					dominance = rand() % 2;
					if(Env.traitList[i][j].getAnimalType() == 2)
							if(Env.traitList[i][j].getDominance() == dominance){
								newCarnivore.setTrait(i,Env.traitList[i][j]);
							}
				}
			}
			species = "C";
			for(int i = 1; i < 5; i++)
				species += (newCarnivore.getTrait(i).getTraitName()).at(0);
			newCarnivore.setSpecies(species);
			for(int j = 0; j < NUMCREATURES; j++){
				cCoords temp;
				temp.creature = sUsed;
				temp.species = newCarnivore.getSpecies();
				sList[sUsed++] = newCarnivore;
				cList[cUsed++] = temp;
			}
			break;
		case 1:
			newOmnivore.setTrait(0,Env.traitList[0][1]);
			for(int i = 1; i < 5 ; i++){
				for(int j = 0; j < 6; j++){
					dominance = rand() % 2;
					if(Env.traitList[i][j].getAnimalType() == 1)
						if(Env.traitList[i][j].getDominance() == dominance)
							newOmnivore.setTrait(i,Env.traitList[i][j]);
				}
			}
			species = "O";
			for(int i = 1; i < 5; i++)
				species += (newOmnivore.getTrait(i).getTraitName()).at(0);
			newOmnivore.setSpecies(species);
			for(int j = 0; j < NUMCREATURES; j++){
				cCoords temp;
				temp.creature = sUsed;
				temp.species = newOmnivore.getSpecies();
				sList[sUsed++] = newOmnivore;
				oList[oUsed++] = temp;
			}
			break;
		case 2:
			newHerbivore.setTrait(0,Env.traitList[0][0]);
			for(int i = 1; i < 5 ; i++){
				for(int j = 0; j < 6; j++){
					dominance = rand() % 2;
					if(Env.traitList[i][j].getAnimalType() == 0)
							if(Env.traitList[i][j].getDominance() == dominance)
								newHerbivore.setTrait(i,Env.traitList[i][j]);
				}
			}
			species = "H";
			for(int i = 1; i < 5; i++)
				species += (newHerbivore.getTrait(i).getTraitName()).at(0);
			newHerbivore.setSpecies(species);
			for(int j = 0; j < NUMCREATURES; j++){
				cCoords temp;
				temp.creature = sUsed;
				temp.species = newOmnivore.getSpecies();
				sList[sUsed++] = newHerbivore;
				hList[hUsed++] = temp;
			}
			break;
		default:
			cout << "err" << std::endl;
		}
	}
}
