#include "pge/olcPixelGameEngine.h"

struct Cell {
    // Position in World Space
    olc::vf2d pos;
};

class GameOfLife : public olc::PixelGameEngine {
public:
    GameOfLife();

private:
    // Pan and zoom variables
    olc::vf2d offset = { 0, 0 };
    olc::vf2d startPan = { 0, 0 };
    olc::vf2d cursor = { 0, 0 };
    float scale = 1.0f;
    float grid = 1.0f;

    // List of cells existing in the world
    std::list<Cell*> cells;

    // Convert coordinates from World Space ---> Screen Space
    void worldToScreen(const olc::vf2d& v, int& screenX, int& screenY);

    // Convert coordinates from Screen Space ---> World Space
    void screenToWorld(int screenX, int screenY, olc::vf2d& v);

public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};