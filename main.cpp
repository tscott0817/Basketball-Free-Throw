#include "gameObjects/primitives/circle.h"
#include "gameObjects/primitives/rect.h"
#include "gameObjects/prefabsComplex/prefabsComplex.h"
#include "gameObjects/prefabsSimple/prefabsSimple.h"
#include "gameObjects/menu/menu.h"
#include "ballController.h"
#include "scoreTracker.h"
#include "inputManager.h"
#include "main.h"
#include "gameObjects/primitives/shape.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//region Fields/Variables
GLdouble width, height;
int wd;

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
const color buttonColor(.75, .75, .75, .5);
const color menuBackground(0, 0, 0, .25);
const color blackBackground(.8, .5, 0, .5);

// If player can currently shoot
bool shooting;

// Keybind bools
bool mouseOneHeld;

// Used to iterate through vector of basketballs
int shotCountDown;

// Increment shoot velocity
double shootPower;

// For visual of charging power
Circle shotCharge;

// To set radius of charging circle
double chargeShot;
double colorIterator;

// Main Systems
Menu mainMenuInterface;

PrefabsComplex scene;

BallController basketballController;

ScoreTracker trackScore;

InputManager manageInput;
vector<InputManager> scoresVector;

// For hoop interaction with basketballs
Rect hoop;

// Screens
bool titleScreenActive;
bool mainMenuActive;
bool gameScreenActive;
bool gameOver;
bool hsScreenActive;

bool displayScore;

// For game loop timer
const int MAX_TIME = 30;
int timeLimit;
bool timeCountDown;

// Holds username
string inputString;

//endregion

//region Initializations

// Reads in from .csv file
void initInputManager() {
    getHighScores("scores.csv", scoresVector);
    //manageInput.setUsername("Tyler");

}

//  TODO: probably put this in ballController
void initShotCharge() {
    shotCharge.setCenter(0, 0);
    shotCharge.setRadius(0);
    shotCharge.setColor(purple);
}

void initBackgroundObjects() {
    scene.outdoorScene(640, 360);
}

// Hoop gets passed to score tracker to see if ball passes
void initForegroundObjects () {

    // get hoop center x values and add point if ball center equals any of those values
    scene.outdoorSceneForeground(640, 360);
    // TODO: Separate into foreground class, remember hoop needs passed into the

    hoop.setCenter(1050, 330);
    hoop.setSize(100, 10);
    hoop.setColor(orange);
    hoop.draw();

}

void init() {
    srand(time(0));
    width = 1280;
    height = 720;

    // Shooting
    shooting = false;
    mouseOneHeld = false;
    titleScreenActive = true;
    mainMenuActive = false;
    gameScreenActive = false;
    gameOver = false;
    hsScreenActive = false;
    timeCountDown = false;
    displayScore = false;

    // Power charger and visual
    shootPower = 0;
    chargeShot = 0;
    colorIterator = 0;
    timeLimit = MAX_TIME;

    // Inputs
    inputString = "";

    // Add basketballs to scene (Must be BEFORE shotCountDown)
    basketballController.addBalls(5);

    // This should be size of the vector that holds basketballs
    shotCountDown = basketballController.getBallVector().size();

    initShotCharge();

    initInputManager();

}

void initGL() {
    glClearColor(0.0f, .3f, 0.4f, 1.0f);
    //scene.outdoorScene(640, 360);
}


void menuObjects() {
    mainMenuInterface.draw();
}
//endregion

// region Screens
void drawInput() {
    // Displays text being typed
    // TODO: Put in input manager
    glColor3f(1, 1, 1);
    glScalef(2, 2, 2);
    glTranslatef(-820, -215, 0);
    for (int i = 0; i < 10; i++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, inputString[i]);
    }
}

void titleScreen() {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


    // TODO: Separate out into class (rect and for loop)
    Rect nameTest;
    nameTest.setCenter(640, 320);
    nameTest.setSize(425, 100);
    nameTest.setColor(menuBackground);
    nameTest.draw();

    glColor3f(1, 1, 1);
    glScalef(.2, -.2, .2);
    glTranslatef(2400, -1250, 0);
    string inputText = "Please Enter Your Name";
    for (const char &letter : inputText) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, letter);
    }

    drawInput();

    glFlush();
}

