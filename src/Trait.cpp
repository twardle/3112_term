/*
 * Trait.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: Tyler
 */

#include "Trait.h"

Trait::Trait() {
	trait_name = "empty";
	temp_resist = 1.00;
	disease_resist = 1.00;
	predator_resist = 1.00;
	breedChance = 1.00;
	herdTendency = 1.00;
	waterNeed = 1.00;
}

Trait::~Trait() {
	// TODO Auto-generated destructor stub
}

float getTempResist(){
	return temp_resist;
}
float getDiseaseResist(){
	return disease_resist;
}
float getPredatorResist(){
	return predator_resist;
}
float getBreedChance(){
	return breedChance;
}
float getHerdTendency(){
	return herdTendency;
}
float getWaterNeed(){
	return waterNeed;
}
string getTraitName(){
	return trait_name;
}

void setTempResist(float tr){
	temp_resist = tr;
}
void setDiseaseResist(float dr){
	disease_resist = dr;
}

void setPredatorResist(float pr){
	predator_resist = pr;
}

void setBreedChance(float bc){
	breedChance = bc;
}

void setHerdTendency(float ht){
	herdTendency = ht;
}

void setWaterNeed(float wn){
	waterNeed = wn;
}

bool Trait::operator >=(const Trait& other) const {
	if(trait_name == other.trait_name)
		return true;
	else if(type == other.type && dominance)
		return true;
	else
		return false;
}

bool Trait::operator==(const Trait& other) const {
	if(trait_name == other.trait_name)
		return true;
	return false;
}
