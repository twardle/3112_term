/*
 * Creature.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
 */
#include <string>
#include <list>
#include "Trait.h"
#include "tree.hh"

using std::list;
using std::string;

#ifndef CREATURE_H_
#define CREATURE_H_
const int NUMTRAITS = 5;

class Creature {
private:
	string species;
	tree<string> speciesTree;
	int age;
	float health;
	Trait traits[NUMTRAITS];
	int numTraits;
	float waterNeed, breedChance, herdTendency;
	float base_waterNeed, base_breedChance, base_herdTendency;
	float temp_resist, disease_resist, predator_resist;
	float base_temp_resist, base_disease_resist, base_predator_resist;
public:
	Creature();
	virtual ~Creature();
	Trait getTrait(int);
	void setTrait(int, Trait);
	void removeTrait(int);

	int getAge();
	float getHealth();
	string getSpecies();
	tree<string> getSpeciesTree();

	float getWaterNeed();
	float getBreedChance();
	float getHerdTendency();
	float getTempResist();
	float getDiseaseResist();
	float getPredatorResist();

	float getBaseWaterNeed();
	float getBaseBreedChance();
	float getBaseHerdTendency();
	float getBaseTempResist();
	float getBaseDiseaseResist();
	float getBasePredatorResist();

	void setWaterNeed(float);
	void setBreedChance(float);
	void setHerdTendency(float);
	void setTempResist(float);
	void setDieaseResist(float);
	void setPredatorResist(float);

	void calcWaterNeed();
	void calcBreedChance();
	void calcHerdTendency();
	void calcTempResist();
	void calcDiseaseResist();
	void calcPredatorResist();
	void calcStats();

	Creature breed(Creature);
	string mutate();

};

#endif /* CREATURE_H_ */