void mainMenu() {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //initBackgroundObjects();
    menuObjects();

    glColor3f(1, 1, 1);
    glScalef(.25, -.25, .25);
    glTranslatef(1750, -2000, 0);

    for (const char &letter : "Current User: ") {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, letter);
    }

    // Prints username
    for (const char &letter : inputString) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, letter);
    }


    glFlush();
}

void gameScreen() {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Scene background layer: DRAW FIRST
    initBackgroundObjects();

    if (shotCountDown > 0) {
        basketballController.drawBall();
    }

    // Scene Foreground layer: DRAW AFTER MOVING OBJECTS
    initForegroundObjects();

    shotCharge.draw();

    // Draw score on top of everything
    trackScore.displayScore();

    // Display time countdown
    glScalef(1.0, 1.0, 1.0);
    glTranslatef(935, -10, 0);
    for (const char &currentTime : to_string(timeLimit)) {

        glutStrokeCharacter(GLUT_STROKE_ROMAN, currentTime);
    }

    glFlush();
}

void gameOverScreen() {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // TODO: Change to current level choice
    initBackgroundObjects();
    //initForegroundObjects();

    Rect nameTest;
    nameTest.setCenter(640, 530);
    nameTest.setSize(1500, 100);
    nameTest.setColor(menuBackground);
    nameTest.draw();

    // Game over text
    glColor3f(1, 1, 1);
    glScalef(.2, -.2, .2);
    glTranslatef(500, -2700, 0);
    string gameOver = "Game Over. Press ENTER to play again or ESCAPE to go back to the main menu.";
    for (const char &letter : gameOver) {

        glutStrokeCharacter(GLUT_STROKE_ROMAN, letter);
    }

    glFlush();
}

void highScores() {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3f(1, 1, 1);
    glScalef(.5, -.5, .5);
    glTranslatef(1000, -300, 0);
    for (int i = 0; i < scoresVector.size(); i++) {

        for (const char &usName : scoresVector[i].getUsername()) {

            glutStrokeCharacter(GLUT_STROKE_ROMAN, usName);
        }

        for (const char &score : scoresVector[i].getScore()) {

            glutStrokeCharacter(GLUT_STROKE_ROMAN, score);
        }

        glTranslatef(-500, -200, 0);
    }

    glFlush();
}
//endregion

//region Keyboard/Mouse
// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {


    if (key == 27 && (hsScreenActive || gameOver)) {

        mainMenuActive = true;
        gameScreenActive = false;
        gameOver = false;
        hsScreenActive = false;
        glutDisplayFunc(mainMenu);
    }

    // Goes to mainMenu from titleScreen
    if (key == 13 && titleScreenActive) {
        mainMenuActive = true;
        titleScreenActive = false;
        gameScreenActive = false;
        gameOver = false;
        hsScreenActive = false;
        glutDisplayFunc(mainMenu);
    }

    else if (key == 13 && gameOver) {
        mainMenuActive = false;
        titleScreenActive = false;
        gameScreenActive = true;
        gameOver = false;
        hsScreenActive = false;

        timeCountDown = true;
        glutDisplayFunc(gameScreen);
    }

    // Get range of letters on keyboard (case sensitive) and add key char to string
    if ((key >= 65 && key <= 90 ) || (key >= 97 && key <= 122) && titleScreenActive) {
        inputString.push_back(key);
    }

    glutPostRedisplay();
}

void kbdUp(unsigned char key, int x, int y) {

    glutPostRedisplay();
}

