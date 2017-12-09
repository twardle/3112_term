/*
 * Creature.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
 */
#include "creature.h"
#include "trait.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <assert.h>
#define NDEBUG
using std::list;
using std::string;

bool const PRINT_DEBUG = false;

/**
 * Default Constructor. Sets default values for Creature class.
 * @param none
 */
Creature::Creature(){
    counted = false;
    index = -1;
    age = 0;
    health = 1.00;
    species = "";
    diseased = false;
    Trait traits[NUMTRAITS];
    base_waterNeed = 1.00;
    base_breedChance = 0.1;
    base_herdTendency = 1.00;
    base_temp_resist = 1.00;
    base_disease_resist = 1.00;
    base_predator_resist = 1.00;
    waterNeed = base_waterNeed;
    breedChance = base_breedChance;
    herdTendency = base_herdTendency;
    temp_resist = base_temp_resist;
    disease_resist = base_disease_resist;
    predator_resist = base_predator_resist;
}

/**
 * Destructor for Creature.
 * @param none
 */
Creature::~Creature(){
    //TODO: create destructor
}

/**
 * Getter. Gets each Trait for a Creature.
 * @param index
 * @return traits[index]
 */
Trait Creature::getTrait(int index){
    return traits[index];
}

/**
 * Setter. Sets Trait at index value for a Creature.
 * @param index
 * @param newTrait
 * @return none
 */
void Creature::setTrait(int index, Trait newTrait){
    traits[index] = newTrait;
}

/**
 * Method. Removes Trait for a Creature.
 * @param index
 * @return none
 */
void Creature::removeTrait(int index){
    Trait temporary;

    traits[index] = temporary;
}

/**
 * Getter. Gets bool value representing whether or not
 * a creature is diseased.
 * @param none
 * @return diseased
 */
bool Creature::getDiseased(){
    return diseased;
}

/**
 * Setter. Sets diseased value to a true/false input value.
 * @param dis
 * @return none
 */
void Creature::setDiseased(bool dis){
    diseased = dis;
}

/**
 * Getter. Returns Creature's age.
 * @param none
 * @return age
 */
float Creature::getAge(){
    return age;
}

/**
 * Setter. Sets Creature's age.
 * @param nAge
 * @return none
 */
void Creature::setAge(float nAge){
    age = nAge;
}

/**
 * Getter. Gets Creature's health.
 * @param none
 * @return health
 */
float Creature::getHealth(){
    assert(health == health);
    return health;
}

/**
 * Setter. Sets Creature's health.
 * @param nHealth
 * @return none
 */
void Creature::setHealth(float nHealth){
    health = nHealth;
}

/**
 * Getter. Gets Creature's Species.
 * @param none
 * @return species
 */
string Creature::getSpecies(){
    return species;
}

/**
 * Method. Updates Creature's health.
 * @param update
 * @return none
 */
void Creature::updateHealth(float update){
    health += update;
}

/**
 * Method. Determines name for a species.
 * @param none
 * @return none
 */
void Creature::setSpecies(){
    if(traits[0].getTraitName().at(0) == 'G')
        species = "H";
    else if(traits[0].getTraitName().at(0) == 'S')
        species = "C";
    else
        species = "O";

    for(int i = 1; i < 5; i++)
        species += (traits[i].getTraitName()).at(0);
}

/**
 * Getter. Returns water need for a Creature.
 * @param none
 * @return waterNeed
 */
float Creature::getWaterNeed(){
    calcWaterNeed();
    return waterNeed;
}

/**
 * Getter. Returns breed chance of a Creature.
 * @param Env
 * @return breedChance
 */
float Creature::getBreedChance(Environment Env){
    calcBreedChance(Env);
    return breedChance;
}

/**
 * Getter. Returns herd tendency of a Creature.
 * @param none
 * @return herdTendency
 */
float Creature::getHerdTendency(){
    calcHerdTendency();
    return herdTendency;
}

/**
 * Getter. Returns temperature resistance of a Creature.
 * @param none
 * @return temp_resist
 */
float Creature::getTempResist(){
    calcTempResist();
    return temp_resist;
}

/**
 * Getter. Returns disease resistance of a Creature.
 * @param none
 * @return disease_resist
 */
float Creature::getDiseaseResist(){
    calcDiseaseResist();
    return disease_resist;
}

/**
 * Getter. Returns predator resistance of a Creature.
 * @param none
 * @return predator_resist
 */
float Creature::getPredatorResist(){
    calcPredatorResist();
    return predator_resist;
}

/**
 * Getter. Returns base water need for a Creature.
 * @param none
 * @return base_waterNeed
 */
float Creature::getBaseWaterNeed(){
    return base_waterNeed;
}

/**
 * Getter. Returns base breed chance for a Creature.
 * @param none
 * @return base_breedChance
 */
float Creature::getBaseBreedChance(){
    return base_breedChance;
}

