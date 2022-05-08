#ifndef M4OEP_GRAPHICS_TSCOTT5_PREFABS_H
#define M4OEP_GRAPHICS_TSCOTT5_PREFABS_H
#include "../primitives/shape.h"
#include "../../main.h"
#include "../primitives/circle.h"
#include "../primitives/rect.h"
#include "../primitives/triangle.h"
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>

class PrefabsSimple {

private:

public:

    PrefabsSimple();

    void ground(int x, int y, double height, double width, color color);
    void sky(int x, int y, double height, double width, color color);
    void clouds(std::vector<std::unique_ptr<Shape>> clouds);
    //void cloudTimer(int dummy);
    void wall(int x, int y, double height, double width, color color);
    void roof(int x, int y, double height, double width, color color);
    void door(int x, int y, double height, double width, color color);
    void window(int x, int y, double height, double width, color glass, color frame);
    void treePine(int x, int y, double height, double width, color bark, color leaves);
    void treePineTwo(int x, int y, double height, double width, color bark, color leaves);

    // For outdoor scene
    void groundDetailsCircle(int x, int y, double radius, color color);
    void skyscraper(int x, int y);
    void skyscraper(int x, int y, color wall, color windows);

    /* Destructor */
    virtual ~PrefabsSimple() = default;
};

#endif //M4OEP_GRAPHICS_TSCOTT5_PREFABS_H
