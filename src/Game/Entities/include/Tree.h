#pragma once
#include "Thing.h"


class Tree : public Thing {
private:
    string id;
    string treeName;
    ofImage overworldSprite;
    int renderX = 1000;
    int renderY = 1000;

public:
    Tree(string id, string treeName, int ox, int oy);
    string getId() {return id;}
    string getTreeName() {return treeName;}
    bool collides(Tree* tree);
    int getOX() { return ox; }
    int getOY() { return oy; }
    void setRenderX(int x) {renderX = x;}
    void setRenderY(int y) {renderY = y;}
    ofImage getOverworldSprite() {return overworldSprite;}
    ofRectangle getBounds();
    void inOverworldUpdate();
    void inOverworldDraw();
};