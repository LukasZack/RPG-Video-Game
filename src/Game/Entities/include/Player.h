#pragma once

#include "Animation.h"
#include "Entity.h"

#define INIT_X 100
#define INIT_Y 100
#define INIT_BATTLE_X 64
#define INIT_BATTLE_Y 164
#define CENTER_X 288
#define CENTER_Y 208

#define OXDIMENSION 2688
#define OYDIMENSION 2560

class Player : public Entity {
   private:
    Direction direction = Direction::up;
    int speed = 8;
    bool walking = false;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;
    Animation *fighting;
    vector<char> pressedKeys;

   public:
    Player(int health, int baseDamage);
    ~Player();
    void inOverworldUpdate();
    void fightingUpdate();
    void inOverworldDraw();
    void keyPressed(int key);
    void keyReleased(int key);
    void reset();
    void resetHealth();
};