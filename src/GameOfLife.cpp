#include "GameOfLife.h"

GameOfLife::GameOfLife() {
    sAppName = "Game Of Life";
}

void GameOfLife::worldToScreen(const olc::vf2d& v, int& screenX, int& screenY) {
    screenX = (int)((v.x - offset.x) * scale);
    screenY = (int)((v.y - offset.y) * scale);
}

void GameOfLife::screenToWorld(int screenX, int screenY, olc::vf2d& v) {
    v.x = (float)((screenX / scale) + offset.x);
    v.y = (float)((screenY / scale) + offset.y);
}

bool GameOfLife::OnUserCreate() {
    offset = { (float)((-ScreenWidth() / 2) / scale), (float)((-ScreenHeight() / 2) / scale) };
    return true;
}

bool GameOfLife::OnUserUpdate(float fElapsedTime) {
    // Get mouse location of this frame
    olc::vf2d mouse = { (float)GetMouseX(), (float)GetMouseY() };

    // Handle pan and zoom
    if (GetMouse(2).bPressed || GetKey(olc::Key::SPACE).bPressed) {
        startPan = mouse;
    }

    if (GetMouse(2).bHeld || GetKey(olc::Key::SPACE).bHeld) {
        offset -= (mouse - startPan) / scale;
        startPan = mouse;
    }

    olc::vf2d mouseBeforeZoom;
    screenToWorld((int)mouse.x, (int)mouse.y, mouseBeforeZoom);

    if (GetKey(olc::Key::Q).bHeld || GetMouseWheel() > 0) {
        scale *= 1.1f;
    }

    if (GetKey(olc::Key::A).bHeld || GetMouseWheel() < 0) {
        scale *= 0.9f;
    }

    olc::vf2d mouseAfterZoom;
    screenToWorld((int)mouse.x, (int)mouse.y, mouseAfterZoom);
    offset += (mouseBeforeZoom - mouseAfterZoom);

    // Snap cursor to nearest cell
    cursor.x = floorf((mouseAfterZoom.x + 0.5f) * grid);
    cursor.y = floorf((mouseAfterZoom.y + 0.5f) * grid);

    // Start drawing
    Clear(olc::BLACK);

    int sx, sy, ex, ey;

    // Get visible world
    olc::vf2d worldTopLeft, worldBottomRight;
    screenToWorld(0, 0, worldTopLeft);
    screenToWorld(ScreenWidth(), ScreenHeight(), worldBottomRight);

    // Set values to just beyond screen boundaries
    worldTopLeft.x = floorf(worldTopLeft.x);
    worldTopLeft.y = floorf(worldTopLeft.y);
    worldBottomRight.x = ceilf(worldBottomRight.x);
    worldBottomRight.y = ceilf(worldBottomRight.y);

    // Draw grid dots of world
    for (float x = worldTopLeft.x; x < worldBottomRight.x; x += grid) {
        for (float y = worldTopLeft.y; y < worldBottomRight.y; y += grid) {
            worldToScreen({ x, y }, sx, sy);
            Draw(sx, sy, olc::BLUE);
        }
    }

    // Draw world axis
    worldToScreen({ 0, worldTopLeft.y }, sx, sy);
    worldToScreen({ 0, worldBottomRight.y }, ex, ey);
    DrawLine(sx, sy, ex, ey, olc::GREY, 0xF0F0F0F0);
    worldToScreen({ worldTopLeft.x, 0 }, sx, sy);
    worldToScreen({ worldBottomRight.x, 0 }, ex, ey);
    DrawLine(sx, sy, ex, ey, olc::GREY, 0xF0F0F0F0);

    // Draw temp cell placement
    worldToScreen(cursor, sx, sy);
    FillRect({ sx, sy }, { (int)scale, (int)scale }, { 255, 51, 255 });

    // Draw cursor string position
    DrawString(10, 10, "X=" + std::to_string(cursor.x) + ", Y=" + std::to_string(cursor.y), olc::YELLOW, 2);

    return true;
}