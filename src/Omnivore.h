/*
 * Omnivore.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler


#ifndef OMNIVORE_H_
#define OMNIVORE_H_

#include "Creature.cpp"

class Omnivore : public Creature {
public:
	Omnivore();
	virtual ~Omnivore();
	bool hunt(int);
};

#endif /* OMNIVORE_H_ */
