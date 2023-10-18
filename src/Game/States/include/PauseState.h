#pragma once

#include "Area.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "Player.h"
#include "State.h"
#include "BattleState.h"

class PauseState : public State {
   private:
    ofImage pause;

   public:
    PauseState();
    void update();
    void draw();
    void keyReleased(int key);
    void reset();
};