/**
 * Getter. Returns base herd tendency for a Creature.
 * @param none
 * @return base_herdTendency
 */
float Creature::getBaseHerdTendency(){
    return base_herdTendency;
}

/**
 * Getter. Returns base temperature resistance for a Creature.
 * @param none
 * @return base_temp_resist
 */
float Creature::getBaseTempResist(){
    return base_temp_resist;
}

/**
 * Getter. Returns base disease resistance for a Creature.
 * @param none
 * @return base_disease_resist
 */
float Creature::getBaseDiseaseResist(){
    return base_disease_resist;
}

/**
 * Getter. Returns base predator resistance for a Creature.
 * @param none
 * @return base_predator_resist
 */
float Creature::getBasePredatorResist(){
    return base_predator_resist;
}

/**
 * Setter. Sets water need for a Creature.
 * @param wn
 * @return none
 */
void Creature::setWaterNeed(float wn){
    base_waterNeed = wn;
}

/**
 * Setter. Sets a Creature's breed chance.
 * @param bc
 * @return none
 */
void Creature::setBreedChance(float bc){
    base_breedChance = bc;
}

/**
 * Setter. Sets a Creature's herd tendency.
 * @param ht
 * @return none
 */
void Creature::setHerdTendency(float ht){
    base_herdTendency = ht;
}

/**
 * Setter. Sets a Creature's temperature resistance.
 * @param tr
 * @return none
 */
void Creature::setTempResist(float tr){
    base_temp_resist = tr;
}

/**
 * Setter. Setss a Creature's disease resistance.
 * @param dr
 * @return none
 */
void Creature::setDieaseResist(float dr){
    base_disease_resist = dr;
}

/**
 * Setter. Sets a Creature's predator resistance.
 * @param pr
 * @return none
 */
void Creature::setPredatorResist(float pr){
    base_predator_resist = pr;
}

/**
 * Method. Calculates the water need for a Creature.
 * @param none
 * @return none
 */
void Creature::calcWaterNeed(){
    waterNeed = base_waterNeed;
    float temp = 1.00;
    for(int i = 0; i < NUMTRAITS; i++){
        temp *= traits[i].getWaterNeed();
    }
    waterNeed *= temp;
}

/**
 * Method. Calculates the breed chance for a Creature.
 * @param Env
 * @return none
 */
void Creature::calcBreedChance(Environment Env){
    float temperature = Env.get_temp();
    breedChance = base_breedChance;
    float temp = 1.00;
    for(int i = 0; i < NUMTRAITS; i++){
        temp *= traits[i].getBreedChance();
    }
    if((47.2 * temp_resist) > temperature || (67.2 * temp_resist) < temperature){
            if((47.2 * temp_resist) > temperature){
                float diff = (47.2 * temp_resist) - temperature;
                temp *= (diff * 0.1);
            }
            else{
                float diff = temperature - (67.2 * temp_resist);
                temp *= (diff * 0.1);
            }
        }
    breedChance *= temp;

}

/**
 * Method. Calculates the herd tendency for a Creature.
 * @param none
 * @return none
 */
void Creature::calcHerdTendency(){
    herdTendency = base_herdTendency;
    float temp = 1.00;
    for(int i = 0; i < NUMTRAITS; i++){
        temp *= traits[i].getHerdTendency();
    }
    herdTendency *= temp;
}

/**
 * Method. Calculates the temperature resistance of a Creature.
 * @param none
 * @return none
 */
void Creature::calcTempResist(){
    temp_resist = base_temp_resist;
    float temp = 1.00;
    for(int i = 0; i < NUMTRAITS; i++){
        temp *= traits[i].getTempResist();
    }
    temp_resist *= temp;
}

/**
 * Method. Calculates the disease resistance for a Creature.
 * @param none
 * @return none
 */
void Creature::calcDiseaseResist(){
    disease_resist = base_disease_resist;
    float temp = 1.00;
    for(int i = 0; i < NUMTRAITS; i++){
        temp *= traits[i].getDiseaseResist();
    }
    disease_resist *= temp;
}

/**
 * Method. Calculates the predator resistance for a Creature.
 * @param none
 * @return none
 */
void Creature::calcPredatorResist(){
    predator_resist = base_predator_resist;
    float temp = 1.00;
    for(int i = 0; i < NUMTRAITS; i++){
        temp *= traits[i].getPredatorResist();
    }
    predator_resist *= temp;
}

/**
 * Method. Calculates the statistics for a Creature.
 * @param Env
 * @return none
 */
void Creature::calcStats(Environment Env){
    calcWaterNeed();
    calcBreedChance(Env);
    calcHerdTendency();
    calcTempResist();
    calcDiseaseResist();
    calcPredatorResist();
}

/**
 * Method. Updates a Creature's health
 * @param Env
 * @return boolean
 */
