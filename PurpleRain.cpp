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

static const olc::Pixel BGPurp(230, 230, 250);

class Droplet {
private:
	float x;
	float y;
	float z;
	float yspeed;
	float len;

    olc::PixelGameEngine* pge;

private:
	void DrawDroplet() {
		for (float i = 0.0f; i < len; i++) {
			float thickness = map(z, 0, 20, 1, 3);
			uint32_t colour = gradient(i / len);
			pge->FillRect(x, y+i, thickness, 1, olc::Pixel(colour));
		}
	}

public:

	Droplet(olc::PixelGameEngine* pge) {
		this->pge = pge;
		this->x = (float) random(0, pge->ScreenWidth());
		this->y = (float) random(-200, -50);
		this->z = (float) random(0, 20); 
		this->yspeed = map(z, 0, 20, 75, 300);
		this->len = map(z, 0, 20, 15, 35);
	}

	void fall() {
		y = y + (yspeed * pge->GetElapsedTime());

		if (y > pge->ScreenHeight()) {
			y = (float) random(-200, -50);
			yspeed = map(z, 0, 20, 75, 300);
		}
	}

	void show() {
		DrawDroplet();
	}
	
};

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
	if (demo.Construct(640, 360, 2, 2))
		demo.Start();
	return 0;
}