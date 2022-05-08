#include "prefabsSimple.h"
#include <memory>
#include <vector>

const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 110/255.0, 214/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0);
const color grey(.4,.4,.4);
const color magenta(1, 0, 1);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);
const color lightWood (171/255.0, 117/255.0, 57/255.0);
const color darkYellow(90/255.0, 100/255.0, 110/255.0);

PrefabsSimple::PrefabsSimple() {

}

//region Environment

void PrefabsSimple::ground(int x, int y, double height, double width, color color) {
    Rect grass;
    grass.setCenter(x, y);
    grass.setSize(width, height/3);
    grass.setColor(color);
    grass.draw();
}

void PrefabsSimple::groundDetailsCircle(int x, int y, double radius, color color) {
    Circle groundDetail;
    groundDetail.setCenter(x, y);
    groundDetail.setRadius(radius);
    groundDetail.setColor(color);
    groundDetail.draw();
}

void PrefabsSimple::sky(int x, int y, double height, double width, color color) {
    Rect grass;
    grass.setCenter(x, y);
    grass.setSize(width, height);
    grass.setColor(color);
    grass.draw();
}

void PrefabsSimple::clouds(std::vector<std::unique_ptr<Shape>> clouds) {
    clouds.clear();
    dimensions cloudBottom(30, 30);
    // First cloud
    clouds.push_back(std::make_unique<Circle>(white, 300, 100, 20));
    clouds.push_back(std::make_unique<Circle>(white, 330, 100, 20));
    clouds.push_back(std::make_unique<Circle>(white, 320, 90, 20));
    clouds.push_back(std::make_unique<Rect>(white, 315, 105, cloudBottom));
    // Second cloud
    clouds.push_back(std::make_unique<Circle>(white, 100, 80, 20));
    clouds.push_back(std::make_unique<Circle>(white, 130, 80, 20));
    clouds.push_back(std::make_unique<Circle>(white, 120, 70, 20));
    clouds.push_back(std::make_unique<Rect>(white, 115, 85, cloudBottom));
    // Third cloud
    clouds.push_back(std::make_unique<Circle>(white, 450, 50, 20));
    clouds.push_back(std::make_unique<Circle>(white, 480, 50, 20));
    clouds.push_back(std::make_unique<Circle>(white, 470, 40, 20));
    clouds.push_back(std::make_unique<Rect>(white, 465, 55, cloudBottom));

    // Fourth cloud
    clouds.push_back(std::make_unique<Circle>(white, 1200, 50, 20));
    clouds.push_back(std::make_unique<Circle>(white, 1230, 50, 20));
    clouds.push_back(std::make_unique<Circle>(white, 1220, 40, 20));
    clouds.push_back(std::make_unique<Rect>(white, 1215, 55, cloudBottom));

    // Fifth cloud
    clouds.push_back(std::make_unique<Circle>(white, 915, 175, 20));
    clouds.push_back(std::make_unique<Circle>(white, 945, 175, 20));
    clouds.push_back(std::make_unique<Circle>(white, 935, 165, 20));
    clouds.push_back(std::make_unique<Rect>(white, 930, 180, cloudBottom));

    // Sixth cloud
    clouds.push_back(std::make_unique<Circle>(white, 620, 100, 20));
    clouds.push_back(std::make_unique<Circle>(white, 650, 100, 20));
    clouds.push_back(std::make_unique<Circle>(white, 640, 90, 20));
    clouds.push_back(std::make_unique<Rect>(white, 635, 105, cloudBottom));

    for (std::unique_ptr<Shape> &s : clouds) {
        // #polymorphism
        s->draw();
    }
}

void PrefabsSimple::treePine(int x, int y, double height, double width, color bark, color leaves) {

    std::vector<std::unique_ptr<Shape>> tree;

    tree.clear();
    dimensions treeBark;
    triangleDimensions leavesOne;

    // Tree base
    treeBark.height = height;
    treeBark.width = width;
    tree.push_back(std::make_unique<Rect>(bark, x, y, treeBark));

    // Leaves
    leavesOne.height = height + 100;
    leavesOne.base = width + 250;
    tree.push_back(std::make_unique<Triangle>(leaves, x, y, leavesOne));

    for (std::unique_ptr<Shape> &t : tree) {
        // #polymorphism
        t->draw();
    }
}


void PrefabsSimple::treePineTwo(int x, int y, double height, double width, color bark, color leaves) {

    std::vector<std::unique_ptr<Shape>> tree;

    tree.clear();
    dimensions treeBark;
    triangleDimensions leavesOne;
    triangleDimensions leavesTwo;
    triangleDimensions leavesThree;

    // Tree base
    treeBark.height = height - 100;
    treeBark.width = width;
    tree.push_back(std::make_unique<Rect>(bark, x, y, treeBark));

    // Leaves
    leavesOne.height = height;
    leavesOne.base = width + 250;
    tree.push_back(std::make_unique<Triangle>(leaves, x, y + 50, leavesOne));

    // Leaves
    leavesTwo.height = height;
    leavesTwo.base = width + 250;
    tree.push_back(std::make_unique<Triangle>(leaves, x, y, leavesTwo));

    // Leaves
    leavesThree.height = height;
    leavesThree.base = width + 250;
    tree.push_back(std::make_unique<Triangle>(leaves, x, y - 50, leavesThree));

    for (std::unique_ptr<Shape> &t : tree) {
        // #polymorphism
        t->draw();
    }
}
//endregion


