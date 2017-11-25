/*
 * Carnivore.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler


#ifndef CARNIVORE_H_
#define CARNIVORE_H_

#include "Creature.cpp"

class Carnivore : public Creature {
public:
	Carnivore();
	virtual ~Carnivore();
	bool hunt(int);
};

#endif /* CARNIVORE_H_ */
