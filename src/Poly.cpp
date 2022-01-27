#include "Poly.h"

// Implementation of static variables
olc::vf2d Shape::worldOffset = { 0, 0 };
float Shape::worldScale = 1.0f;

void Shape::worldToScreen(const olc::vf2d& v, int& screenX, int& screenY) {
    screenX = (int)((v.x - worldOffset.x) * worldScale);
    screenY = (int)((v.y - worldOffset.y) * worldScale);
}

Node* Shape::getNextNode(const olc::vf2d& p) {
    if (nodes.size() == maxNodes) {
        return nullptr; // Shape complete
    }

    Node n;
    n.pos = p;
    n.parent = this;
    nodes.push_back(n);

    // Beware this is bad! - see sub classes (change this)
    return &nodes[nodes.size() - 1];
}

Node* Shape::hitNode(const olc::vf2d& p) {
    for (auto& node : nodes) {
        if ((p - node.pos).mag() < 0.01f)
            return &node;
    }

    return nullptr;
}

void Shape::drawNodes(olc::PixelGameEngine* pge) {
    for (auto &n : nodes) {
        int sx, sy;
        worldToScreen(n.pos, sx, sy);
        pge->FillCircle(sx, sy, 2, olc::RED);
    }
}

Line::Line() {
    maxNodes = 2;
    nodes.reserve(maxNodes);
}

void Line::drawYourself(olc::PixelGameEngine* pge) {
    int sx, sy, ex, ey;
    worldToScreen(nodes[0].pos, sx, sy);
    worldToScreen(nodes[1].pos, ex, ey);
    pge->DrawLine(sx, sy, ex, ey, color);
}

Box::Box() {
    maxNodes = 2;
    nodes.reserve(maxNodes); 
}

void Box::drawYourself(olc::PixelGameEngine* pge) {
    int sx, sy, ex, ey;
    worldToScreen(nodes[0].pos, sx, sy);
    worldToScreen(nodes[1].pos, ex, ey);
    pge->DrawRect(sx, sy, ex - sx, ey - sy, color);
}

Circle::Circle() {
    maxNodes = 2;
    nodes.reserve(maxNodes);
}

void Circle::drawYourself(olc::PixelGameEngine* pge) {
    float fRadius = (nodes[0].pos - nodes[1].pos).mag();
    int sx, sy, ex, ey;
    worldToScreen(nodes[0].pos, sx, sy);
    worldToScreen(nodes[1].pos, ex, ey);
    pge->DrawLine(sx, sy, ex, ey, color, 0xFF00FF00);

    // Note the radius is also scaled so it is drawn appropriately
    pge->DrawCircle(sx, sy, (int32_t)(fRadius * worldScale), color);
}

Curve::Curve() {
    maxNodes = 3;
    nodes.reserve(maxNodes);
}

void Curve::drawYourself(olc::PixelGameEngine* pge) {
    int sx, sy, ex, ey;

    if (nodes.size() < 3) {
        // only draw line from first to second node
        worldToScreen(nodes[0].pos, sx, sy);
        worldToScreen(nodes[1].pos, ex, ey);
        pge->DrawLine(sx, sy, ex, ey, color, 0xFF00FF00);
    }

    if (nodes.size() == 3) {
        // draw line from first to second node
        worldToScreen(nodes[0].pos, sx, sy);
        worldToScreen(nodes[1].pos, ex, ey);
        pge->DrawLine(sx, sy, ex, ey, color, 0xFF00FF00);

        // draw line from second to third node
        worldToScreen(nodes[1].pos, sx, sy);
        worldToScreen(nodes[2].pos, ex, ey);
        pge->DrawLine(sx, sy, ex, ey, color, 0xFF00FF00);

        // Bezier curve
        olc::vf2d op = nodes[0].pos;
        olc::vf2d np = op;
        for (float t = 0; t < 1.0f; t += 0.01f) {
            np = (1 - t) * (1 - t) * nodes[0].pos + 2 * (1 - t) * t * nodes[1].pos + t * t * nodes[2].pos;
            worldToScreen(op, sx, sy);
            worldToScreen(np, ex, ey);
            pge->DrawLine(sx, sy, ex, ey, color);
            op = np;
        }
    }
}

Poly::Poly() {
    sAppName = "Polymorphism";
}

void Poly::worldToScreen(const olc::vf2d& v, int& screenX, int& screenY) {
    screenX = (int)((v.x - offset.x) * scale);
    screenY = (int)((v.y - offset.y) * scale);
}

void Poly::screenToWorld(int screenX, int screenY, olc::vf2d& v) {
    v.x = (float) screenX / scale + offset.x;
    v.y = (float) screenY / scale + offset.y;
}

