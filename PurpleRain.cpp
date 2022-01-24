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

static const olc::Pixel DankPurp(138, 43, 226), BG(0, 0, 0);

class Droplet {
private:
	olc::vf3d pos;
	olc::vf3d vel;
	float len;
	float thickness;
	float gravity;

	// Eventually want this pointer out of this class
	olc::PixelGameEngine* pge;

private:
	
	void resetFall() {
		pos = olc::vf3d((float) random(0, pge->ScreenWidth()), (float) random(-200, -50), (float) random(0, 20));
		vel = olc::vf3d(map(pos.z, 0, 20, 10, 20), map(pos.z, 0, 20, 10, 20), 0) * 2;
		len = map(pos.z, 0, 20, 10, 20);
		thickness = map(pos.z, 0, 20, 1, 3);
		gravity = map(pos.z, 0, 20, 0.1, 0.2) * 2;
	}

public:
	Droplet(olc::PixelGameEngine* pge) {
		this->pge = pge;
		resetFall();
	}

	void fall() {
		if (pos.y > pge->ScreenHeight() || pos.x > pge->ScreenWidth()) {
			resetFall();
		}

		vel.y += gravity;
		pos += vel * pge->GetElapsedTime();
	}

	olc::vf3d getPos() {
		return pos;
	}

	olc::vf3d getVel() {
		return vel;
	}

	float getLen() {
		return len;
	}

	float getThickness() {
		return thickness;
	}
	
};

class GradientRain {
private:
	const static int n = 100;
	Droplet* d[n];

    olc::PixelGameEngine* pge;

private: 

	void createDroplets() {
		for (int i = 0; i < n; i++) {
			d[i] = new Droplet(pge);
		}
	}

	void updateDroplets() {
		for (int i = 0; i < n; i++) {
			d[i]->fall();
		}
	}

	void deleteDroplets() {
		delete[] d;
	}

	void drawDroplets() {
		for (int i = 0; i < n; i++) {
			Droplet drop = *d[i];
			for (float j = 0.0f; j < drop.getLen(); j++) {
				olc::vf2d pos = olc::v3dTov2d(drop.getPos());
				olc::vf2d dir = olc::v3dTov2d(drop.getVel());
				uint32_t colour = gradient(j / drop.getLen());
				pge->FillCircle(pos + (dir * j), drop.getThickness(), olc::Pixel(colour));
			}
		}
	}

public:

	GradientRain(olc::PixelGameEngine* pge) {
		this->pge = pge;
	}
	
	void createRain() {
		createDroplets();
	}

	void updateRain() {
		updateDroplets();
		drawDroplets();
	}

	void deleteRain() {
		deleteDroplets();
	}
};

class DankRain : public olc::PixelGameEngine
{
	GradientRain* rain;
public:
	DankRain()
	{
		sAppName = "DankRain";
	}

public:
	bool OnUserCreate() override
	{	
		rain = new GradientRain(this);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(BG);
		rain->updateRain();

		return true;
	}

	bool OnUserDestroy() override 
	{
		rain->deleteRain();

		return true;
	}
};

int main()
{
	DankRain demo;
	if (demo.Construct(1920, 1080, 1, 1, true, true))
		demo.Start();
	return 0;
}