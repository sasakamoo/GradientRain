#include "pge/olcPixelGameEngine.h"

struct Shape;

struct Node {
    olc::vf2d pos;
    Shape* parent;
};

struct Shape {
    // Each shape has a dynamic number of nodes
    std::vector<Node> nodes;
    uint32_t maxNodes = 0;

    // Colour of shape
    olc::Pixel color = olc::GREEN;

    // All shapes share screen transformation coefficients, 
    // try to get them out of this class?
    static olc::vf2d worldOffset;
    static float worldScale;

    // Convert vf2d coords from World Space ---> Screen Space
    void worldToScreen(const olc::vf2d& v, int& screenX, int& screenY);

    // Pure virtual function 
    virtual void drawYourself(olc::PixelGameEngine *pge) = 0;

    // add node to shape at point p 
    Node* getNextNode(const olc::vf2d& p);

    // Test if supplied coordinate hits this shapes nodes
    Node* hitNode(const olc::vf2d& p);

    // draw nodes of this shape
    void drawNodes(olc::PixelGameEngine* pge);
};

// Line subclass, implements drawYourself
struct Line : public Shape {
    Line();
    void drawYourself(olc::PixelGameEngine* pge) override;
};

// Box subclass, implements drawYourself
struct Box : public Shape {
    Box();
    void drawYourself(olc::PixelGameEngine* pge) override;
};

// Circle subclass, implements drawYourself
struct Circle : public Shape {
    Circle();
    void drawYourself(olc::PixelGameEngine* pge) override;
};

// Bezier Spline
struct Curve : public Shape {
    Curve();
    void drawYourself(olc::PixelGameEngine* pge) override;
};

// Application
class Poly : public olc::PixelGameEngine {
public:
    Poly();

private:
    // Pan and zoom variables
    olc::vf2d offset = { 0, 0 };
    olc::vf2d startPan = { 0, 0 };
    olc::vf2d cursor = { 0, 0 };
    float scale = 10.0f;
    float grid = 1.0f;

    // pointer to shape currently defined by placement of nodes
    Shape* tempShape = nullptr;

    // pointer to node currently selected
    Node* selectedNode = nullptr;

    // list shape pointers which have been added
    std::list<Shape*> shapes;

    // Convert coordinate from World Space ---> Screen Space
    void worldToScreen(const olc::vf2d& v, int& screenX, int& screenY);

    // Convert coordinate from Screen Space ---> World Space
    void screenToWorld(int screenX, int screenY, olc::vf2d& v);

public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};