#include <string>
#include <map>

using std::string;
using std::map;

#ifndef weather
#define weather

//Class Definition
class Weather
{
private:
	map<int,string> seasons;
	string current_season;
	int season_num;
	float temperature;
	float temp[4];

	//Methods
	void find_temp();
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
	void set_temps(float * temps);
};

#endif
