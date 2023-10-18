#include "WinState.h"

WinState::WinState() {
    screen.load("images/ui/winscreen.png");
}

void WinState::update() {
}

void WinState::draw() {
    screen.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void WinState::keyPressed(int key) {
    setNextState("Overworld");
    setFinished(true);
}

void WinState::reset() {
    setFinished(false);
    setNextState("");
}