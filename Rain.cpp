/**
 * @file Rain.cpp
 * @author Matthew Sasakamoose (matt.sasakamoose@gmail.com)
 * @brief Purple rain project ported from processing 
 * 		  inspired by https://thecodingtrain.com/CodingChallenges/004-purplerain.html
 * @version 0.5
 * @date 2022-01-22
 */

#include "Rain.h"
#include "GradientRain.h"

static const olc::Pixel DankPurp(138, 43, 226), BG(0, 0, 0);

Rain::Rain() {
	sAppName = "Rain";
}

bool Rain::OnUserCreate() {	
	rain = GradientRain(this);
	rain.createRain();

	return true;
}

bool Rain::OnUserUpdate(float fElapsedTime) {
	Clear(BG);
	rain.updateRain();

	return true;
}