#pragma once

#include "ofMain.h"

enum Direction {left, right, up, down};

class Entity {
   protected:
    int health;
    int baseDamage;
    int fx, fy, fw, fh; // Fighting coordinates and dimensions
    int ox, oy, ow, oh; // Overworld Coordinates and dimensions
    ofImage fightingSprite;
    ofImage overworldSprite;

   public:
    Entity(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage);
    virtual ~Entity();
    virtual void inOverworldUpdate() = 0;
    virtual void fightingUpdate() = 0;
    virtual void inOverworldDraw();
    virtual void fightingDraw();
    int getOX() { return ox; };
    int getOY() { return oy; };
    int getOW() { return ow; };
    int getOH() { return oh; };
    ofRectangle getBounds();
    ofRectangle getBounds(int ox, int oy);
    bool collides(Entity* entity);
    void setOX(int ox) { this->ox = ox; };
    void setOY(int oy) { this->oy = oy; };
    void setHealth(int health) { this->health = health; };
    void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
    int getHealth() { return health; };
    int getDmg() { return baseDamage; };
    
   
};