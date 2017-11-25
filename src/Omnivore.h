/*
 * Omnivore.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
*/

#ifndef OMNIVORE_H_
#define OMNIVORE_H_

#include "Creature.h"
#include "Herbivore.h"

class Omnivore : public Creature {
private:
	bool herding = false;
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

	void herd(){
			if(herdTendency > .5)
				herding = true;
		};

		bool getHerding(){
			return herding;
		};
};

#endif /* OMNIVORE_H_ */
