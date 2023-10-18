#include "Animation.h"

Animation::Animation(int speed, std::vector<ofImage> frames) {
    this->speed = speed;
    this->frames = frames;
    this->index = this->timer = 0;
}

void Animation::update() {
    if (++timer > speed) {
        if (++index == frames.size())
            index = 0;
        timer = 0;
    }
}

ofImage Animation::getCurrentFrame() {
    return frames[index];
}