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
	dominance = false;
	type = -1;
	animalType = -1;
}

Trait::~Trait() {
	// TODO Auto-generated destructor stub
}

float Trait::getTempResist(){
	return temp_resist;
}
float Trait::getDiseaseResist(){
	return disease_resist;
}
float Trait::getPredatorResist(){
	return predator_resist;
}
float Trait::getBreedChance(){
	return breedChance;
}
float Trait::getHerdTendency(){
	return herdTendency;
}
float Trait::getWaterNeed(){
	return waterNeed;
}
string Trait::getTraitName(){
	return trait_name;
}
int Trait::getType(){
	return type;
}
bool Trait::getDominance(){
	return dominance;
}
int Trait::getAnimalType(){
	return animalType;
}

void Trait::setTraitName(string name){
	trait_name = name;
}
void Trait::setDominance(bool dom){
	dominance = dom;
}
void Trait::setAnimalType(int type){
	animalType = type;
}
void Trait::setTempResist(float tr){
	temp_resist = tr;
}
void Trait::setDiseaseResist(float dr){
	disease_resist = dr;
}

void Trait::setPredatorResist(float pr){
	predator_resist = pr;
}

void Trait::setBreedChance(float bc){
	breedChance = bc;
}

void Trait::setHerdTendency(float ht){
	herdTendency = ht;
}

void Trait::setWaterNeed(float wn){
	waterNeed = wn;
}

void Trait::setType(int i){
	type = i;
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
