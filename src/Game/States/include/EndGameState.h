#pragma once

#include "Enemy.h"
#include "Player.h"
#include "State.h"

class EndGameState : public State {
   private:
    Player *player;
    Enemy *enemy;
    ofImage loseScreen;
    ofImage winScreen;
    bool win;

   public:
    EndGameState();
    bool getWin() { return win; };
    void setWin(bool winning) { this->win = winning; };
    void update();
    void draw();
    void keyPressed(int key);
    void reset();
};