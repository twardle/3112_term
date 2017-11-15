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

#include "weather.h"

using std::string;
using std::map;

class Environment
{
private:
	map<int,string> biomes;
	int current_environ;
	string str_environ;

	//Water Supply
	float water_supply;
	float water_refill_speed;

	//Disease - implement later

	//Weather
	Weather season;
	int cur_season;

	//Space
	int current_pop;

	//Other variables
	float danger;
	int max_pop;	

	//Private methods
	void set_map();
	void set_values();

public:
	Environment();
	Environment(int b);

	//Getters/Setters
	string get_biome();
	void set_biome(int b);
	float get_water_supply();
	void set_water_supply(float w);
	float get_water_refill_speed();
	void set_water_refill_speed(float w);
	int get_current_pop();
	void set_current_pop(int c);
	float get_danger();
	void set_danger(float d);
	int get_max_pop();
	void set_max_pop(int m);
	string get_season();
	float get_temp();

	//Methods
	void calculate_danger();
};

Environment::Environment()
{
	set_map();

	current_environ = -1;
	str_environ = "None";
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
	set_map();

	//Default values
	current_pop = 0;
	danger = 0;

	//Set string for current environment
	current_environ = b;
	str_environ = biomes[b];

	//Set weather
	cur_season = 0;

	//Biome determines all other factors
	set_values();

	
}

string Environment::get_biome()
{
	return str_environ;
}

void Environment::set_biome(int b)
{
	//Do later
}

float Environment::get_water_supply()
{
	return water_supply;
}

void Environment::set_water_supply(float w)
{
	water_supply = w;
}

float Environment::get_water_refill_speed()
{
	return water_refill_speed;
}

void Environment::set_water_refill_speed(float w)
{
	water_refill_speed = w;
}

int Environment::get_current_pop()
{
	return current_pop;
}

void Environment::set_current_pop(int c)
{
	current_pop = c;
}

float Environment::get_danger()
{
	return danger;
}

void Environment::set_danger(float d)
{
	danger = d;
}

int Environment::get_max_pop()
{
	return max_pop;
}

void Environment::set_max_pop(int m)
{
	max_pop = m;
}

string Environment::get_season()
{
	return season.getSeason();
}

float Environment::get_temp()
{
	return season.getTemp();
}

void Environment::set_map()
{
	biomes[0] = "Desert";
	biomes[1] = "Tundra";
	biomes[2] = "Grasslands";
	biomes[3] = "Wetlands";
	biomes[4] = "Forest";
}

void Environment::set_values()
{
	if(current_environ == 0) //Desert
	{
		//Set water variables
		set_water_supply(0.15);
		set_water_refill_speed(0.15);

		//Weather values
		float temps[] = {80.0, 100.0, 80.0, 70.0};
		season.set_temps(temps);

		//Set maximum population
		set_max_pop(100);
	}
	else if(current_environ == 1) //Tundra
	{
		//Set water variables
		set_water_supply(0.15);
		set_water_refill_speed(0.15);

		//Weather values
		float temps[] = {10.0, 30.0, 20.0, -10.0};
		season.set_temps(temps);


		//Set maximum population
		set_max_pop(100);
	}
	else if(current_environ == 2) //Grasslands
	{
		//Set water variables
		set_water_supply(0.5);
		set_water_refill_speed(0.5);

		//Weather values
		float temps[] = {75.0, 95.0, 80.0, 65.0};
		season.set_temps(temps);

		//Set maximum population
		set_max_pop(500);
	}
	else if(current_environ == 3) //Wetlands
	{
		//Set water variables
		set_water_supply(0.9);
		set_water_refill_speed(0.9);

		//Weather values
		float temps[] = {40.0, 75.0, 60.0, 25.0};
		season.set_temps(temps);

		//Set maximum population
		set_max_pop(1000);
	}
	else  //Forest
	{
		//Set water variables
		set_water_supply(0.75);
		set_water_refill_speed(0.75);

		//Weather values
		float temps[] = {50.0, 95.0, 70.0, 30.0};
		season.set_temps(temps);

		//Set maximum population
		set_max_pop(1000);
	}

	season.setSeason(cur_season);
}
