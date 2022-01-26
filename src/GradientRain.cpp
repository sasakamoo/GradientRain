/**
 * @file GradientRain.cpp
 * @author Matthew Sasakamoose (matt.sasakamoose@gmail.com)
 * @brief gradient rain class implementations
 * @version 0.1
 * @date 2022-01-25
 */

#include "GradientRain.h"
#include "olcPixelGameEngine.h"
#include "utils.h"

Drop::Drop() : pos(olc::vf2d(0, 0)), vel(olc::vf2d(0, 0)),
    g(0), len(0), thickness(0) {}

Drop::Drop(olc::vf2d _pos, olc::vf2d _vel, float _g, float _len, float _thickness) : 
    pos(_pos), vel(_vel), g(_g), len(_len), thickness(_thickness) {}

void Drop::fall(float fElapsedTime)  {
    vel.y += g;
    pos += vel * fElapsedTime;
}

GradientRain::GradientRain() {
    sAppName = "Rainbow Rain!";
}

Drop GradientRain::createDrop() {
    float z = random(0, 20);
    return 	Drop( 	olc::vf2d(random(0, ScreenWidth()), random(-200, -50)),
                    olc::vf2d(map(z, 0, 20, 10, 20), map(z, 0, 20, 10, 20)) * 2, 
                    map(z, 0, 20, 0.1, 0.2),
                    map(z, 0, 20, 10, 20), 
                    map(z, 0, 20, 1, 3));
}

void GradientRain::createDrops() {
    for (int i = 0; i < n; i++) {
        drops[i] = createDrop();
    }
}

void GradientRain::updateDrops(float fElapsedTime) {
    for (int i = 0; i < n; i++) {
        if (drops[i].pos.x > ScreenWidth() || drops[i].pos.y > ScreenHeight())
            drops[i] = createDrop();

        drops[i].fall(fElapsedTime);
    }
}

void GradientRain::drawDrop(Drop drop) {
    for (float i = 0.0f; i < drop.len; i++) {
        olc::vf2d dir = drop.vel.norm();
        uint32_t colour = gradient(i / drop.len);
        FillCircle(drop.pos + (dir * i), drop.thickness, olc::Pixel(colour));
    }
}

void GradientRain::drawDrops() {
    for (int i = 0; i < n; i++) {
        drawDrop(drops[i]);
    }
}

bool GradientRain::OnUserCreate() {
    createDrops();

    return true;
}

bool GradientRain::OnUserUpdate(float fElapsedTime) {
    Clear({ 0, 0, 0 });

    updateDrops(fElapsedTime);
    drawDrops();

    return true;
}