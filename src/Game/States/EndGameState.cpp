#include "EndGameState.h"

EndGameState::EndGameState() {
    loseScreen.load("images/ui/losescreen.png");
    winScreen.load("images/ui/winscreen.png");
    win = false;
}

void EndGameState::update() {
}

void EndGameState::draw() {
    if (win)
        winScreen.draw(0, 0, ofGetWidth(), ofGetHeight());
    else
        loseScreen.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void EndGameState::keyPressed(int key) {
    setNextState("Title");
    setFinished(true);
}

void EndGameState::reset() {
    setFinished(false);
    setNextState("");
}