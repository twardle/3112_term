/** 
 * Season Class
 * Candace Allison
 *
 Environmental Factors
|-Season - Separate Class
| |-Current Weather ( varies seasonally, encourages varied traits )
|   |-Temperature ( varies by weather, encourages varied traits )
 */

#include "Weather.h"
#include <sstream>
#include <string>
#include <map>


using std::string;
using std::map;

Weather::Weather()
{
	set_map();

	season_num = -1;
	current_season = "None";
	temperature = 0.0;

	for(int i = 0; i < 4; i++)
		temp[i] = 0;
}

Weather::Weather(int season)
{
	set_map(); 

	season_num = season;
	current_season = seasons[season_num];
}

string Weather::getSeason()
{
	return current_season;
}

float Weather::getTemp()
{
	return temperature;
}

void Weather::setSeason(int s)
{
	season_num = s;
	current_season = seasons[season_num];

	find_temp();
}

void Weather::setTemp(float t)
{
	temperature = t;
}

void Weather::set_map()
{
	seasons[0] = "Spring";
	seasons[1] = "Summer";
	seasons[2] = "Fall";
	seasons[3] = "Winter";
}

void Weather::set_temps(float * temps)
{
	for(int i = 0; i < 4; i++)
	{
		temp[i] = temps[i];
	}
}

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

string Weather::toString(){
	std::stringstream ss;
	string toString;

	ss << "\nSEASON:\t\t" << current_season;
	ss << "\nTEMPERATURE:\t" << temperature;

	toString = ss.str();
	return toString;


}
