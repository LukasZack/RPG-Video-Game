#include "Thing.h"

Thing::Thing(int ox, int oy, int ow, int oh, string overworldPath) {
    this->ox = ox;
    this->oy = oy;
    this->oh = oh;
    this->ow = ow;

    overworldSprite.load(overworldPath);
}

void Thing::inOverworldDraw() {
    overworldSprite.draw(ox, oy, ow, oh);
    }

// bool Thing::collides(Thing* thing) {
//     return this->getBounds().intersects(entity->getBounds());
// }

ofRectangle Thing::getBounds(){
    return ofRectangle(ox, oy, ow, oh);
}

ofRectangle Thing::getBounds(int ox, int oy) {
    return ofRectangle(ox, oy, ow, oh);
}





