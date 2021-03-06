/**
 * Season Class
 * Candace Allison
 *
 Environmental Factors
|-Season - Separate Class
| |-Current Weather ( varies seasonally, encourages varied traits )
|   |-Temperature ( varies by weather, encourages varied traits )
 */

#include "weather.h"
#include <sstream>
#include <string>
#include <map>


using std::string;
using std::map;

/**
 * Default Constructor. Sets default values for Weather class.
 * @param none
 */
Weather::Weather()
{
    set_map();

    season_num = -1;
    current_season = "None";
    temperature = 0.0;

    for(int i = 0; i < 4; i++)
        temp[i] = 0;
}

/**
 * Normal Constructor. Sets values for Weather based on numerical season value.
 * @param season
 */
Weather::Weather(int season)
{
    set_map();

    season_num = season;
    current_season = seasons[season_num];
}

/**
 * Getter. Returns current season.
 * @param none
 * @return current_season
 */
string Weather::getSeason()
{
    return current_season;
}

/**
 * Getter. Returns temperature of current season.
 * @param none
 * @return temperature
 */
float Weather::getTemp()
{
    return temperature;
}

/**
 * Setter. Sets current season.
 * @param s
 * @return none
 */
void Weather::setSeason(int s)
{
    season_num = s;
    current_season = seasons[season_num];

    find_temp();
}

/**
 * Setter. Sets temperature for the current season.
 * @param t
 * @return none
 */
void Weather::setTemp(float t)
{
    temperature = t;
}

/**
 * Setter. Sets a map for season names.
 * @param none
 * @return none
 */
void Weather::set_map()
{
    seasons[0] = "Spring";
    seasons[1] = "Summer";
    seasons[2] = "Fall";
    seasons[3] = "Winter";
}

/**
 * Setter. Sets temperature values for the season.
 * @param temps
 * @return none
 */
void Weather::set_temps(float * temps)
{
    for(int i = 0; i < 4; i++)
    {
        temp[i] = temps[i];
    }
}

/**
 * Method. Finds the temperature based on what season it is.
 * @param none
 * @return none
 */
void Weather::find_temp()
{
    if(season_num == 0) //Spring
        temperature = temp[0];
    else if(season_num == 1) //Summer
        temperature = temp[1];
    else if(season_num == 2) //Fall
        temperature = temp[2];
    else //Winter
        temperature = temp[3];
}

/**
 * Method. Changes the season.
 * @param none
 * @return none
 */
void Weather::change_season()
{
    if(season_num == 3)
    {
        season_num = 0;
    }
    else
    {
        season_num++;
    }

    setSeason(season_num);
}

/**
 * Method. ToString method for Weather.
 * @param none
 * @return toString
 */
string Weather::toString(){
    std::stringstream ss;
    string toString;

    ss << "\nSEASON:\t\t" << current_season;
    ss << "\nTEMPERATURE:\t" << temperature;

    toString = ss.str();
    return toString;
}
