#pragma once
#include "ofMain.h"

class Thing {
protected: 
     int ox, oy, ow, oh; // Overworld Coordinates and dimensions
     ofImage overworldSprite;


public:
    Thing(int ox, int oy, int ow, int oh, string overworldPath);
    int getOX() { return ox; };
    int getOY() { return oy; };
    int getOW() { return ow; };
    int getOH() { return oh; };

    void setOX(int ox) { this->ox = ox; };
    void setOY(int oy) { this->oy = oy; };
    virtual void inOverworldUpdate() = 0;
    virtual void inOverworldDraw();
    virtual ofRectangle getBounds();
    ofRectangle getBounds(int ox, int oy);
    // bool collides(Entity* entity);


};