#pragma once

#include "Animation.h"
#include "State.h"

class TitleState : public State {
   private:
    ofImage titleImage;
    Animation *titlescreen;

   public:
    TitleState();
    void update();
    void draw();
    void keyPressed(int key);
    void reset();
};