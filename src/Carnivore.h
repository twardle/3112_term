/*
 * Carnivore.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
*/

#ifndef CARNIVORE_H_
#define CARNIVORE_H_

#include "Creature.h"
#include "Herbivore.h"
#include "Omnivore.h"

class Carnivore : public Creature {
public:
	bool hunt(Creature prey){
		if(prey.getHealth() - (1 - prey.getPredatorResist()) < 0)
			return true;
		else
			return false;
	};

	bool hunt(Herbivore prey){
		if(prey.getHerding()){
			if(prey.getHealth() - (1 - prey.getPredatorResist() + 0.5) < 0)
				return true;
			else
				return false;
		}
		else if(prey.getHealth() - (1 - prey.getPredatorResist()) < 0)
			return true;
		else
			return false;

		return false;
	};

	bool hunt(Omnivore prey){
		if(prey.getHerding()){
			if(prey.getHealth() - (1 - prey.getPredatorResist() + 0.5) < 0)
				return true;
			else
				return false;
		}
		else if(prey.getHealth() - (1 - prey.getPredatorResist()) < 0)
			return true;
		else
			return false;

		return false;
	};
};

#endif /* CARNIVORE_H_ */
