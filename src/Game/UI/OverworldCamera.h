#pragma once

#include "EntityManager.h"

#define DIMENSIONX 640
#define DIMENSIONY 480
#define OXDIMENSION 2688
#define OYDIMENSION 2560

class OverworldCamera {
   private:
    Player *player;
    int playerX, playerY;
    int playerW, playerH;
    int leftCornerX;
    int rightCornerX;
    int topCornerY;
    int bottomCornerY;

   public:
    OverworldCamera(Player *player);
    void update();
    int getPlayerX() { return playerX; };
    int getPlayerY() { return playerY; };
    int getDimensionX() { return DIMENSIONX; };
    int getDimensionY() { return DIMENSIONY; };
    int getLeftCornerX() { return leftCornerX; };
    int getRightCornerX() { return rightCornerX; };
    int getTopCornerY() { return topCornerY; };
    int getBottomCornerY() { return bottomCornerY; };
};