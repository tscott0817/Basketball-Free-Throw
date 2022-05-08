#ifndef FINAL_PROJECT_TSCOTT5_INPUTMANAGER_H
#define FINAL_PROJECT_TSCOTT5_INPUTMANAGER_H

#include "gameObjects/primitives/circle.h"
#include "main.h"
#include "inputManager.h"
#include "scoreTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class InputManager {

private:
    std::string username;
    std::string score;
    std::ofstream scoresInput;

public:

    InputManager() {
        username = "NA";
        score = "NA";

    }

    InputManager(std::string username, std::string score) {
        this->username = username;
        this->score = score;
    }

    // Setters
    void setUsername(std::string username) {
        this->username = username;
    }

    void setScore(std::string score) {
        this->score = score;
    }

    // Getters
    std::string getUsername() {
        return username;
    }

    std::string getScore() {
        return score;
    }

    void addScoresToFile(std::string username, std::string score) {

        scoresInput.open ("../scores.csv", std::ios::app);

        scoresInput << username << ", " << score << "\n";
        //scoresInput.flush();
        scoresInput.close();
    }


    // For printing to console
    friend std::ostream& operator << (std::ostream& outs, const InputManager &m) {
        outs << std::fixed;
        outs << std:: left << std::setw(5) << m.username;
        outs << std::left << std::setw(2) << m.score;
        return outs;
    }


};

// Adds high scores to vector, takes in .csv file and vector to be added to
void getHighScores(std::string filename, std::vector<InputManager> &scores) {

    std::ifstream fIn;
    fIn.open("../" + filename);

    // Variables to be used in loop
    std::string username = "", score = "";

    //char comma = ',';

    // Reads file and adds to vector
    while(fIn && fIn.peek() != EOF) {

        getline(fIn, username, ',');

        getline(fIn, score);

        scores.push_back(InputManager(username, score));

    }

    fIn.close();
}

#endif //FINAL_PROJECT_TSCOTT5_INPUTMANAGER_H
