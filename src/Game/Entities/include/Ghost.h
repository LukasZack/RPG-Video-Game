#pragma once

#include "Animation.h"
#include "Enemy.h"

class Ghost : public Enemy{
   private:
    Direction direction;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;
    Animation *fighting;
    ofImage sprite;

   public:
    Ghost(string id, int health, int baseDamage, string entityName, int ox, int oy);
    ~Ghost();
    int getOX() { return ox; };
    int getOY() { return oy; };
    bool isDead() { return dead; };
    bool isSpawned() { return spawned;};
    void kill() { this->dead = true; };
    void revive() { this->dead = false; };
    void unSpawn() { this->spawned = false; };
    void spawn() { this->spawned = true; };
    void setRenderX(int x) { renderX = x; };
    void setRenderY(int y) { renderY = y; };
    void inOverworldUpdate();
    void fightingUpdate();
    void inOverworldDraw();
    void reset();
    string getId() { return id; };
    ofImage getSprite() { return overworldSprite; };
};