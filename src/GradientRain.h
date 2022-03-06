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
#include "utils/utils.h"

struct Drop {
	olc::vf2d position;
	olc::vf2d velocity;
	float gravity;
	float length;
	float thickness;

	Drop();
	Drop(olc::vf2d pos, olc::vf2d vel, float g, float len, float th);

	void fall(float fElapsedTime);
};

class GradientRain : public olc::PixelGameEngine {
private:
	const static int n = 250;
	Drop drops[n];

private: 
	Drop createDrop();
	void createDrops();
	void updateDrops(float fElapsedTime);
	void drawDrop(const Drop& drop);
	void drawDrops();

public:
	GradientRain();

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
};

#endif