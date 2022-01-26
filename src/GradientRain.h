/**
 * @file GradientRain.h
 * @author Matthew Sasakamoose (matt.sasakamoose@gmail.com)
 * @brief Gradient rain class declarations
 * @version 0.1
 * @date 2022-01-25
 */

#ifndef GRADIENTRAIN_H_DEF
#define GRADIENTRAIN_H_DEF

#include "pge/olcPixelGameEngine.h"

struct Drop {
	olc::vf2d pos;
	olc::vf2d vel;
	float g;
	float len;
	float thickness;

	Drop();
	Drop(olc::vf2d _pos, olc::vf2d _vel, float _g, float _len, float _thickness);

	void fall(float fElapsedTime);
};

class GradientRain : public olc::PixelGameEngine {
private:
	const static int n = 100;
	Drop drops[n];

private: 
	Drop createDrop();
	void createDrops();
	void updateDrops(float fElapsedTime);
	void drawDrop(Drop drop);
	void drawDrops();

public:
	GradientRain();

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};

#endif