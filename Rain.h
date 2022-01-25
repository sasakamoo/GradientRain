#ifndef RAIN_H_DEF
#define RAIN_H_DEF

#include "olcPixelGameEngine.h"
#include "GradientRain.h"

class Rain : public olc::PixelGameEngine
{
	GradientRain rain;

public:
	Rain();

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

};

#endif