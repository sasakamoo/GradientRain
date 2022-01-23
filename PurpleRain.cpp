/**
 * @file PurpleRain.cpp
 * @author Matthew Sasakamoose (matt.sasakamoose@gmail.com)
 * @brief Purple rain project ported from processing 
 * 		  inspired by https://thecodingtrain.com/CodingChallenges/004-purplerain.html
 * @version 0.1
 * @date 2022-01-22
 */

#include "olcPixelGameEngine.h"
#include "utils.h"
#include "Droplet.h"

static const olc::Pixel BGPurp(230, 230, 250);

// Override base class with your custom functionality
class PurpleRain : public olc::PixelGameEngine
{
private:
	const static int n = 100;
	Droplet* d[n];

public:
	PurpleRain()
	{
		// Name your application
		sAppName = "PurpleRain";
	}

public:
	bool OnUserCreate() override
	{	
		for (int i = 0; i < n; i++) {
			d[i] = new Droplet(this);
		}

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Set background colour
		Clear(BGPurp);
		for (int i = 0; i < n; i++) {
			d[i]->fall();
			d[i]->show();
		}

		return true;
	}

	bool OnUserDestroy() override 
	{
		delete[] d;
		return true;
	}
};

int main()
{
	PurpleRain demo;
	if (demo.Construct(640, 360, 1, 1))
		demo.Start();
	return 0;
}