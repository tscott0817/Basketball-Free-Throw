#include "scoreTracker.h"

ScoreTracker::ScoreTracker() {
    ballScored = false;
    points = 0;
    pointsString = "0";
}

void ScoreTracker::trackScore(BallController basketballs, Rect hoop) {

    for (int i = 0; i < basketballs.getBallVector().size(); i++) {

        if (basketballs.getBallVector()[i].getCenterX() > hoop.getLeftX() &&
            basketballs.getBallVector()[i].getCenterX() < hoop.getRightX() &&
            basketballs.getBallVector()[i].getCenterY() > hoop.getTopY() &&
            basketballs.getBallVector()[i].getCenterY() < hoop.getBottomY()) {

            points += 1;
            pointsString = std::to_string(points);

        }
    }
}

std::string ScoreTracker::getScore() {
    return pointsString;
}

void ScoreTracker::resetScore() {
    points = 0;
    pointsString = "0";
}

// Displays current score to top left of screen
void ScoreTracker::displayScore() {

    // Set color, flip y-axis, and scale size of score text
    glColor3f(1, 1, 1);
    glScalef(1.0, -1, 1.0);
    glTranslatef(50, -150, 0);

    for (const char &currentPoint : pointsString) {

        glutStrokeCharacter(GLUT_STROKE_ROMAN, currentPoint);
    }
}

