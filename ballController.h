#ifndef FINAL_PROJECT_TSCOTT5_BALLCONTROLLER_H
#define FINAL_PROJECT_TSCOTT5_BALLCONTROLLER_H

#include <vector>
#include "gameObjects/primitives/circle.h"
#include "main.h"

class BallController {
private:
    std::vector<Circle> basketballs;
    GLdouble width = 1280, height = 720;
    int wd;
    bool canScore;
public:

    BallController();

    // Initialize basketballs
    void addBalls(int numBasketballs);
    void emptyBallVector();
    void addBallBack();
    void drawBall();

    // Getters
    std::vector<Circle>  getBallVector();

    // Setters
    void setBallVelocity(int vel);

    // Interactions
    void shoot(int ballNumber);
    void powerShot(int ballNumber, double velMultiplier);
    void ballCollision();
    void ballPhysics();

};
#endif //FINAL_PROJECT_TSCOTT5_BALLCONTROLLER_H