//region Architecture
void PrefabsSimple::wall(int x, int y, double height, double width, color color) {

    dimensions wallSize;
    wallSize.height = height;
    wallSize.width = width;

    Rect wall(color, x, y, wallSize);

    wall.draw();
}

void PrefabsSimple::roof(int x, int y, double height, double width, color color) {

    std::vector<std::unique_ptr<Shape>> roof;

    roof.clear();
    triangleDimensions roofSize;
    roofSize.height = height;
    roofSize.base = width;

    roof.push_back(std::make_unique<Triangle>(color, x, y, roofSize));

    for (std::unique_ptr<Shape> &s : roof) {
        s->draw();
    }

}

void PrefabsSimple::door(int x, int y, double height, double width, color color) {

    dimensions doorSize;

    doorSize.height = height;
    doorSize.width = width;
    std::vector<std::unique_ptr<Shape>> door;

    doorSize.height = 100;
    doorSize.width = 60;
    door.push_back(std::make_unique<Rect>(lightWood, x , y, doorSize));

    // Handle
    door.push_back(std::make_unique<Circle>(darkYellow, x + 25, y + 10, 3));

    // Window
    door.push_back(std::make_unique<Circle>(darkYellow, x, y - 25, 15));
    door.push_back(std::make_unique<Circle>(skyBlue, x, y - 25, 12));

    for (std::unique_ptr<Shape> &d : door) {
        d->draw();
    }
}

/**
 * Creates a prefab for windows
 * @param x The x-coordinate
 * @param y The y-coordinate
 */
void PrefabsSimple::window(int x, int y, double height, double width, color glass, color frame) {

    std::vector<std::unique_ptr<Shape>> window;

    window.clear();
    dimensions windowFrameLeft;
    dimensions windowFrameTop;
    dimensions windowFrameRight;
    dimensions windowFrameBottom;
    dimensions windowFrameMiddleY;
    dimensions windowFrameMiddleX;
    dimensions windowGlass;

    // Glass
    windowGlass.height = height;
    windowGlass.width = width;
    window.push_back(std::make_unique<Rect>(glass, x, y, windowGlass));

    // Left Frame
    windowFrameLeft.height = 50;
    windowFrameLeft.width = 5;
    window.push_back(std::make_unique<Rect>(frame, x - 40 , y, windowFrameLeft));

    // Top Frame
    windowFrameTop.height = 5;
    windowFrameTop.width = 85;
    window.push_back(std::make_unique<Rect>(frame, x ,y - 25, windowFrameTop));

    // Right Frame
    windowFrameRight.height = 50;
    windowFrameRight.width = 5;
    window.push_back(std::make_unique<Rect>(frame, x + 40 , y, windowFrameRight));

    // Bottom Frame
    windowFrameBottom.height = 5;
    windowFrameBottom.width = 85;
    window.push_back(std::make_unique<Rect>(frame, x ,y + 25, windowFrameBottom));

    // MiddleY Frame
    windowFrameMiddleY.height = 50;
    windowFrameMiddleY.width = 5;
    window.push_back(std::make_unique<Rect>(frame, x , y, windowFrameMiddleY));

    // MiddleX Frame
    windowFrameMiddleX.height = 5;
    windowFrameMiddleX.width = 85;
    window.push_back(std::make_unique<Rect>(frame, x , y, windowFrameMiddleX));

    for (std::unique_ptr<Shape> &w : window) {
        // #polymorphism
        w->draw();
    }
}
//endregion

void PrefabsSimple::skyscraper(int x, int y) {

    std::vector<std::unique_ptr<Shape>> skyscraper;
    skyscraper.clear();
    dimensions base;

    base.height = 500;
    base.width = 400;
    skyscraper.push_back(std::make_unique<Rect>(grey,x,y,base));

    for (std::unique_ptr<Shape> &s : skyscraper) {

        s->draw();
    }
}

void PrefabsSimple::skyscraper(int x, int y, color wall, color windows) {

    std::vector<std::unique_ptr<Shape>> skyscraper;
    skyscraper.clear();
    dimensions base;
    dimensions window;

    base.height = 500;
    base.width = 600;
    skyscraper.push_back(std::make_unique<Rect>(wall,x,y,base));

    window.height = 100;
    window.width = 80;
    skyscraper.push_back(std::make_unique<Rect>(windows,x-200,y+100,window));
    skyscraper.push_back(std::make_unique<Rect>(darkYellow,x-200,y-50,window));
    skyscraper.push_back(std::make_unique<Rect>(windows,x,y+100,window));
    skyscraper.push_back(std::make_unique<Rect>(windows,x,y-50,window));
    skyscraper.push_back(std::make_unique<Rect>(windows,x+200,y+100,window));
    skyscraper.push_back(std::make_unique<Rect>(windows,x+200,y-50,window));



    for (std::unique_ptr<Shape> &s : skyscraper) {

        s->draw();
    }
}



