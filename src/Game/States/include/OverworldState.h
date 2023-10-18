#pragma once

#include "Area.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "Player.h"
#include "State.h"
#include "BattleState.h"
#include "Tree.h"
#include "Friend.h"

class OverworldState : public State {
   private:
    ofImage overworldImage;
    Player *player;
    OverworldCamera *camera;
    Area *area;
    std::vector<Enemy *> enemies;
    std::vector<Tree *> trees;
    std::vector<Friend *> friends;
    Enemy *enemy;

   public:
    string print;
    OverworldState(Player *player, Area *area);
    Player *getPlayer() { return player; };
    void setEnemy(Enemy *enemy) { this->enemy = enemy; };
    Enemy *getEnemy() { return enemy; };
    void loadArea(Area *Area);
    Area *getArea() { return area; };
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void reset();
};