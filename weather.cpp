/** 
 * Season Class
 * Candace Allison
 *
 Environmental Factors
|-Season - Separate Class
| |-Current Weather ( varies seasonally, encourages varied traits )
|   |-Temperature ( varies by weather, encourages varied traits )
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

//Class Definition
class Weather
{
private:
	map<int,string> seasons;
	string current_season;
	int season_num;
	float temperature;

	//Methods
	float find_temp(int s);
	void set_map();

public: 
	//Constructors
	Weather();
	Weather(int season);

	//Getters and Setters
	string getSeason();
	void setSeason(int s);
	float getTemp();
	void setTemp(float t);

	//Method
	void change_season();
};

Weather::Weather()
{
	set_map();

	season_num = -1;
	current_season = "None";
	temperature = 0.0;
}

Weather::Weather(int season)
{
	set_map(); 

	season_num = season;
	current_season = seasons[season_num];
	temperature = find_temp(season_num);
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

	//Change temperature based on the season
	temperature = find_temp(s);
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

float Weather::find_temp(int s)
{
	if(s == 0) //Spring
		return 50.0;
	else if(s == 1) //Summer
		return 85.0; 
	else if(s == 2) //Fall
		return 50.0;
	else //Winter
		return 30.0;
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