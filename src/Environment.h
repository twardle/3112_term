#include <string>
#include <map>
#include "Weather.h"
#include <fstream>
#include "Trait.h"
#include <sstream>
#include <list>

using std::string;
using std::map;

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

struct biomes
{
	std::string name = "None";
	float temps[4];
	float water_supply_m;
	float water_refill_m;
};

struct seasons
{
	float water_supply_m;
	float water_refill_m;
};

class Environment {
private:
	struct biomes biome;
	struct seasons season_multiply;

    int current_environ;

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
    void set_values();

public:

    Trait traitList[5][6];

    Environment();
    Environment(int);

    //Getters/Setters
    string get_biome();
    float get_water_supply();
    void set_water_supply(float);
    float get_water_refill_speed();
    void set_water_refill_speed(float);
    int get_current_pop();
    void set_current_pop(int);
    float get_danger();
    void set_danger(float);
    int get_max_pop();
    void set_max_pop(int);
    string get_season();
    float get_temp();

    //Methods
    void calculate_danger();
    void readTraits();
    void changeseason();
};

#endif
