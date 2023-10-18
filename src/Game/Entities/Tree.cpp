#include "Tree.h"

Tree::Tree(string id, string treeName, int ox, int oy): Thing(ox, oy, 128, 128, "") {
    this->id = id;
    this->treeName = treeName;
    overworldSprite.load("images/objects/trees/" + treeName + ".png");
}

 void Tree::inOverworldUpdate()
 {}

void Tree::inOverworldDraw() {

overworldSprite.draw(renderX, renderY, ow, oh);
}

ofRectangle Tree::getBounds() {

    return ofRectangle(ox+56, oy+100, 16, 16);
}

