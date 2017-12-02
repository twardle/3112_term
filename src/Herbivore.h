/*
 * Herbivore.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
*/

#ifndef HERBIVORE_H_
#define HERBIVORE_H_

#include "Creature.h"

class Herbivore : public Creature {
private:
	bool herding = false;
public:
	Herbivore(){

	}
	void herd(){
		if(herdTendency > .5)
			herding = true;
	};

	bool getHerding(){
		return herding;
	};
};

#endif /* HERBIVORE_H_ */
