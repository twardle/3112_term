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
#include <sstream>
#include <ctime>
#include <map>
#include <vector>

#include <cstdlib>
#include "Environment.h"
#include "Creature.h"
#include "Trait.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Omnivore.h"

using namespace std;

int const NUMSPECIES = 10;
int const NUMCREATURES = 100;
int const NUMSEASONS = 4;

int sUsed = 0;
int cUsed = 0;
int hUsed = 0;
int oUsed = 0;

void creatureInstantiation(Environment,Creature[],Carnivore[],Herbivore[],Omnivore[]);

int main()
{
	//Main Variables
	Environment Env = Environment(); //Create environment
	Creature * sList = NULL;
	Carnivore * cList = NULL;
	Herbivore * hList = NULL;
	Omnivore * oList = NULL;
	sList = new Creature[NUMSPECIES * NUMCREATURES];
	cList = new Carnivore[NUMSPECIES * NUMCREATURES];
	hList = new Herbivore[NUMSPECIES * NUMCREATURES];
	oList = new Omnivore[NUMSPECIES * NUMCREATURES];
	int current = 0;
	int numDead = 0;


	string userSeed;

	//Get user input for program seed
	cout << "INPUT SEED:\t";
	std::cin >> userSeed;
	std::stringstream ss ( userSeed);
	std::stringstream species;
	int seed = 0;
	for (unsigned int i = 0; i < userSeed.length(); i++)
	    {
	        char x = userSeed.at(i);
	        seed += int(x);
	    }
	srand( seed );
	int random_biome = (rand() % 5);
	Env = Environment(random_biome);
	Env.readTraits(); //Get traits

	creatureInstantiation(Env,sList,cList,hList,oList);

	for(int i = 0; i < sUsed; i++){
			sList[i].calcStats(Env);
			cout << sList[i].toString() << endl;
	}
	//cout << "Random Biome: " << random_biome << endl;

	//Set season and biome

	//Get season
	//cout << "Biome: " << Env.get_biome() << endl;

	//Implement change of season
	do
	{
		for(int i = 0; i < sUsed; i++){
			if(sList[i].getHealth() > 0)
				if (!sList[i].updateHealth(Env)){
					cout << sList[i].toString() << endl;
					numDead++;
					}
				}
		//TODO Update values

		//Get new season
		//cout << "Season: " << Env.get_season().getSeason() << endl;
		//cout << "Temp: " << Env.get_temp() << endl;

		//Change the season
		Env.changeseason();

		//cout << "New Season...\n" << endl;

		//Increment current
		current++;
	}while(current < NUMSEASONS);
	int count = 0;

	for(int i = 0; i < sUsed; i++){
		if (sList[i].getHealth() > 0){
			count++;
			//cout << sList[i].toString() << endl;
		}
	}
	cout << "Water Supply:\t" << Env.get_water_supply() << ", Number Dead:\t" << numDead;;
	delete [] cList;

	return 0;
}

void creatureInstantiation(Environment Env, Creature sList[], Carnivore cList[], Herbivore hList[], Omnivore oList[]){
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
				sList[sUsed++] = newCarnivore;
				cList[cUsed++] = newCarnivore;
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
				sList[sUsed++] = newOmnivore;
				oList[oUsed++] = newOmnivore;
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
				sList[sUsed++] = newHerbivore;
				hList[hUsed++] = newHerbivore;
			}
			break;
		default:
			cout << "err" << std::endl;
		}
	}
}
