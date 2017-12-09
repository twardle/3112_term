/*
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

/**
 * Default Constructor. Sets default values for Environment.
 * @param none
 */
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

/**
 * Normal Constructor. Sets values for Environment based on input b.
 * @param b
 */
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

/**
 * Getter. Returns name for a biome
 * @param none
 * @return biome.name
 */
string Environment::get_biome()
{
    return biome.name;
}

/**
 * Getter. Returns water supply for an Environment.
 * @param none
 * @return water_supply
 */
float Environment::get_water_supply()
{
    return water_supply;
}

/**
 * Setter. Sets water supply for an Environment.
 * @param w
 * @return none
 */
void Environment::set_water_supply(float w)
{
    water_supply = w;
}

/**
 * Getter. Returns water refill speed for Environment.
 * @param none
 * @return water_refill_speed
 */
float Environment::get_water_refill_speed() {
    return water_refill_speed;
}

/**
 * Setter. Sets water refill speed for an Environment.
 * @param w
 * @return none
 */
void Environment::set_water_refill_speed(float w) {
    water_refill_speed = w;
}

/**
 * Getter. Returns current population of the Environment.
 * @param none
 * @return current_pop
 */
int Environment::get_current_pop() {
    return current_pop;
}

/**
 * Setter. Sets the current population for the Environment.
 * @param c
 * @return none
 */
void Environment::set_current_pop(int c) {
    current_pop = c;
}

/**
 * Getter. Returns the danger for the Environment.
 * @param none
 * @return danger
 */
float Environment::get_danger() {
    return danger;
}

/**
 * Setter. Sets danger for the Environment.
 * @param d
 * @return none
 */
void Environment::set_danger(float d) {
    danger = d;
}

/**
 * Getter. Returns maximum population for an Environment.
 * @param none
 * @return max_pop
 */
int Environment::get_max_pop() {
    return max_pop;
}

/**
 * Setter. Sets maximum population for an Environment.
 * @param m
 * @return none
 */
void Environment::set_max_pop(int m) {
    max_pop = m;
}

/**
 * Getter. Returns the current season for the Environment.
 * @param none
 * @return season
 */
Weather Environment::get_season() {
    return season;
}

/**
 * Getter. Returns current temperature of the Environment.
 * @param none
 * @return season.getTemp()
 */
float Environment::get_temp() {
    return season.getTemp();
}

/**
 * Setter. Sets maximum water supply for the Environment.
 * @param max
 * @return none
 */
void Environment::set_max_water_supply(float max){
    max_water_supply = max;
}

/**
 * Method. Sets temperature values for the ENvironment.
 * @param none
 * @return none
 */
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

/**
 * Method. Changes the current season of the Environment.
 * @param none
 * @return none
 */
void Environment::changeseason() {
    season.change_season();
    num_iterations++;
    if(water_supply + water_refill_speed < max_water_supply)
        set_water_supply(water_supply + water_refill_speed);
    else
        set_water_supply(max_water_supply);
}

/**
 * Method. Reads traits from csv file.
 * @param none
 * @return none
 */
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

/**
 * Method. ToString method for Environment
 * @param pop
 * @return toString
 */
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
