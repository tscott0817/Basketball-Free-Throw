#include "../prefabsSimple/prefabsSimple.h"
#include "prefabsComplex.h"
#include <memory>
#include <vector>

const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 110/255.0, 214/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0);
const color magenta(1, 0, 1);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);
const color lightWood (171/255.0, 117/255.0, 57/255.0);
const color greyBlue (84/255.0, 88/255.0, 102/255.0);
const color darkGreen (75/255.0, 111/255.0, 69/255.0);
const color outdoorCourt(.4,.4,.4);
const color blackBackground(0, 0, 0, .25);
const color buttonColor(.75, .75, .75, .5);
const color litWindow(254/255.0, 254/255.0, 100/255.0);
const color cement(150/255.0,140/255.0,135/255.0);
const color silver(180/255.0, 180/255.0, 180/255.0);
const color scoreboard(0,0,0,.4);

PrefabsComplex::PrefabsComplex() {

}

void PrefabsComplex::house(int x, int y) {

    // Wall Component (Base)
    PrefabsSimple wall;
    wall.wall(x, y, 250, 500, brickRed);

    // Roof Component
    PrefabsSimple roof;
    roof.roof(x, y - 118, 400, 550, darkBlue);

    // Door Component
    PrefabsSimple door;
    door.door(x, y + 70, 100, 50, lightWood);

    // Window Component
    PrefabsSimple windowTopLeft;
    windowTopLeft.window(x - 150, y - 50, 50, 80, cyan, lightWood);

    // Window Component
    PrefabsSimple windowTopRight;
    windowTopRight.window(x + 150, y - 50, 50, 80, cyan ,lightWood);

    // Window Component
    PrefabsSimple windowBottomLeft;
    windowBottomLeft.window(x - 150, y + 50, 50, 80, cyan ,lightWood);

    // Window Component
    PrefabsSimple windowBottomRight;
    windowBottomRight.window(x + 150, y + 50, 50, 80, cyan ,lightWood);


}

void PrefabsComplex::houseTwo(int x, int y) {

    // Wall Component (Base)
    PrefabsSimple wall;
    wall.wall(x, y, 200, 500, darkGreen);

    // Roof Component
    PrefabsSimple roof;
    roof.roof(x, y - 100, 300, 550, greyBlue);

    // Door Component
    PrefabsSimple door;
    door.door(x + 150, y + 45, 100, 50, lightWood);
    PrefabsSimple doorTwo;
    doorTwo.door(x - 150, y + 45, 100, 50, lightWood);

    // Window Component
    PrefabsSimple windowTopLeft;
    windowTopLeft.window(x, y - 25, 50, 80, cyan, lightWood);



}

void PrefabsComplex::outdoorScene(int x, int y) {

    PrefabsSimple sky;
    PrefabsSimple groundBase;
    PrefabsSimple court;
    PrefabsSimple groundCenterCircleOuter;
    PrefabsSimple groundCenterCircleInner;
    PrefabsSimple groundCenterLine;
    PrefabsSimple scoreBoard;
    PrefabsSimple skyscraper;
    PrefabsSimple trees;
    PrefabsSimple door;
    PrefabsSimple hoop;

    // Build Scene
    sky.sky(x, y, 720, 1280, skyBlue);
    groundBase.ground(x, y + 150, 1400, 1300, grassGreen);
    court.ground(x, y + 175, 950, 1100, outdoorCourt);
    trees.treePineTwo(20, 200, 350, 50, lightWood, grassGreen);
    trees.treePineTwo(700, 190, 300, 50, lightWood, darkGreen);
    trees.treePine(550, 150, 300, 50, lightWood, grassGreen);
    houseTwo(300, 275);
    groundCenterCircleOuter.groundDetailsCircle(x, y + 175, 75, white);
    groundCenterCircleOuter.groundDetailsCircle(x, y + 175, 70, outdoorCourt);
    groundCenterLine.ground(x, y + 175, 950, 5, white);
    skyscraper.skyscraper(1000, 50, cement, litWindow);
    door.door(x+260, y-120, 100, 50, lightWood);
    trees.treePineTwo(1230, 230, 400, 50, lightWood, grassGreen);
    hoop.wall(1050, 540, 25, 50, black);
    hoop.wall(1050, 400, 300, 30, black);
    hoop.wall(1050, 300, 100, 150, white);
    hoop.wall(1050, 295, 50, 90, orange);
    hoop.wall(1050, 295, 40, 80, white);
    scoreBoard.ground(x - 510, y - 260, 500, 200, scoreboard);
    scoreBoard.ground(x + 500, y - 260, 500, 200, scoreboard);
//    scoreboard.wall(640, 200, 200, 400, greyBlue);
//    scoreBoard.wall(590, 200, 180, 100, black);
//    scoreBoard.wall(690, 200, 180, 100, darkBlue);


}

void PrefabsComplex::outdoorSceneForeground(int x, int y) {

    PrefabsSimple ballHolder;
    ballHolder.wall(115, 535, 100, 10, silver);
    ballHolder.wall(380, 535, 100, 10, silver);
    ballHolder.wall(250, 555, 10, 270, silver);
    ballHolder.wall(250, 500, 10, 270, silver);



}
