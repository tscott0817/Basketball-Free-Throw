#ifndef FINAL_PROJECT_TSCOTT5_SCORETRACKER_H
#define FINAL_PROJECT_TSCOTT5_SCORETRACKER_H

#include "main.h"
#include "ballController.h"
#include <vector>
#include "gameObjects/primitives/rect.h"

class ScoreTracker {

private:
    bool ballScored;
    int points;
    std::string pointsString;
public:

    ScoreTracker();

    void trackScore(BallController basketballs, Rect hoop);
    std::string getScore();
    void resetScore();
    void displayScore();

};

#endif //FINAL_PROJECT_TSCOTT5_SCORETRACKER_H
