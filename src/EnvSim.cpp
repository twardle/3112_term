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

bool const PRINT_CREATURES = false;
bool const PRINT_DEBUG_POP = false;
bool const PRINT_DEBUG_HUNT = false;
bool const PRINT_BIOME_SEASON = false;
bool const DEBUG_PLOT = false;

//global variables
int const NUMSPECIES = 10;
int const NUMCREATURES = 100;
int const NUMSEASONS = 20;
int sUsed = 0;
int cUsed = 0;
int hUsed = 0;
int oUsed = 0;
int sMax = NUMSPECIES * NUMCREATURES * 1000;

struct cCoords{
	string species;
	int creature;
	bool alive = true;
};

struct cCount{
	string species;
	int count;
};

void iterateSeason(Environment&,Creature[],cCoords[],cCoords[],cCoords[]);

void creatureInstantiation(Environment,Creature[],cCoords[],cCoords[],cCoords[]);

void clearDead(Creature[],cCoords[],cCoords[],cCoords[]);

int translateSeed(string);

int main()
{
	//Main Variables
	Environment Env = Environment(); //Create environment
	Creature * sList = NULL;
	cCoords * cList = NULL;
	cCoords * hList = NULL;
	cCoords * oList = NULL;
	cCount * plotCount = NULL;
	plotCount = new cCount[sMax];
	sList = new Creature[sMax];
	cList = new cCoords[sMax];
	hList = new cCoords[sMax];
	oList = new cCoords[sMax];
	int pUsed = 0;
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
		if(sUsed == 0)
			break;
		iterateSeason(Env, sList, cList, oList, hList);
		//cout << Env.get_water_supply() << "," << numDead << endl;
		for(int j = 0; j < sUsed; j++){
			float avgWaterNeed=1.0;
			if(sList[j].getHealth() > 0){
				avgWaterNeed *= sList[j].getWaterNeed();
			}
			//cout << "AVG:" << avgWaterNeed << endl;
		}
		clearDead(sList,cList,oList,hList);
		Env.changeseason();
		if(PRINT_DEBUG_POP)
			cout << "Pop:\t" << sUsed << endl;
	}
	if(PRINT_BIOME_SEASON){
		cout << Env.toString(sUsed);
		cout << Env.get_season().toString() << endl << endl;
	}

	for(int i = 0; i < sUsed; i++){
		int found = false;
		int j;
		for(j = 0; j < pUsed; j++){
			for(int k = 0; k < 5; k++){
				if(plotCount[j].species.at(k) != sList[i].getSpecies().at(k)){
					found = false;
					break;
				}
				else
					found = true;
			}
			if(found)
				break;
		}
		if(found){
			plotCount[j].count++;
		}
		else{
			cCount temp;
			temp.count = 1;
			temp.species = sList[i].getSpecies();
			plotCount[pUsed++] = temp;
		}
	}

	for(int i = 0; i < pUsed; i++)
		if(DEBUG_PLOT)
			cout << plotCount[i].species << "," << plotCount[i].count << endl;

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

