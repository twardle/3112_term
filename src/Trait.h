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
private:
	string trait_name;
	float temp_resist, disease_resist, predator_resist;
	float breedChance, herdTendency, waterNeed;
	bool dominance;
	int type;

	Trait();
	Trait(string,float,float,float,float,float,float);
	virtual ~Trait();
public:
	float getTempResist();
	float getDiseaseResist();
	float getPredatorResist();
	float getBreedChance();
	float getHerdTendency();
	float getWaterNeed();
	string getTraitName();

	void setTempResist(float);
	void setDiseaseResist(float);
	void setPredatorResist(float);
	void setBreedChance(float);
	void setHerdTendency(float);
	void setWaterNeed(float);

	bool operator >=(const Trait&) const;
	bool operator==(const Trait&) const;
};

#endif /* TRAIT_H_ */
