#include "menu.h"
#include <vector>
#include <memory>
using namespace std;

// Menu Colors
const color blackBackground(0, 0, 0, .25);
const color buttonColor(.75, .75, .75, .5);
const color enviroGreen(95/255.0, 183/255.0, 62/255.0, .75);
const color exitRed(203/255.0, 104/255.0, 54/255.0, .75);

// Object colors
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

bool menuOpen = true;

//region Menu initialization
Menu::Menu() : Rect() {

    // Menu text
    this->label = "Basketball Free Throw";
    this->labelTwo = "Play Game";
    this->labelThree = "Choose Level";
    this->labelFour = "High Score";
    this->labelFive = "Exit";

    // Menu component sizes
    dimensions background;
    dimensions buttonDim;
    dimensions buttonExit;

    // Add UI elements to vector
    background.height = 480;
    background.width = 720;
    ui.push_back(Rect(blackBackground, 640, 340, background));

    buttonDim.height = 50;
    buttonDim.width = 240;
    ui.push_back(Rect(buttonColor, 640, 215, buttonDim));

    buttonDim.height = 50;
    buttonDim.width = 240;
    ui.push_back(Rect(buttonColor, 640, 275, buttonDim));

    buttonDim.height = 50;
    buttonDim.width = 240;
    ui.push_back(Rect(buttonColor, 640, 335, buttonDim));

    buttonDim.height = 50;
    buttonDim.width = 240;
    ui.push_back(Rect(buttonColor, 640, 395, buttonDim));



}


void Menu::draw() const {

    for (Rect r : ui) {

        r.draw();
    }

    // Prints text to buttons given that menu is open
    if (menuOpen) {

        glColor3f(1, 1, 1);
        // Center text on ui elements
        glRasterPos2i(ui[0].getLeftX() + 250, ui[0].getTopY() + 60);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }

        glColor3f(0, 0, 0);
        glRasterPos2i((ui[1].getLeftX() + 120) - (4 * labelTwo.length()), ui[1].getTopY() + 25);
        for (const char &letter : labelTwo) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(0, 0, 0);
        glRasterPos2i((ui[2].getLeftX() + 120) - (4 * labelTwo.length()), ui[2].getTopY() + 25);
        for (const char &letter : labelThree) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(0, 0, 0);
        glRasterPos2i((ui[3].getLeftX() + 120) - (4 * labelTwo.length()), ui[3].getTopY() + 25);
        for (const char &letter : labelFour) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(0, 0, 0);
        glRasterPos2i((ui[4].getLeftX() + 120) - (4 * labelTwo.length()), ui[4].getTopY() + 25);
        for (const char &letter : labelFive) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }
}
//endregion

//region Getters/Setters
bool Menu::getCanOpen() {
    return menuOpen;
}

std::vector<Rect> Menu::getMenu() const {
    return ui;
}

// Setters
void Menu::setCanOpen(bool open) {
    menuOpen = open;
}
//endregion

//region Controllers
void Menu::openMenu() {
    menuOpen = true;
    ui[0].setColor(blackBackground);
    ui[1].setColor(buttonColor);
    ui[2].setColor(buttonColor);
    ui[3].setColor(buttonColor);
    ui[4].setColor(buttonColor);
    ui[5].setColor(buttonColor);
    ui[6].setColor(buttonColor);
    ui[7].setColor(buttonColor);
    ui[8].setColor(buttonColor);
    ui[9].setColor(buttonColor);
    ui[10].setColor(buttonColor);
    ui[11].setColor(buttonColor);

}

void Menu::closeMenu() {
    menuOpen = false;
    for (int i = 0; i < ui.size(); i++) {
        ui[i].setColor(0, 0, 0, 0);
    }
}


bool Menu::isOverlappingOne(int x, int y) const {

    if (y > ui[1].getTopY() && y < ui[1].getBottomY() && x > ui[1].getLeftX() && x < ui[1].getRightX()){
        return true;
    }
    else {
        return false;
    }
}

bool Menu::isOverlappingTwo(int x, int y) const {

    if (y > ui[2].getTopY() && y < ui[2].getBottomY() && x > ui[2].getLeftX() && x < ui[2].getRightX()){
        return true;
    }
    else {
        return false;
    }
}
bool Menu::isOverlappingThree(int x, int y) const {

    if (y > ui[3].getTopY() && y < ui[3].getBottomY() && x > ui[3].getLeftX() && x < ui[3].getRightX()){
        return true;
    }
    else {
        return false;
    }
}
bool Menu::isOverlappingFour(int x, int y) const {

    if (y > ui[4].getTopY() && y < ui[4].getBottomY() && x > ui[4].getLeftX() && x < ui[4].getRightX()){
        return true;
    }
    else {
        return false;
    }
}

void Menu::hoverOne() {
    if (menuOpen) {
        ui[1].setColor(enviroGreen);
    }
}

void Menu::hoverTwo() {
    if (menuOpen) {
        ui[2].setColor(enviroGreen);
    }
}

void Menu::hoverThree() {
    if (menuOpen) {
        ui[3].setColor(enviroGreen);
    }
}

void Menu::hoverFour() {
    if (menuOpen) {
        ui[4].setColor(enviroGreen);
    }
}

void Menu::clickOne() {
    if (menuOpen) {
        ui[1].setColor(exitRed);
    }
}

void Menu::clickTwo() {
    if (menuOpen) {
        ui[2].setColor(exitRed);
    }
}

void Menu::clickThree() {
    if (menuOpen) {
        ui[3].setColor(exitRed);
    }
}

void Menu::clickFour() {
    if (menuOpen) {
        ui[4].setColor(exitRed);
    }
}

void Menu::release() {
    if (menuOpen) {
        ui[1].setColor(buttonColor);
        ui[2].setColor(buttonColor);
        ui[3].setColor(buttonColor);
        ui[4].setColor(buttonColor);
    }
}
//endregion