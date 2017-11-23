//============================================================================
// Name        : EnvSim.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>

#include "Environment.h"
#include "Creature.h"

using namespace std;

int main(){
	Environment Env;
	list <Creature> cList;
	list <Creature> :: iterator it;
	string userSeed;
	cout << "INPUT SEED:\t";
	std::cin >> userSeed;
	std::stringstream ss ( userSeed);
	int seed;
	ss >> seed;
	srand( seed );

	Env.readTraits();

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

}
