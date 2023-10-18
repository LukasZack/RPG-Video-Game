#pragma once

#include "Entity.h"

class Enemy : public Entity {
   protected:
    int speed;
    int renderX;
    int renderY;
    int moveTimer;
    int baseDamage;
    int health;
    bool walking;
    bool dead;
    bool spawned;
    string id;
    string entityName;
    string type;

   public:
    Enemy(int ox, int oy, int moveTimer, int speed, int renderX, int renderY, bool walking, bool dead, int health, int baseDamage, string type, bool spawned);
    ~Enemy();
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
    string getId() { return id; };
    string getType() { return type; };
    ofImage getSprite() { return overworldSprite; };
};