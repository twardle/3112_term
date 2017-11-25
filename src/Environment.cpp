/** 
 * Environment Class
 * Candace Allison
 *
 Environmental Factors
|-Water Supply
| |-Available Water Locations ( less means higher danger )
| |-Water Refill Speed ( less means lower supportable population )
|-Disease
| |-Variant of mutation ( Only affects certain species, encourages evolution )
|-Space
  |- Current Population ( Lower means more herbivores, Higher means more predators )
  |-Foliage - Grass, Sandy, etc 
 */

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "Environment.h"
#include "Trait.h"

using std::string;
using std::map;
using std::stringstream;

Environment::Environment()
{

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			traitList[i][j] = Trait();
		}
	}

	current_environ = -1;
	water_supply = 0.0;
	water_refill_speed = 0.0;
	current_pop = 0;
	danger = 0.0;
	max_pop = 0;

	//Set weather
	cur_season = -1;
}

Environment::Environment(int b)
{

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 6; j++){
			traitList[i][j] = Trait();
		}
	}

	//Default values
	current_pop = 0;
	danger = 0;

	//Set string for current environment
	current_environ = b;

	//Set weather
	cur_season = 0;

	//Biome determines all other factors
	set_values();
}

string Environment::get_biome()
{
	return biome.name;
}

float Environment::get_water_supply()
{
	return water_supply;
}

void Environment::set_water_supply(float w)
{
	water_supply = w;
}

float Environment::get_water_refill_speed() {
	return water_refill_speed;
}

void Environment::set_water_refill_speed(float w) {
	water_refill_speed = w;
}

int Environment::get_current_pop() {
	return current_pop;
}

void Environment::set_current_pop(int c) {
	current_pop = c;
}

float Environment::get_danger() {
	return danger;
}

void Environment::set_danger(float d) {
	danger = d;
}

int Environment::get_max_pop() {
	return max_pop;
}

void Environment::set_max_pop(int m) {
	max_pop = m;
}

string Environment::get_season() {
	return season.getSeason();
}

float Environment::get_temp() {
	return season.getTemp();
}

void Environment::set_values() {
	if(current_environ == 0) //Desert
	{
		//Set biome name and temps
		biome.name = "Desert";
		biome.temps[0] = 80.0;
		biome.temps[1] = 100.0;
		biome.temps[2] = 80.0;
		biome.temps[3] = 70.0;

		//Set water variables
		set_water_supply(0.15);
		set_water_refill_speed(0.15);

		//Weather values
		season.set_temps(biome.temps);

		//Set maximum population
		set_max_pop(100);
	}
	else if(current_environ == 1) //Tundra
	{
		biome.name = "Tundra";
		biome.temps[0] = 10.0;
		biome.temps[1] = 30.0;
		biome.temps[2] = 20.0;
		biome.temps[3] = -10.0;

		//Set water variables
		set_water_supply(0.15);
		set_water_refill_speed(0.15);

		//Weather values
		season.set_temps(biome.temps);


		//Set maximum population
		set_max_pop(100);
	}
	else if(current_environ == 2) //Grasslands
	{
		biome.name = "Grasslands";
		biome.temps[0] = 75.0;
		biome.temps[1] = 95.0;
		biome.temps[2] = 80.0;
		biome.temps[3] = 65.0;

		//Set water variables
		set_water_supply(0.5);
		set_water_refill_speed(0.5);

		//Weather values
		season.set_temps(biome.temps);

		//Set maximum population
		set_max_pop(500);
	}
	else if(current_environ == 3) //Wetlands
	{
		biome.name = "Wetlands";
		biome.temps[0] = 40.0;
		biome.temps[1] = 75.0;
		biome.temps[2] = 60.0;
		biome.temps[3] = 25.0;

		//Set water variables
		set_water_supply(0.9);
		set_water_refill_speed(0.9);

		//Weather values
		season.set_temps(biome.temps);

		//Set maximum population
		set_max_pop(1000);
	}
	else  //Forest
	{
		biome.name = "Forest";
		biome.temps[0] = 50.0;
		biome.temps[1] = 95.0;
		biome.temps[2] = 70.0;
		biome.temps[3] = 30.0;

		//Set water variables
		set_water_supply(0.75);
		set_water_refill_speed(0.75);

		//Weather values
		season.set_temps(biome.temps);

		//Set maximum population
		set_max_pop(1000);
	}

	season.setSeason(cur_season);
}

void Environment::changeseason() {
	season.change_season();
}

void Environment::readTraits() {
	std::ifstream file ("data/Traits.csv");
	string value;
	int i = 0;

	getline(file,value);

	while(file.good()){
		Trait newTrait;
		stringstream ss;
		float x;
		bool y;
		int z;
		getline (file, value, ',');
		newTrait.setTraitName(value);
		getline (file, value, ',');
		ss << value;
		ss >> z;
		newTrait.setType(z);
		getline (file, value , ',');
		ss << value;
		ss >> y;
		newTrait.setDominance(y);
		getline (file, value, ',');
		switch(value[0]){
		case 'H':
		case 'h':
			newTrait.setAnimalType(0);
			break;
		case 'O':
		case 'o':
			newTrait.setAnimalType(1);
			break;
		case 'P':
		case 'p':
			newTrait.setAnimalType(2);
			break;
		default:
			newTrait.setAnimalType(-1);
		}

		getline (file, value, ',');
		ss << value;
		ss >> x;
		newTrait.setBreedChance(x);
		getline (file, value, ',');
		ss << value;
		ss >> x;
		newTrait.setHerdTendency(x);
		getline (file, value, ',');
		ss << value;
		ss >> x;
		newTrait.setWaterNeed(x);
		getline (file, value, ',');
		ss << value;
		ss >> x;
		newTrait.setTempResist(x);
		getline (file, value, ',');
		ss << value;
		ss >> x;
		newTrait.setDiseaseResist(x);
		getline (file, value);
		ss << value;
		ss >> x;
		newTrait.setPredatorResist(x);

		traitList[newTrait.getType()][i++] = newTrait;
		if(i == 6){
			if(newTrait.getType() == 4)
				break;
			else
				i = 0;
		}
		else if(newTrait.getType() == 0 && i == 3)
			i = 0;
	}
}
