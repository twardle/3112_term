/*
 * Trait.h
 *
 *  Created on: Nov 13, 2017
 *      Author: Tyler
 */

#include <string>

using std::string;

#ifndef TRAIT_H_
#define TRAIT_H_

class Trait {
public:
	string trait_name;
	float temp_resist, disease_resist, predator_resist;
	float breedChance, herdTendency, waterNeed;

	Trait();
	Trait(string,float,float,float,float,float,float);
	virtual ~Trait();

	void setTempResist(float);
	void setDiseaseResist(float);
	void setPredatorResist(float);
	void setBreedChance(float);
	void setHerdTendency(float);
	void setWaterNeed(float);

	bool operator==(const Trait&) const;
};

#endif /* TRAIT_H_ */
