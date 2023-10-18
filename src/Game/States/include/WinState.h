#pragma once

#include "Enemy.h"
#include "Player.h"
#include "State.h"

class WinState : public State {
   private:
    Player *player;
    Enemy *enemy;
    ofImage screen;

   public:
    WinState();
    void update();
    void draw();
    void keyPressed(int key);
    void reset();
};