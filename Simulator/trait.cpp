/*
 * Trait.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Tyler
 */

#include "trait.h"
#include <sstream>

/**
 * Default Constructor.
 * @param none
 */
Trait::Trait() {
    trait_name = "empty";
    temp_resist = 1.00;
    disease_resist = 1.00;
    predator_resist = 1.00;
    breedChance = 1.00;
    herdTendency = 1.00;
    waterNeed = 1.00;
    dominance = false;
    type = -1;
    animalType = -1;
}

/**
 * Destructor.
 * @param none
 */
Trait::~Trait() {
    // TODO Auto-generated destructor stub
}

/**
 * Getter. Returns temperature resistance.
 * @param none
 * @return temp_resist
 */
float Trait::getTempResist(){
    return temp_resist;
}

/**
 * Getter. Returns disease resistance.
 * @param none
 * @return disease_resist
 */
float Trait::getDiseaseResist(){
    return disease_resist;
}

/**
 * Getter. Returns predator resistance.
 * @param none
 * @return predator_resist
 */
float Trait::getPredatorResist(){
    return predator_resist;
}

/**
 * Getter. Returns breed chance.
 * @param none
 * @return breedChance
 */
float Trait::getBreedChance(){
    return breedChance;
}

/**
 * Getter. Returns herd tendency.
 * @param none
 * @return herdTendency
 */
float Trait::getHerdTendency(){
    return herdTendency;
}

/**
 * Getter. Returns need for water.
 * @param none
 * @return waterNeed
 */
float Trait::getWaterNeed(){
    return waterNeed;
}

/**
 * Getter. Returns name for trait.
 * @param none
 * @return trait_name
 */
string Trait::getTraitName(){
    return trait_name;
}

/**
 * Getter. Returns type of trait.
 * @param none
 * @return type
 */
int Trait::getType(){
    return type;
}

/**
 * Getter. Returns dominance of trait.
 * @param none
 * @return dominance
 */
bool Trait::getDominance(){
    return dominance;
}

/**
 * Getter. Returns type of creature.
 * @param none
 * @return animalType
 */
int Trait::getAnimalType(){
    return animalType;
}

/**
 * Setter. Sets trait name.
 * @param name
 * @return none
 */
void Trait::setTraitName(string name){
    trait_name = name;
}

/**
 * Setter. Sets dominance of a trait.
 * @param dom
 * @return none
 */
void Trait::setDominance(bool dom){
    dominance = dom;
}

/**
 * Setter. Sets the type of animal.
 * @param type
 * @return none
 */
void Trait::setAnimalType(int type){
    animalType = type;
}

/**
 * Setter. Sets temperature resistance based on trait.
 * @param tr
 * @return none
 */
void Trait::setTempResist(float tr){
    temp_resist = tr;
}

/**
 * Setter. Sets disease resistance based on trait.
 * @param dr
 * @return none
 */
void Trait::setDiseaseResist(float dr){
    disease_resist = dr;
}

/**
 * Setter. Sets predator resistance based on trait.
 * @param pr
 * @return none
 */
void Trait::setPredatorResist(float pr){
    predator_resist = pr;
}

/**
 * Setter. Sets breed chance based on trait.
 * @param bc
 * @return none
 */
void Trait::setBreedChance(float bc){
    breedChance = bc;
}

/**
 * Setter. Sets herd tendency based on trait.
 * @param ht
 * @return none
 */
void Trait::setHerdTendency(float ht){
    herdTendency = ht;
}

/**
 * Setter. Sets water need based on trait.
 * @param wn
 * @return none
 */
void Trait::setWaterNeed(float wn){
    waterNeed = wn;
}

/**
 * Setter. Sets type.
 * @param i
 * @return none
 */
void Trait::setType(int i){
    type = i;
}

/**
 * Method. Returns string for trait.
 * @param none
 * @return output
 */
string Trait::toString(){
    std::stringstream ss;

    ss << "\n\tTRAIT NAME:\t" << trait_name;
    ss << "\n\tLOCATION:\t" << type;
    ss << "\n\tDOMINANCE:\t" << dominance;
    //ss << "\nWATER NEED:\t" << waterNeed;
    //ss << "\nHERD TENDENCY:\t" << herdTendency;
    //ss << "\nBREED CHANCE:\t" << breedChance;
    //ss << "\nTEMP RESIST:\t" << temp_resist;
    //ss << "\nDISEASE RESIST:\t" << disease_resist;
    //ss << "\nPRED RESIST:\t" << predator_resist;

    string output = ss.str();
    return output;
}

/**
 * Method. Checks if a trait is greater than or equivalent to another.
 * @param other
 * @return boolean
 */
bool Trait::operator >=(const Trait& other) const {
    if(trait_name == other.trait_name)
        return true;
    else if(type == other.type && dominance)
        return true;
    else
        return false;
}

/**
 * Method. Checks to see if two traits are equivalent.
 * @param other
 * @return boolean
 */
bool Trait::operator==(const Trait& other) const {
    if(trait_name == other.trait_name)
        return true;
    return false;
}

/**
 * Method. Sets a trait to another.
 * @param other
 * @return none
 */
void Trait::operator =(const Trait& other){
    temp_resist = other.temp_resist;
    disease_resist = other.disease_resist;
    predator_resist = other.predator_resist;
    breedChance = other.breedChance;
    herdTendency = other.herdTendency;
    waterNeed = other.waterNeed;
    trait_name = other.trait_name;
    dominance = other.dominance;
    type =  other.type;
    animalType = other.animalType;

    return;
}
