/*
 * Creature.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
 */

#include "Creature.h"
#include "Trait.h"
#include <string>

using std::list;
using std::string;

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
	list<Trait> traits;
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
}

list<Trait> Creature::getTraits(){
	return traits;
}
void Creature::addTrait(Trait newTrait){
	traits.push_back(newTrait);
}
bool Creature::removeTrait(Trait removeTrait){
	std::list<Trait>::iterator remove = std::find(traits.begin(), traits.end(), removeTrait);

	if(*remove == removeTrait){
		traits.remove(removeTrait);
		return true;
	}
	return false;
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
	float temp = 1.00;
	for (std::list<Trait>::iterator it=traits.begin(); it != traits.end(); ++it){
		temp *= it->getBreedChance();
	}
	setWaterNeed(temp);
}
void Creature::calcBreedChance(){
	float temp = 1.00;
	for (std::list<Trait>::iterator it=traits.begin(); it != traits.end(); ++it){
		temp *= it->getBreedChance();
	}
	setBreedChance(temp);
}
void Creature::calcHerdTendency(){
	float temp = 1.00;
	for (std::list<Trait>::iterator it=traits.begin(); it != traits.end(); ++it){
		temp *= it->getHerdTendency();
	}
	setHerdTendency(temp);
}
void Creature::calcTempResist(){
	float temp = 1.00;
	for (std::list<Trait>::iterator it=traits.begin(); it != traits.end(); ++it){
		temp *= it->getTempResist();
	}
	setTempResist(temp);
}
void Creature::calcDiseaseResist(){
	float temp = 1.00;
	for (std::list<Trait>::iterator it=traits.begin(); it != traits.end(); ++it){
		temp *= it->getDiseaseResist();
	}
	setDieaseResist(temp);
}
void Creature::calcPredatorResist(){
	float temp = 1.00;
	for (std::list<Trait>::iterator it=traits.begin(); it != traits.end(); ++it){
		temp *= it->getPredatorResist();
	}
	setPredatorResist(temp);
}
void Creature::calcStats(){
	calcWaterNeed();
	calcBreedChance();
	calcHerdTendency();
	calcTempResist();
	calcDiseaseResist();
	calcPredatorResist();
}

void Creature::breed(Creature other){

}

string Creature::mutate(){
	return "mutated";
}

