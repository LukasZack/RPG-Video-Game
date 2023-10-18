#include "TitleState.h"

TitleState::TitleState() {
    vector<ofImage> titleFrames;
    ofImage temp;
    temp.load("images/ui/title1.png");
    titleFrames.push_back(temp);
    temp.load("images/ui/title2.png");
    titleFrames.push_back(temp);
    titlescreen = new Animation(11, titleFrames);
    setNextState("Overworld");
    music.load("audio/title.wav");
    music.setLoop(true);
    music.setVolume(0.25);
    music.play();
}

void TitleState::update() {
    titlescreen->update();
    titleImage = titlescreen->getCurrentFrame();
}

void TitleState::draw() {
    titleImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void TitleState::keyPressed(int key) {
    setNextState("Overworld");
    setFinished(true);
}

void TitleState::reset() {
    setFinished(false);
    setNextState("");
}