void cursor(int x, int y) {

    if (mainMenuInterface.isOverlappingOne(x, y)) {
        mainMenuInterface.hoverOne();
    }
    else if (mainMenuInterface.isOverlappingTwo(x, y)) {
        mainMenuInterface.hoverTwo();
    }
    else if (mainMenuInterface.isOverlappingThree(x, y)) {
        mainMenuInterface.hoverThree();
    }
    else if (mainMenuInterface.isOverlappingFour(x, y)) {
        mainMenuInterface.hoverFour();
    }
    else {
        mainMenuInterface.release();
    }

    shotCharge.setCenter(x, y);

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameScreenActive) {
        shotCountDown -= 1;
        mouseOneHeld = true;
    }

    // Starts game with current level
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainMenuInterface.isOverlappingOne(x, y) && mainMenuInterface.getCanOpen()) {

        // Will change with booleans or string based on current level choice
        titleScreenActive = false;
        mainMenuActive = false;
        gameScreenActive = true;
        hsScreenActive = false;

        // Starts game timer
        timeCountDown = true;

        glutDisplayFunc(gameScreen);

    }

    // Changes Level
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainMenuActive && mainMenuInterface.isOverlappingTwo(x, y) && mainMenuInterface.getCanOpen()) {

        // Logic to change level
    }

    // Opens high scores menu
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainMenuActive && mainMenuInterface.isOverlappingThree(x, y) && mainMenuInterface.getCanOpen()) {

        titleScreenActive = false;
        mainMenuActive = false;
        gameScreenActive = false;
        hsScreenActive = true;
        displayScore = true;

        glutDisplayFunc(highScores);
    }

    // Exits program
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mainMenuActive && mainMenuInterface.isOverlappingFour(x, y) && mainMenuInterface.getCanOpen()) {

        glutDestroyWindow(wd);
        exit(0);


    }

    // Resets params after each shot
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && gameScreenActive) {
        //shotCountDown -= 1;
        basketballController.powerShot(shotCountDown, shootPower);
        mouseOneHeld = false;
        shooting = true;

        // Reset shoot power
        shootPower = 0;

        // Reset shot charge and visual
        shotCharge.setRadius(0);
        chargeShot = 0;
        colorIterator = 0;
    }
    glutPostRedisplay();
}
//endregion

// region Timers
void timer(int dummy) {

    // Sets score based on ball controller and hoop
    trackScore.trackScore(basketballController, hoop);

    if (mouseOneHeld) {

        // Increments shot velocity and charging visual
        shootPower += .03;
        chargeShot += 2;
        colorIterator += 8;
        shotCharge.setRadius(chargeShot);

        // Lowers green value while raising red value
        shotCharge.setColor(0 + (colorIterator/255.0), 1 - ((colorIterator/255.0) - .6), 0, 1);

        // Caps upper limit of power and charging circle size
        if (shootPower >= 1.2) {
            shootPower = 1.2;
            shotCharge.setRadius(80);
        }
    }

    if (shooting) {
        basketballController.ballPhysics();
    }

    basketballController.ballCollision();

    // Adds new balls to vector when empty
    if (shotCountDown <= 0) {
        basketballController.emptyBallVector();
        basketballController.addBalls(5);
        shotCountDown = basketballController.getBallVector().size();
    }

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

// One second loop
void gameTimer(int dummy) {

    // Iterates for time display on screen
    if (timeCountDown) {
        timeLimit -= 1;
    }

    // When time limit is up reset game parameters
    if (timeLimit == 0) {

        timeCountDown = false;
        titleScreenActive = false;
        mainMenuActive = false;
        gameScreenActive = false;
        gameOver = true;
        hsScreenActive = false;
        displayScore = false;

        // Reset time limit
        timeLimit = MAX_TIME;

        // Adds username and score to file after each round
        manageInput.addScoresToFile(inputString, trackScore.getScore());
        getHighScores("scores.csv", scoresVector);

        // Reset points
        trackScore.resetScore();

        // Reset ball vector
        basketballController.emptyBallVector();
        basketballController.addBalls(5);

        // Reset shot counter
        shotCountDown = basketballController.getBallVector().size();

        // Change to game over screen
        glutDisplayFunc(gameOverScreen);
    }

    // Call every second
    glutPostRedisplay();
    glutTimerFunc(1000, gameTimer, dummy);
}
//endregion

int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(300, 150);
    wd = glutCreateWindow("Free Throw");

    initGL();

    // Start game at title screen
    glutDisplayFunc(titleScreen);

    glutKeyboardFunc(kbd);
    glutKeyboardUpFunc(kbdUp);

    glutPassiveMotionFunc(cursor);

    glutMouseFunc(mouse);

    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, gameTimer, 0);

    glutMainLoop();
    return 0;
}