bool Creature::updateHealth(Environment& Env){
    Weather currSeason = Env.get_season();

    if(diseased){
        float diff = .25 * disease_resist;
        health -= diff;
    }
    if(health < 0){
        //std::cout << "died at disease" << std::endl;
        return false;
    }

    float temp = currSeason.getTemp();

    if((47.2 * temp_resist) > temp || (67.2 * temp_resist) < temp){
        if((47.2 * temp_resist) > temp){
            float diff = (47.2 * temp_resist) - temp;
            diff *= 0.01;
            health -= diff;
        }
        else{
            float diff = temp - (67.2 * temp_resist);
            diff *= 0.0025;
            health -= diff;
        }

    }

    if(health < 0){
            //std::cout << "died at temp" << std::endl;
            return false;
        }

    float water = Env.get_water_supply();

    if(water < waterNeed){
        float diff = waterNeed - water;
        diff *= .65;
        health -= diff;
    }
    else
        Env.set_water_supply(water - waterNeed);

    if(health < 0){
            //std::cout << "died at water" << std::endl;
            return false;
        }

    return true;
}

/**
 * Method. Allows a Creature to breed.
 * @param other
 * @param breed
 * @return baby
 */
Creature Creature::breed(Creature other, int breed){
    Creature baby;

    //set offspring waterNeed
    if(breed % 2 == 0)
        baby.setWaterNeed(base_waterNeed);
    else
        baby.setWaterNeed(other.getBaseWaterNeed());

    //set offspring breed chance
    if(breed % 3 == 0)
        baby.setBreedChance(base_breedChance);
    else if(breed % 3 == 2)
        baby.setBreedChance(other.getBaseBreedChance());
    else
        baby.setBreedChance((base_breedChance + other.getBaseBreedChance())/2);

    //set offspring herd tendency
    if(breed % 5 < 2)
        baby.setHerdTendency(base_herdTendency);
    else if(breed % 5 > 2)
        baby.setHerdTendency(other.getBaseHerdTendency());
    else
        baby.setHerdTendency((base_herdTendency + other.getBaseHerdTendency())/2);

    //set offspring temp resist
    if(breed % 7 < 3)
        baby.setTempResist(base_temp_resist);
    else if(breed % 7 > 3)
        baby.setTempResist(other.getBaseTempResist());
    else
        baby.setTempResist((base_temp_resist + other.getBaseTempResist())/2);

    //set offspring disease resist
    if(breed % 11 < 5)
        baby.setDieaseResist(base_disease_resist);
    else if(breed % 11 > 5)
        baby.setDieaseResist(other.getBaseDiseaseResist());
    else
        baby.setDieaseResist((base_disease_resist + other.getBaseDiseaseResist())/2);

    //set offspring predator resist
    if(breed % 13 < 6)
        baby.setPredatorResist(base_predator_resist);
    else if(breed % 13 > 6)
        baby.setPredatorResist(other.getBasePredatorResist());
    else
        baby.setPredatorResist((base_predator_resist + other.getBasePredatorResist())/2);


    bool mutate = false;
    bool mTrait = rand() % 4 + 1;

    if(breed % 500 == 0){
        if(PRINT_DEBUG)
            std::cout << "mutated" << std::endl;
        mutate = true;
    }

    //set offspring traits
    for(int i = 0; i < NUMTRAITS; i++){
        if(traits[i].getType() == -1)
            baby.traits[i] = other.traits[i];
        else if(other.traits[i].getType() == -1)
            other.traits[i] = baby.traits[i];
        else if((traits[i] >= other.traits[i] && !mutate) || mTrait != i)
            baby.traits[i] = traits[i];
        else if((traits[i] >= other.traits[i] && mutate) || mTrait != i)
            traits[i] = baby.traits[i];
        else if (!mutate || mTrait != i)
            baby.traits[i] = other.traits[i];
        else
            other.traits[i] = baby.traits[i];
    }

    return baby;

}

/**
 * Method. ToString for Creature class.
 * @param none
 * @return cString
 */
string Creature::toString(){
    std::stringstream ss;
    string cString;

    ss << "\nSPECIES:\t" << species;
    ss << "\nAGE:\t\t" << age;
    ss << "\nHEALTH:\t\t" << health;
    ss << "\nDISEASED:\t" << diseased;

    for(int i = 0; i < NUMTRAITS; i++){
        ss << "\nTRAIT '" << i+1 << "':\t" << traits[i].toString();
    }

    ss << "\nWATER NEED:\t" << waterNeed;
    ss << "\nBREED CHANCE:\t" << breedChance;
    ss << "\nHERD TENDENCY:\t" << herdTendency;
    ss << "\nTEMP RESIST:\t" << temp_resist;
    ss << "\nDISEASE RESIST:\t" << disease_resist;
    ss << "\nPRED RESIST:\t" << predator_resist;
    cString = ss.str();
    return cString;
}
