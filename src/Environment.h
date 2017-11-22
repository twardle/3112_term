#include <string>
#include <map>

using std::string;
using std::map;

#include "Weather.h"
#include "Trait.h"
#include <fstream>
#include <sstream>

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

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
    Trait traitList[5][5];


    //Private methods
    void set_map();
    void set_values();
    void changeseason();

public:
    Environment();
    Environment(int b);

    //Getters/Setters
    string get_biome();
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
    void readTraits();
};

#endif
