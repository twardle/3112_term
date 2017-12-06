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

#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "environment.h"
#include "trait.h"

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
    max_water_supply = water_supply * 2;
    water_refill_speed = 0.0;
    current_pop = 0;
    danger = 0.0;
    max_pop = 0;
    num_iterations = 0;

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

    water_supply = 0.0;
    max_water_supply = water_supply * 2;
    water_refill_speed = 0.0;

    //Set string for current environment
    current_environ = b;

    //Set weather
    cur_season = 0;
    num_iterations = 0;

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

Weather Environment::get_season() {
    return season;
}

float Environment::get_temp() {
    return season.getTemp();
}
void Environment::set_max_water_supply(float max){
    max_water_supply = max;
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
        set_water_supply(750.00);
        set_max_water_supply(water_supply * 2);
        set_water_refill_speed(water_supply/2);

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
        set_water_supply(1250);
        set_max_water_supply(water_supply * 2);
        set_water_refill_speed(water_supply/2);

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
        set_water_supply(1500);
        set_max_water_supply(water_supply * 2);
        set_water_refill_speed(water_supply/2);

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
        set_water_supply(2000);
        set_max_water_supply(water_supply * 2);
        set_water_refill_speed(water_supply/2);

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
        set_water_supply(1750);
        set_max_water_supply(water_supply * 2);
        set_water_refill_speed(water_supply/2);

        //Weather values
        season.set_temps(biome.temps);

        //Set maximum population
        set_max_pop(1000);
    }

    season.setSeason(cur_season);
}

void Environment::changeseason() {
    season.change_season();
    num_iterations++;
    if(water_supply + water_refill_speed < max_water_supply)
        set_water_supply(water_supply + water_refill_speed);
    else
        set_water_supply(max_water_supply);
}

void Environment::readTraits() {
    std::ifstream file;
    //file.open("/Users/candicane/Documents/Programs/QT/Simulator/traits.csv");
    //file.open("../../../../QT/Simulator/traits.csv");

    //Get working directory
    char * dir = getcwd(NULL,0);
    string new_path = "/";

    //Split directory string on /
    char * dir_str = strtok(dir,"/");
    while(dir_str != NULL)
    {
        //Add to new_path
        string str(dir_str);
        new_path += str + "/";

        if(str == "QT")
        {
            //Add Simulator/traits.csv to filename and break
            new_path += "Simulator/traits.csv";
            break;
        }
        else
        {
            dir_str = strtok(NULL,"/");
        }
    }

    //Open file at new file path
    file.open(new_path);

    string value;
    int i = 0;

    getline(file,value);

    while(file.good())
    {
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
        ss.clear();
        newTrait.setType(z);
        getline (file, value , ',');
        y = atoi (value.c_str());
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
        x = atof (value.c_str());
        newTrait.setBreedChance(x);
        getline (file, value, ',');
        x = atof (value.c_str());
        newTrait.setHerdTendency(x);
        getline (file, value, ',');
        x = atof (value.c_str());
        newTrait.setWaterNeed(x);
        getline (file, value, ',');
        x = atof (value.c_str());
        newTrait.setTempResist(x);
        getline (file, value, ',');
        x = atof (value.c_str());
        newTrait.setDiseaseResist(x);
        getline (file, value);
        x = atof (value.c_str());
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

string Environment::toString(int pop){
    std::stringstream ss;
    string toString;

    ss << "\nBIOME:\t\t" << get_biome();
    ss << "\nNUM ITERATIONS:\t" << num_iterations;
    ss << "\nWATER SUPPLY:\t" << water_supply << " (+" << water_refill_speed << ")";
    ss << "\nPOPULATION:\t" << pop;

    toString = ss.str();
    return toString;
}
