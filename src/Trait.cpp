/*
 * Trait.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Tyler
 */

#include "Trait.h"

Trait::Trait() {
	// TODO Auto-generated constructor stub

}

Trait::~Trait() {
	// TODO Auto-generated destructor stub
}

bool Trait::operator==(const Trait& other) const {
	if(trait_name == other.trait_name)
		return true;
	return false;
}
