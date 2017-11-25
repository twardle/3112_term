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

	for(int i = 0; i < 10; i++){
		int cType = rand() % 3;
		for(int j = 0; j < 10; j++){
			switch (cType){
			case 0:
				//TODO: Predator
				break;
			case 1:
				//TODO: Omnivore
				break;
			case 2:
				//TODO: Herbivore
				break;
			default:
				cout << "err" << std::endl;
			}
		}
	}

	for(it = cList.begin(); it != cList.end(); it++){
		Creature val = *it;
		cout << val.getSpecies() << std::endl;
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
		cout << "Season: " << Env.get_season() << endl;
		cout << "Temp: " << Env.get_temp() << endl;

		//Change the season
		Env.changeseason();

		cout << "New Season...\n" << endl;

		//Increment current
		current++;
	}while(current < val);

}
