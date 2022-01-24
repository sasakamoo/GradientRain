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

static const olc::Pixel BGPurp(0, 0, 0);

class Droplet {
private:
	vf3d pos;
	vf3d vel;
	float len;
	float thickness;

    olc::PixelGameEngine* pge;

private:
	void DrawDroplet() {
		for (float i = 0.0f; i < len; i++) {
			uint32_t colour = gradient(i / len);
			pge->FillRect(pos.x, pos.y+i, thickness, 1, olc::Pixel(colour));
		}
	}

public:

	Droplet(olc::PixelGameEngine* pge) {
		this->pge = pge;
		this->pos = vf3d((float) random(0, pge->ScreenWidth()), (float) random(-200, -50), (float) random(0, 20));
		this->vel = vf3d(0, map(pos.z, 0, 20, 75, 300), 0);
		this->len = map(pos.z, 0, 20, 15, 35);
		this->thickness = map(pos.z, 0, 20, 1, 3);
	}

	void fall() {
		pos.y = pos.y + (vel.y * pge->GetElapsedTime());

		if (pos.y > pge->ScreenHeight()) {
			pos.y = (float) random(-200, -50);
			vel.y = map(pos.z, 0, 20, 75, 300);
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