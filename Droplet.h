/**
 * @file Droplet.h
 * @author Matthew Sasakamoose (matt.sasakamoose@gmail.com)
 * @brief Droplet class definition used in the purple rain project
 * @version 0.1
 * @date 2022-01-22`
 */

#ifndef DROPLET_H_DEF
#define DROPLET_H_DEF

#include "olcPixelGameEngine.h"
#include "utils.h"

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
			uint32_t colour = gradient(i / len);
			pge->Draw(x, y+i, olc::Pixel(colour));
		}
	}

public:

	Droplet(olc::PixelGameEngine* pge) {
		this->pge = pge;
		this->x = (float) random(0, pge->ScreenWidth());
		this->y = (float) random(-200, -50);
		this->z = (float) random(0, 20); 
		this->yspeed = (float) random(75, 600);
		this->len = (float) random(15, 35);
	}

	void fall() {
		y = y + (yspeed * pge->GetElapsedTime());
		
		if (y > pge->ScreenHeight()) 
			y = (float) random(-200, -50);
	}

	void show() {
		DrawDroplet();
	}
	
};

#endif