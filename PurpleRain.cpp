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
	olc::vf2d* pos;
	olc::vf2d* vel;
	float z;
	float len;
	float thickness;

    olc::PixelGameEngine* pge;

private:
	void DrawDroplet() {
		for (float i = 0.0f; i < len; i++) {
			uint32_t colour = gradient(i / len);
			pge->FillRect(pos->x, pos->y+i, thickness, 1, olc::Pixel(colour));
		}
	}

public:

	Droplet(olc::PixelGameEngine* pge) {
		this->pge = pge;
		this->pos = new olc::vf2d((float) random(0, pge->ScreenWidth()), (float) random(-200, -50));
		this->z = (float) random(0, 20); 
		this->vel = new olc::vf2d(0.0f, map(z, 0, 20, 75, 300));
		this->len = map(z, 0, 20, 15, 35);
		this->thickness = map(z, 0, 20, 1, 3);
	}

	void fall() {
		pos->y = pos->y + (vel->y * pge->GetElapsedTime());

		if (pos->y > pge->ScreenHeight()) {
			pos->y = (float) random(-200, -50);
			vel->y = map(z, 0, 20, 75, 300);
		}
	}

	void show() {
		DrawDroplet();
	}
	
};

class PurpleRain : public olc::PixelGameEngine
{
private:
	const static int n = 100;
	Droplet* d[n];

public:
	PurpleRain()
	{
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