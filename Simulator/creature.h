/*
 * Creature.h
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
 */
#include <string>
#include <list>

#include "environment.h"
#include "trait.h"
#include "weather.h"

using std::list;
using std::string;

#ifndef CREATURE_H_
#define CREATURE_H_
const int NUMTRAITS = 5;

class Creature {
protected:
    float waterNeed, breedChance, herdTendency;
    float temp_resist, disease_resist, predator_resist;
private:
    bool counted;
    string species;
    float age;
    bool diseased;
    float health;
    Trait traits[NUMTRAITS];

    float base_waterNeed, base_breedChance, base_herdTendency;
    float base_temp_resist, base_disease_resist, base_predator_resist;

    float getBaseWaterNeed();
    float getBaseBreedChance();
    float getBaseHerdTendency();
    float getBaseTempResist();
    float getBaseDiseaseResist();
    float getBasePredatorResist();

    void calcWaterNeed();
    void calcBreedChance(Environment);
    void calcHerdTendency();
    void calcTempResist();
    void calcDiseaseResist();
    void calcPredatorResist();
public:
    int index;

    Creature();
    virtual ~Creature();
    Trait getTrait(int);
    void setTrait(int, Trait);
    void removeTrait(int);

    float getAge();
    void setAge(float);
    float getHealth();
    void setHealth(float);
    string getSpecies();
    void updateHealth(float);
    void setSpecies();
    bool getDiseased();
    void setDiseased(bool);

    float getWaterNeed();
    float getBreedChance(Environment Env);
    float getHerdTendency();
    float getTempResist();
    float getDiseaseResist();
    float getPredatorResist();

    void setWaterNeed(float);
    void setBreedChance(float);
    void setHerdTendency(float);
    void setTempResist(float);
    void setDieaseResist(float);
    void setPredatorResist(float);

    bool updateHealth(Environment&);
    void calcStats(Environment);

    Creature breed(Creature, int);

    string toString();

};

#endif /* CREATURE_H_ */