bool Poly::OnUserCreate()  {
    // Configure world space to (0, 0) in middle of screen
    offset = { (float)(-ScreenWidth() / 2) / scale, (float)(-ScreenHeight() / 2) / scale };
    return true;
}

bool Poly::OnUserUpdate(float fElapsedTime) {
    // Get mouse location of this frame
    olc::vf2d mouse = { (float)GetMouseX(), (float)GetMouseY() };

    // Handle Pan and Zoom
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

    // Snap cursor to nearest grid interval
    cursor.x = floorf((mouseAfterZoom.x + 0.5f) * grid);
    cursor.y = floorf((mouseAfterZoom.y + 0.5f) * grid);

    // Handle Shape generation
    if (GetKey(olc::Key::L).bPressed) {
        tempShape = new Line();

        // Add first node at cursor location
        selectedNode = tempShape->getNextNode(cursor);

        // Get second node for editing
        selectedNode = tempShape->getNextNode(cursor);
    }

    if (GetKey(olc::Key::B).bPressed) {
        tempShape = new Box();

        // Add first node at cursor location
        selectedNode = tempShape->getNextNode(cursor);

        // Get second node for editing
        selectedNode = tempShape->getNextNode(cursor);
    }

    if (GetKey(olc::Key::C).bPressed) {
        tempShape = new Circle();

        // Add first node at cursor location
        selectedNode = tempShape->getNextNode(cursor);

        // Get second node for editing
        selectedNode = tempShape->getNextNode(cursor);
    }

    if (GetKey(olc::Key::S).bPressed) {
        tempShape = new Curve();

        // Add first node at cursor location
        selectedNode = tempShape->getNextNode(cursor);

        // Get second node for editing
        selectedNode = tempShape->getNextNode(cursor);
    }

    if (GetKey(olc::Key::M).bPressed) {
        selectedNode = nullptr;
        for (auto& shape : shapes) {
            selectedNode = shape->hitNode(cursor);
            if (selectedNode != nullptr)
                break;
        }
    }

    // If a node is selected make it follow cursor
    if (selectedNode != nullptr) {
        selectedNode->pos = cursor;
    }

    // When user releases mouse click check if shape finished or
    // if next node is needed
    if (GetMouse(0).bReleased) {
        if (tempShape != nullptr) {
            selectedNode = tempShape->getNextNode(cursor);
            if (selectedNode == nullptr) {
                tempShape->color = olc::WHITE;
                shapes.push_back(tempShape);
                tempShape = nullptr;
            }
        } else {
            selectedNode = nullptr;
        }
    }

    // Start Drawing
    Clear(olc::BLACK);

    int sx, sy, ex, ey;

    // Get Visible world
    olc::vf2d worldTopLeft, worldBottomRight;
    screenToWorld(0, 0, worldTopLeft);
    screenToWorld(ScreenWidth(), ScreenHeight(), worldBottomRight);

    // Set values to just beyond screen boundaries
    worldTopLeft.x = floorf(worldTopLeft.x);
    worldTopLeft.y = floorf(worldTopLeft.y);
    worldBottomRight.x = ceilf(worldBottomRight.x);
    worldBottomRight.y = ceilf(worldBottomRight.y);

    // Draw Grid Dots of world
    for (float x = worldTopLeft.x; x < worldBottomRight.x; x += grid) {
        for (float y = worldTopLeft.y; y < worldBottomRight.y; y += grid) {
            worldToScreen({ x, y }, sx, sy);
            Draw(sx, sy, olc::BLUE);
        }
    }

    // Draw World Axis
    worldToScreen({ 0, worldTopLeft.y }, sx, sy);
    worldToScreen({ 0, worldBottomRight.y }, ex, ey);
    DrawLine(sx, sy, ex, ey, olc::GREY, 0xF0F0F0F0);
    worldToScreen({ worldTopLeft.x, 0 }, sx, sy);
    worldToScreen({ worldBottomRight.x, 0 }, ex, ey);
    DrawLine(sx, sy, ex, ey, olc::GREY, 0xF0F0F0F0);

    // Update world translation coefficients
    Shape::worldOffset = offset;
    Shape::worldScale = scale;

    // Draw all finished shapes
    for (auto& shape : shapes) {
        shape->drawYourself(this);
        shape->drawNodes(this);
    }

    // Draw shape currently being added
    if (tempShape != nullptr) {
        tempShape->drawYourself(this);
        tempShape->drawNodes(this);
    }

    // Draw snapped cursor
    worldToScreen(cursor, sx, sy);
    DrawCircle(sx, sy, 3, olc::YELLOW);

    // Draw cursor position
    DrawString(10, 10, "X=" + std::to_string(cursor.x) + ", Y=" + std::to_string(cursor.y), olc::YELLOW, 2);
    
    return true;
}