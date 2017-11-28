//============================================================================
// Name        : EnvSim.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <ctime>

#include "Environment.h"
#include "Creature.h"
#include "Trait.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Omnivore.h"

using namespace std;



int main()
{
	//Main Variables
	int const NUMSPECIES = 10;
	int const NUMCREATURES = 1;
	Environment Env = Environment(); //Create environment
	list <Creature> cList;
	list <Creature> :: iterator it;
	string userSeed;
	int pCount = 0;
	int hCount = 0;
	int oCount = 0;


	//Get user input for program seed
	cout << "INPUT SEED:\t";
	std::cin >> userSeed;
	std::stringstream ss ( userSeed);
	std::stringstream species;
	int seed;
	ss >> seed;
	srand( seed );

	Env.readTraits(); //Get traits

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
							if(Env.traitList[i][j].getDominance() == dominance)
								newCarnivore.setTrait(i,Env.traitList[i][j]);
				}
			}
			newCarnivore.setSpecies("Carnivore");
			for(int j = 0; j < NUMCREATURES; j++){
				cList.push_back(newCarnivore);
			}
			pCount++;
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
			newOmnivore.setSpecies("Omnivore");
			for(int j = 0; j < NUMCREATURES; j++){
				cList.push_back(newOmnivore);
			}
			oCount++;
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
			newHerbivore.setSpecies("Herbivore");
			for(int j = 0; j < NUMCREATURES; j++){
				cList.push_back(newHerbivore);
			}
			hCount++;
			break;
		default:
			cout << "err" << std::endl;
		}
	}

	for(it = cList.begin(); it != cList.end(); it++){
		Creature val = *it;
		cout << val.toString() << std::endl;
	}

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 6; j++)
			//cout << Env.traitList[i][j].getAnimalType() << std::endl;

	//Randomly generate season and biome
	//New srand seed
	srand((unsigned)time(0));

	int random_biome = (rand() % 5);
	//cout << "Random Biome: " << random_biome << endl;

	//Set season and biome
	Env = Environment(random_biome);

	//Get season
	//cout << "Biome: " << Env.get_biome() << endl;

	int val = 100;
	int current = 0;
	//Implement change of season
	do
	{
		//TODO Update creature health
		//TODO Update values

		//Get new season
		//cout << "Season: " << Env.get_season() << endl;
		//cout << "Temp: " << Env.get_temp() << endl;

		//Change the season
		Env.changeseason();

		//cout << "New Season...\n" << endl;

		//Increment current
		current++;
	}while(current < val);

}
