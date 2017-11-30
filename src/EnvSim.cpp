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

int main()
{
	//Main Variables
	int const NUMSPECIES = 10;
	int const NUMCREATURES = 1;
	int const NUMSEASONS = 1;
	Environment Env = Environment(); //Create environment
	list <Creature> cList;
	map<string, vector<Creature>> species_dict;
	map<string, vector<Creature>> :: iterator it;
	int current = 0;
	//list <Creature> :: iterator it;


	string userSeed;
	int pCount = 0;
	int hCount = 0;
	int oCount = 0;

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
				species_dict[newCarnivore.getSpecies()].push_back(newCarnivore);
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
			species = "O";
			for(int i = 1; i < 5; i++)
				species += (newOmnivore.getTrait(i).getTraitName()).at(0);
			newOmnivore.setSpecies(species);
			for(int j = 0; j < NUMCREATURES; j++){
				species_dict[newOmnivore.getSpecies()].push_back(newOmnivore);
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
			species = "H";
			for(int i = 1; i < 5; i++)
				species += (newHerbivore.getTrait(i).getTraitName()).at(0);
			newHerbivore.setSpecies(species);
			for(int j = 0; j < NUMCREATURES; j++){
				species_dict[newHerbivore.getSpecies()].push_back(newHerbivore);
			}
			hCount++;
			break;
		default:
			cout << "err" << std::endl;
		}
	}

	for(it = species_dict.begin(); it != species_dict.end(); it++)
	{
		string key = it->first;

		vector<Creature> val = it->second;
		vector<Creature> :: iterator vec;

		for(vec = val.begin(); vec != val.end(); vec++)
		{
			Creature val = *vec;
			val.calcStats(Env);
			//cout << val.toString() << endl;
		}
	}
	//cout << "Random Biome: " << random_biome << endl;

	//Set season and biome

	//Get season
	//cout << "Biome: " << Env.get_biome() << endl;

	//Implement change of season
	do
	{
		for(it = species_dict.begin(); it != species_dict.end(); it++)
			{
				string key = it->first;

				vector<Creature> val = it->second;
				vector<Creature> :: iterator vec;

				for(vec = val.begin(); vec != val.end(); vec++)
				{
					Creature val = *vec;
					if (!val.updateHealth(Env))
						cout << val.toString() << endl;
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

	for(it = species_dict.begin(); it != species_dict.end(); it++)
				{
					string key = it->first;

					vector<Creature> val = it->second;
					vector<Creature> :: iterator vec;

					for(vec = val.begin(); vec != val.end(); vec++)
					{
						Creature val = *vec;
						if (val.getHealth() > 0){
							count++;
							cout << val.toString() << endl;
						}
					}
				}

	cout << count << "," << Env.get_water_supply();
}
