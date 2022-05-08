#ifndef M4OEP_GRAPHICS_TSCOTT5_PREFABSCOMPLEX_H
#define M4OEP_GRAPHICS_TSCOTT5_PREFABSCOMPLEX_H

#include "../prefabsSimple/prefabsSimple.h"
#include "../primitives/shape.h"
#include "../../main.h"
#include "../primitives/circle.h"
#include "../primitives/rect.h"
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>

class PrefabsComplex {
private:
    int x;
    int y;
public:
    /* Constructors */
    PrefabsComplex();

    void house(int x, int y);
    void houseTwo(int x, int y);

    void outdoorScene(int x, int y);
    void outdoorSceneForeground(int x, int y);
    virtual ~PrefabsComplex() = default;

};

#endif //M4OEP_GRAPHICS_TSCOTT5_PREFABSCOMPLEX_H
