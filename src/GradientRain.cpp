/**
 * @file GradientRain.cpp
 * @author Matthew Sasakamoose (matt.sasakamoose@gmail.com)
 * @brief gradient rain class implementations
 * @version 0.1
 * @date 2022-01-25
 */

#include "GradientRain.h"

Drop::Drop() : position(olc::vf2d(0, 0)), velocity(olc::vf2d(0, 0)),
    gravity(0), length(0), thickness(0) {}

Drop::Drop(olc::vf2d pos, olc::vf2d vel, float g, float len, float th) : 
    position(pos), velocity(vel), gravity(g), length(len), thickness(th) {}

void Drop::fall(float fElapsedTime)  {
    velocity.y += gravity * fElapsedTime;
    position += velocity * fElapsedTime;
}

GradientRain::GradientRain() {
    sAppName = "Rainbow Rain!";
}

Drop GradientRain::createDrop() {
    float z = random(0, 20);
    return 	Drop( 	olc::vf2d(random(-ScreenWidth()/2, ScreenWidth()), random(-200, -50)),
                    olc::vf2d(map(z, 0, 20, 20, 40), map(z, 0, 20, 20, 60)), 
                    map(z, 0, 20, 10, 20),
                    map(z, 0, 20, 10, 30), 
                    map(z, 0, 20, 1, 3));
}

void GradientRain::createDrops() {
    for (int i = 0; i < n; i++) {
        drops[i] = createDrop();
    }
}

void GradientRain::updateDrops(float fElapsedTime) {
    for (int i = 0; i < n; i++) {
        if (drops[i].position.x > ScreenWidth() || drops[i].position.y > ScreenHeight())
            drops[i] = createDrop();

        drops[i].fall(fElapsedTime);
    }
}

void GradientRain::drawDrop(const Drop& drop) {
    for (float i = 0.0f; i < drop.length; i += 0.5f) {
        olc::vf2d dir = drop.velocity.norm();
        uint32_t colour = gradient(i / drop.length);
        FillCircle(drop.position + (dir * i), drop.thickness, olc::Pixel(colour));
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