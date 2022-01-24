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
	olc::vf3d pos;
	olc::vf3d vel;
	float gravity;
	float len;
	float thickness;

    olc::PixelGameEngine* pge;

private:
	void drawDroplet() {
		for (float i = 0.0f; i < len; i++) {
			olc::vf2d _pos = olc::v3dTov2d(pos);
			olc::vf2d dir = olc::v3dTov2d(vel).norm();
			uint32_t colour = gradient(i / len);
			pge->FillCircle(_pos + (dir * i), thickness, olc::Pixel(colour));
		}
	}
	
	void updateValues() {
		pos = olc::vf3d((float) random(0, pge->ScreenWidth()), (float) random(-200, -50), (float) random(0, 20));
		vel = olc::vf3d(map(pos.z, 0, 20, 10, 20), map(pos.z, 0, 20, 10, 20), 0) * 2;
		gravity = map(pos.z, 0, 20, 0.1, 0.2) * 2;
		len = map(pos.z, 0, 20, 10, 20);
		thickness = map(pos.z, 0, 20, 1, 3);
	}

public:

	Droplet(olc::PixelGameEngine* pge) {
		this->pge = pge;
		updateValues();
	}

	void fall() {
		if (pos.y > pge->ScreenHeight() || pos.x > pge->ScreenWidth()) {
			updateValues();
		}

		vel.y += gravity;
		pos += vel * pge->GetElapsedTime();
	}

	void show() {
		drawDroplet();
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
		// TODO: Blend pixels so that it looks better, currently not actually blending (use SetPixelBlend?)
		SetPixelMode(olc::Pixel::ALPHA);
		SetPixelBlend(0.8f);
		for (int i = 0; i < n; i++) {
			d[i]->fall();
			d[i]->show();
		}
		SetPixelMode(olc::Pixel::NORMAL);

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
	if (demo.Construct(1920, 1080, 1, 1, true))
		demo.Start();
	return 0;
}