void iterateSeason(Environment & Env, Creature sList[], cCoords cList[], cCoords oList[], cCoords hList[]){

	for(int i = 0; i < cUsed; i++){
		if(cList[i].alive){
			if(sList[cList[i].creature].getHealth() < 0){
				cList[i].alive = false;
			}
			else{
				int breed = rand() % cUsed;
				bool breeding = ((((rand() % 200) + 1) / 100.0) <= sList[cList[i].creature].getBreedChance(Env));
				if(breeding){
					if(sUsed < sMax)
						if(hUsed < sMax){
							cCoords temp;
							//TODO:  Consider passing reference creature
							sList[cList[i].creature].breed(sList[cList[breed].creature],rand());
							sList[sUsed].setSpecies();
							sList[sUsed].calcStats(Env);
							temp.species = sList[sUsed].getSpecies();
							temp.creature = sUsed++;
							cList[cUsed++] = temp;
						}
				}
				int creature = rand() % sUsed;
				if(creature != cList[i].creature && sList[creature].getHealth() > 0){
					if(PRINT_DEBUG_HUNT)
						cout << "pre-hunt" << sList[creature].getHealth() << endl;
					((Carnivore)(sList[cList[i].creature])).hunt(sList[creature]);
					if(PRINT_DEBUG_HUNT)
						cout << "hunted" << sList[creature].getHealth() << endl;

				}
			}
		}
	}

	for(int i = 0; i < oUsed; i++){
		if(oList[i].alive){
			if(sList[oList[i].creature].getHealth() < 0){
				oList[i].alive = false;
			}
			else{
				int breed = rand() % oUsed;
				bool breeding = ((((rand() % 200) + 1) / 100.0) <= sList[oList[i].creature].getBreedChance(Env));
				if(breeding){
					if(sUsed < sMax)
						if(oUsed < sMax){
							cCoords temp;
							//TODO:  Consider passing reference creature
							sList[sUsed] = sList[oList[i].creature].breed(sList[oList[breed].creature],rand());
							sList[sUsed].setSpecies();
							sList[sUsed].calcStats(Env);
							temp.species = sList[sUsed].getSpecies();
							temp.creature = sUsed++;
							oList[oUsed++] = temp;
						}
				}
				int creature = rand() % sUsed;
				if(creature != oList[i].creature && sList[creature].getHealth() > 0){
					if(PRINT_DEBUG_HUNT)
						cout << "pre-hunt" << sList[creature].getHealth() << endl;
					((Omnivore)(sList[oList[i].creature])).hunt(sList[creature]);
					if(PRINT_DEBUG_HUNT)
						cout << "hunted" << sList[creature].getHealth() << endl;

				}
			}
		}
	}

	for(int i = 0; i < hUsed; i++){
		if(hList[i].alive){
			if(sList[oList[i].creature].getHealth() <= 0){
				hList[i].alive = false;
			}
			else{
				int breed = rand() % hUsed;
				bool breeding = ((((rand() % 200) + 1) / 100.0) <= sList[hList[i].creature].getBreedChance(Env));
				if(breeding){
					if(sUsed < sMax)
						if(hUsed < sMax){
							cCoords temp;
							//TODO:  Consider passing reference creature
							sList[sUsed] = sList[hList[i].creature].breed(sList[hList[breed].creature],rand());
							sList[sUsed].setSpecies();
							sList[sUsed].calcStats(Env);
							temp.species = sList[sUsed].getSpecies();
							temp.creature = sUsed++;
							hList[hUsed++] = temp;
						}
				}
				//cout << breeding << endl;
			}
		}
	}

	for(int i = 0; i < sUsed; i++){
		if(sList[i].getHealth() > 0)
			if (sList[i].updateHealth(Env) && PRINT_CREATURES){
				cout << sList[i].toString() << endl;
			}
		}
}

void creatureInstantiation(Environment Env, Creature sList[], cCoords cList[], cCoords hList[], cCoords oList[]){
	for(int i = 0; i < NUMSPECIES; i++)
	{
		int cType = rand() % 3;
		bool dominance;
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
			newCarnivore.setSpecies();
			for(int j = 0; j < NUMCREATURES; j++){
				cCoords temp;
				temp.creature = sUsed;
				temp.species = newCarnivore.getSpecies();
				newCarnivore.index = cUsed;
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
			newOmnivore.setSpecies();
			for(int j = 0; j < NUMCREATURES; j++){
				cCoords temp;
				temp.creature = sUsed;
				temp.species = newOmnivore.getSpecies();
				newOmnivore.index = cUsed;
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
			newHerbivore.setSpecies();
			for(int j = 0; j < NUMCREATURES; j++){
				cCoords temp;
				temp.creature = sUsed;
				temp.species = newHerbivore.getSpecies();
				newHerbivore.index = cUsed;
				sList[sUsed++] = newHerbivore;
				hList[hUsed++] = temp;
			}
			break;
		default:
			cout << "err" << std::endl;
		}
	}
}


void clearDead(Creature * sList,cCoords * cList,cCoords * oList,cCoords * hList){
	int currUsed = 0;
	int numDead = 0;
	for(int i = 0; i < sUsed; i++){
		if(sList[i].getHealth() > 0){
			sList[currUsed] = sList[i];
			if(sList[currUsed].getSpecies().at(0) == 'C'){
				cList[sList[i].index].creature = currUsed;
			}
			else if(sList[currUsed].getSpecies().at(0) == 'H'){
				hList[sList[i].index].creature = currUsed;
			}
			else if(sList[currUsed].getSpecies().at(0) == 'O'){
				oList[sList[i].index].creature = currUsed;
			}
			currUsed++;
		}
		else numDead++;
	}
	sUsed = currUsed;
}
