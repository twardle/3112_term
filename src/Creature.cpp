/*
 * Creature.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
 */

#include "Creature.h"
#include <string>

/*
 * Creature Factors
 * |-Food
 * | |-Carnivore/Herbivore/Omnivore ( type of creature )
 * | |-Prey ( What this creature eats, lower prey pop means less food )
 * | |-Necessary Water Intake ( less means health decreases, more is irrelevant )
 * |-Internal Characteristics
 * | |-Age ( 0-x infant, x-y middle-aged, y-z elder )
 * | |-Health ( 0-100% lower means less likely to survive, disease lowers this faster and constantly )
 * | |-Species ( species of this creature, only able to breed with same species or relative species )
 * | |-Relative Species ( species with similar but mutated traits, encourages mutations and stores distance to original)
 * | |-Herding Tendencies ( bonus for herbivore, penalty for carnivore )
 * | |-Breeding Chance ( encourages predators, discourages herbivores )
 */


Creature::Creature(){
	age = 0;
	health = 100.00;
	species = "";
	tree<string> speciesTree;
	traits = new Trait[1];
	numTraits = 1;
	base_waterNeed = 0.00;
	base_breedChance = 0.00;
	base_herdTendency = 0.00;
	base_temp_resist = 0.00;
	base_disease_resist = 0.00;
	base_predator_resist = 0.00;
	waterNeed = base_waterNeed;
	breedChance = base_breedChance;
	herdTendency = base_herdTendency;
	temp_resist = base_temp_resist;
	disease_resist = base_disease_resist;
	predator_resist = base_predator_resist;
}

Creature::~Creature(){
	delete [] traits;
}
int Creature::getTraits(Trait temp[]){
	for(int i = 0; i < numTraits; i++){
		temp[i] = traits[i];
	}
	return numTraits;
}
void Creature::addTrait(Trait newTrait){
	Trait * newSet = new Trait [numTraits+1];

	for(int i = 0; i < numTraits; i++){
		newSet[i] = traits[i];
	}

	numTraits++;
	delete [] traits;

	traits = new Trait [numTraits];

	for(int i = 0; i < numTraits; i++){
		traits[i] = newSet[i];
	}
	traits[numTraits-1] = newTrait;
	delete [] newSet;
}
void Creature::removeTrait(int index){
	for(int i = index; i < numTraits-1; i++){
		traits[i] = traits [i+1];
	}

	Trait * newSet = new Trait [numTraits-1];
	for(int i = 0; i < numTraits-1; i++){
		newSet[i] = traits[i];
	}

	numTraits--;
	delete [] traits;

	for(int i = 0; i < numTraits; i++){
		traits[i] = newSet[i];
	}

	delete [] newSet;
}

int Creature::getAge(){
	return age;
}
float Creature::getHealth(){
	return health;
}
string Creature::getSpecies(){
	return species;
}
tree<string> Creature::getSpeciesTree(){
	return speciesTree;
}

float Creature::getWaterNeed(){
	return waterNeed;
}
float Creature::getBreedChance(){
	return breedChance;
}
float Creature::getHerdTendency(){
	return herdTendency;
}
float Creature::getTempResist(){
	return temp_resist;
}
float Creature::getDiseaseResist(){
	return disease_resist;
}
float Creature::getPredatorResist(){
	return predator_resist;
}

void Creature::setWaterNeed(float wn){
	base_waterNeed = wn;
}
void Creature::setBreedChance(float bc){
	base_breedChance = bc;
}
void Creature::setHerdTendency(float ht){
	base_herdTendency = ht;
}
void Creature::setTempResist(float tr){
	base_temp_resist = tr;
}
void Creature::setDieaseResist(float dr){
	base_disease_resist = dr;
}
void Creature::setPredatorResist(float pr){
	base_predator_resist = pr;
}

void Creature::calcWaterNeed(){

}
void Creature::calcBreedChance(){

}
void Creature::calcHerdTendency(){

}
void Creature::calcTempResist(){

}
void Creature::calcDiseaseResist(){

}
void Creature::calcPredatorResist(){

}
void Creature::calcStats(){

}

void Creature::breed(Creature other){

}
string Creature::mutate(){
	return "mutated";
}

