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

struct Drop {
	olc::vf2d pos;
	olc::vf2d vel;
	float g;
	float len;
	float thickness;

	Drop() : pos(olc::vf2d(0, 0)), vel(olc::vf2d(0, 0)),
		g(0), len(0), thickness(0) {}

	Drop(olc::vf2d _pos, olc::vf2d _vel, float _g, float _len, float _thickness) : 
		pos(_pos), vel(_vel), g(_g), len(_len), thickness(_thickness) {}

	void fall(float fElapsedTime) {
		vel.y += g;
		pos += vel * fElapsedTime;
	}
};

class GradientRain {
private:
	const static int n = 100;
	Drop drops[n];

    olc::PixelGameEngine* pge;

private: 
	Drop createDrop() {
		float z = random(0, 20);
		return 	Drop( 	olc::vf2d(random(0, pge->ScreenWidth()), random(-200, -50)),
					   	olc::vf2d(map(z, 0, 20, 10, 20), map(z, 0, 20, 10, 20)) * 2, 
						map(z, 0, 20, 0.1, 0.2),
						map(z, 0, 20, 10, 20), 
						map(z, 0, 20, 1, 3));
	}

	void createDrops() {
		for (int i = 0; i < n; i++) {
			drops[i] = createDrop();
		}
	}

	void updateDrops() {
		for (int i = 0; i < n; i++) {
			if (drops[i].pos.x > pge->ScreenWidth() || drops[i].pos.y > pge->ScreenHeight())
				drops[i] = createDrop();

			drops[i].fall(pge->GetElapsedTime());
		}
	}

	void drawDrop(Drop drop) {
		for (float i = 0.0f; i < drop.len; i++) {
			olc::vf2d dir = drop.vel.norm();
			uint32_t colour = gradient(i / drop.len);
			pge->FillCircle(drop.pos + (dir * i), drop.thickness, olc::Pixel(colour));
		}
	}

	void drawDrops() {
		for (int i = 0; i < n; i++) {
			Drop drop = drops[i];
			drawDrop(drop);
		}
	}

public:
	GradientRain() : pge(nullptr) {}

	GradientRain(olc::PixelGameEngine* _pge) : pge(_pge) {}
	
	void createRain() {
		createDrops();
	}

	void updateRain() {
		updateDrops();
		drawDrops();
	}
};

class DankRain : public olc::PixelGameEngine
{
	GradientRain rain;

public:
	DankRain()
	{
		sAppName = "DankRain";
	}

public:
	bool OnUserCreate() override
	{	
		rain = GradientRain(this);
		rain.createRain();

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(BG);
		rain.updateRain();

		return true;
	}

	bool OnUserDestroy() override 
	{

		return true;
	}
};

int main()
{
	DankRain demo;
	if (demo.Construct(1280, 720, 1, 1))
		demo.Start();
	return 0;
}