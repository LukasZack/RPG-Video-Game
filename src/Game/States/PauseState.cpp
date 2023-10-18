#include "PauseState.h"

PauseState::PauseState() {
    pause.load("images/ui/pausescreen.png");
}

void PauseState::update() {
}

void PauseState::draw() {
    pause.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void PauseState::keyReleased(int key) {
    if(key == OF_KEY_ESC){
        if(!getBattle()){setNextState("Overworld");}
        else{setNextState("Battle");}
        setFinished(true);
    }
}

void PauseState::reset() {
    setFinished(false);
    setNextState("");
}