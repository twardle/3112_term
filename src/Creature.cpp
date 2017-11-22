/*
 * Creature.cpp
 *
 *  Created on: Nov 6, 2017
 *      Author: Tyler
 */

#include "Creature.h"
#include "Trait.h"
#include <string>
#include <cstdlib>

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
	infant = false;
	health = 1.00;
	species = "";
	diseased = false;
	tree<string> speciesTree;
	Trait traits[NUMTRAITS];
	numTraits = 1;
	base_waterNeed = 1.00;
	base_breedChance = 0.3;
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

Creature::~Creature(){
	//TODO: create destructor
}

Trait Creature::getTrait(int index){
	return traits[index];
}
void Creature::setTrait(int index, Trait newTrait){
	traits[index] = newTrait;
}
void Creature::removeTrait(int index){
	Trait temporary;

	traits[index] = temporary;
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

float Creature::getBaseWaterNeed(){
	return base_waterNeed;
}
float Creature::getBaseBreedChance(){
	return base_breedChance;
}
float Creature::getBaseHerdTendency(){
	return base_herdTendency;
}
float Creature::getBaseTempResist(){
	return base_temp_resist;
}
float Creature::getBaseDiseaseResist(){
	return base_disease_resist;
}
float Creature::getBasePredatorResist(){
	return base_predator_resist;
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
	for(int i = 0; i < NUMTRAITS; i++){
		temp *= traits[i].getWaterNeed();
	}
	setWaterNeed(temp);
}
void Creature::calcBreedChance(){
	float temp = 1.00;
	for(int i = 0; i < NUMTRAITS; i++){
		temp *= traits[i].getBreedChance();
	}
	setBreedChance(temp);
}
void Creature::calcHerdTendency(){
	float temp = 1.00;
	for(int i = 0; i < NUMTRAITS; i++){
		temp *= traits[i].getHerdTendency();
	}
	setHerdTendency(temp);
}
void Creature::calcTempResist(){
	float temp = 1.00;
	for(int i = 0; i < NUMTRAITS; i++){
		temp *= traits[i].getTempResist();
	}
	setTempResist(temp);
}
void Creature::calcDiseaseResist(){
	float temp = 1.00;
	for(int i = 0; i < NUMTRAITS; i++){
		temp *= traits[i].getDiseaseResist();
	}
	setDieaseResist(temp);
}
void Creature::calcPredatorResist(){
	float temp = 1.00;
	for(int i = 0; i < NUMTRAITS; i++){
		temp *= traits[i].getPredatorResist();
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
bool Creature::updateHealth(Weather currSeason, Environment Env){
	if(diseased){
		float diff = .25 * disease_resist;
		health -= diff;
	}
	if(health < 0)
		return false;

	float temp = currSeason.getTemp();

	if((47.2 * temp_resist) > temp || (67.2 * temp_resist) < temp){
		if((47.2 * temp_resist) > temp){
			float diff = (47.2 * temp_resist) - temp;
			diff *= 0.1;
			health -= diff;
		}
		else{
			float diff = temp - (67.2 * temp_resist);
			diff *= 0.1;
			health -= diff;
		}
	}

	if(health < 0)
			return false;

	float water = Env.get_water_supply();

	if(water < waterNeed){
		float diff = waterNeed - water;
		diff *= .65;
		health -= diff;
	}
	else
		Env.set_water_supply(water - waterNeed);

	if(health < 0)
			return false;

	return true;
}

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


	//set offspring traits
	for(int i = 0; i < NUMTRAITS; i++){
		if(traits[i] >= other.traits[i])
			baby.traits[i] = traits[i];
		else
			baby.traits[i] = other.traits[i];
	}

	if(breed % 10 == 0)
		baby.mutate();

	baby.calcStats();

	return baby;

}

string Creature::mutate(){
	//TODO: implement method
	return "mutated";
}

