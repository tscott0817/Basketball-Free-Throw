#include "ballController.h"
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color black(.4,.4,.4);
const color trigger(1, 0, 1, 0);
const color invisible(.4,.4,.4, 0.0);

BallController::BallController() {
    canScore = true;
}

void BallController::addBalls(int numBasketballs) {

    int ballXPos = 0;

    // Used as trigger for refilling vector
    basketballs.push_back(Circle(trigger, ballXPos + 100, 525, 20));

    for (int i = 0; i < numBasketballs; i++) {
        ballXPos += 50;
        basketballs.push_back(Circle(brickRed, ballXPos + 100, 525, 20));
    }
}

void BallController::emptyBallVector() {

    for (int i = 0; i < basketballs.size(); i++) {

        basketballs.erase(basketballs.begin(), basketballs.begin() + basketballs.size());
    }
}


void BallController::drawBall() {

    for (const Circle &ball : basketballs) {
        ball.draw();
    }
}

std::vector<Circle> BallController::getBallVector() {
    return basketballs;
}

void BallController::powerShot(int ballNum, double velMultiplier) {
    basketballs[ballNum].setVelocity(10 * velMultiplier, -20 * velMultiplier);
}

void BallController::ballCollision() {

    for (int i = 0; i < basketballs.size() - 1; ++i) {
        for (int j = i + 1; j < basketballs.size(); ++j) {
            if (basketballs[i].isOverlapping(basketballs[j])) {
                basketballs[i].collide(basketballs[j]);
            }
        }
    }
}

// Add physics to all basketballs
void BallController::ballPhysics() {

    for (Circle &ball : basketballs) {

        ball.setVelocity(ball.getXVelocity(), ball.getYVelocity() + .5);
        ball.move(ball.getXVelocity(), ball.getYVelocity());

        if (ball.getCenterX() < ball.getRadius()) {
            ball.bounceX();
            ball.setCenterX(ball.getRadius());

            // Sets right side rebound
            ball.setVelocity(ball.getXVelocity() - 4, ball.getYVelocity());

        } else if (ball.getCenterX() > (width - ball.getRadius())) {
            ball.bounceX();
            ball.setCenterX(width - ball.getRadius());

            // Sets left side rebound
            ball.setVelocity(ball.getXVelocity() + 4, ball.getYVelocity());

        }
        if (ball.getCenterY() < ball.getRadius()) {
            ball.bounceY();
            ball.setCenterY(ball.getRadius());

            // Sets top rebound
            ball.setVelocity(ball.getXVelocity(), ball.getYVelocity() - 6);

            // Makes sure velocity does not go negative Y (Stuck to ceiling)
            if (ball.getYVelocity() <= 0) {
                ball.setYVelocity(1);
            }
        }

        // Scalar attached to height to set floor level
        else if (ball.getCenterY() > ((height - 170) - ball.getRadius())) {
            ball.bounceY();
            ball.setCenterY((height - 170) - ball.getRadius());

            // Floor rebound
            ball.setVelocity(ball.getXVelocity(), ball.getYVelocity() + 10);
            //ball.setVelocity(0, 0);

        }
    }
}


