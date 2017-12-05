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
	Carnivore(){}
	Carnivore(Creature & creature){}
	bool hunt(Creature & prey){
		float currHealth = prey.getHealth();
		if(prey.getPredatorResist() > 1)
			prey.updateHealth(prey.getPredatorResist() - 2);
		else
			prey.setHealth(0);

		if(currHealth < prey.getHealth())
			prey.setHealth(currHealth);

		if(prey.getHealth() <= 0)
			return true;
		else
			return false;
	};

	bool hunt(Herbivore prey){
		float currHealth = prey.getHealth();
		if(prey.getHerding()){
			if(prey.getPredatorResist() + 0.5 > 1)
				prey.updateHealth(prey.getPredatorResist() - 1.5);
			else
				prey.setHealth(0);

			if(currHealth < prey.getHealth())
				prey.setHealth(currHealth);

			if(prey.getHealth() <= 0)
				return true;
			else
				return false;
		}
		else if(prey.getPredatorResist() > 1)
			prey.updateHealth(prey.getPredatorResist() - 2);
		else
			prey.setHealth(0);

		if(currHealth < prey.getHealth())
			prey.setHealth(currHealth);

		if(prey.getHealth() <= 0)
			return true;
		else
			return false;

		return false;
	};

	bool hunt(Omnivore prey){
		float currHealth = prey.getHealth();
		if(prey.getHerding()){
			if(prey.getPredatorResist() + 0.5 > 1)
				prey.updateHealth(prey.getPredatorResist() - 1.5);
			else
				prey.setHealth(0);

			if(currHealth < prey.getHealth())
				prey.setHealth(currHealth);

			if(prey.getHealth() <= 0)
				return true;
			else
				return false;
		}
		else if(prey.getPredatorResist() > 1)
			prey.updateHealth(prey.getPredatorResist() - 2);
		else
			prey.setHealth(0);

		if(currHealth < prey.getHealth())
			prey.setHealth(currHealth);

		if(prey.getHealth() <= 0)
			return true;
		else
			return false;

		return false;
	};
};

#endif /* CARNIVORE_H_ */
