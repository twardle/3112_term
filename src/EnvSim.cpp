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
	Environment Env = Environment(); //Create environment
	list <Creature> cList;
	list <Creature> :: iterator it;
	string userSeed;

	//Get user input for program seed
	cout << "INPUT SEED:\t";
	std::cin >> userSeed;
	std::stringstream ss ( userSeed);
	int seed;
	ss >> seed;
	srand( seed );

	Env.readTraits(); //Get traits

	for(int i = 0; i < 10; i++)
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
					if(Env.traitList[i][j].getAnimalType() == 2 && Env.traitList[i][j].getDominance() == dominance)
						newCarnivore.setTrait(i,Env.traitList[i][j]);
				}
			}

			for(int j = 0; j < 10; j++){
				cList.push_back(newCarnivore);
			}
			break;
		case 1:
			newOmnivore.setTrait(0,Env.traitList[0][1]);
			for(int i = 1; i < 5 ; i++){
				for(int j = 0; j < 6; j++){
					dominance = rand() % 2;
					if(Env.traitList[i][j].getAnimalType() == 1 && Env.traitList[i][j].getDominance() == dominance)
						newOmnivore.setTrait(i,Env.traitList[i][j]);
				}
			}

			for(int j = 0; j < 10; j++){
				cList.push_back(newOmnivore);
			}
			break;
		case 2:
			newHerbivore.setTrait(0,Env.traitList[0][0]);
			for(int i = 1; i < 5 ; i++){
				for(int j = 0; j < 6; j++){
					dominance = rand() % 2;
					if(Env.traitList[i][j].getAnimalType() == 0 && Env.traitList[i][j].getDominance() == dominance)
						newHerbivore.setTrait(i,Env.traitList[i][j]);
				}
			}

			for(int j = 0; j < 10; j++){
				cList.push_back(newHerbivore);
			}
			break;
		default:
			cout << "err" << std::endl;
		}
	}

	for(it = cList.begin(); it != cList.end(); it++){
		Creature val = *it;
		cout << val.toString() << std::endl;
	}

	//Randomly generate season and biome
	//New srand seed
	srand((unsigned)time(0));

	int random_biome = (rand() % 5);
	cout << "Random Biome: " << random_biome << endl;

	//Set season and biome
	Env = Environment(random_biome);

	//Get season
	cout << "Biome: " << Env.get_biome() << endl;

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
