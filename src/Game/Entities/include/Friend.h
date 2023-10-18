#pragma once

#include "Thing.h" 
#include "Animation.h"
#include "Entity.h"

class Friend : public Thing {
    private:
        Direction direction = Direction::down;
        int speed = 8;
        bool walking = false;
        int renderX = 1000;
        int renderY = 1000;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        Animation *fighting;
        string id;
        int moveTimer;
        string friendName;
        ofImage sprite; 
        // bool canInteract = false;
        // bool interacting = false;
        // ofImage reaction;
        // int counter = 0;

    
    public:
        Friend(string id, string friendName, int ox, int oy);
        ~Friend();
        int getOX() { return ox; };
        int getOY() { return oy; };
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void inOverworldUpdate();
        void inOverworldDraw();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId(){ return id; };
        ofImage getSprite() { return overworldSprite;};
        // void setCanInteract(bool canInteract){this->canInteract = canInteract;}
        // bool getCanInteract() { return canInteract;}
        // void setInteracting(bool interacting){this->interacting = interacting;}
};