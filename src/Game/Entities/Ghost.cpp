#include "Ghost.h"

Ghost::Ghost(string id, int health, int baseDamage, string entityName, int ox, int oy) : Enemy(ox, oy, 60, 8, 1000, 1000, false, false, health, baseDamage, "ghost", true) {
    this->id = id;
    this->baseDamage = baseDamage;
    this->health = health;
    this->entityName = entityName;
    this->spawned = spawned;
    vector<ofImage> downFrames;
    vector<ofImage> upFrames;
    vector<ofImage> leftFrames;
    vector<ofImage> rightFrames;
    ofImage sprite;
    ofImage temp;

    sprite.load("images/entities/enemy/sprite.png");

    int w = 48, h = 48;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp.cropFrom(sprite, 6 + w * i, 192 + h * j, w - 12, h);
            if (j == 0)
                downFrames.push_back(temp);
            else if (j == 1)
                leftFrames.push_back(temp);
            else if (j == 2)
                rightFrames.push_back(temp);
            else
                upFrames.push_back(temp);
        }   
    } 
    
    walkDown = new Animation(3, downFrames);
    walkUp = new Animation(3, upFrames);
    walkLeft = new Animation(3, leftFrames);
    walkRight = new Animation(3, rightFrames);
    fighting = new Animation(7, leftFrames);

    direction = Direction::right;
}

void Ghost::inOverworldUpdate() {
    if (moveTimer == 60) {
        walking = true;
        switch (direction) {
            case Direction::left:
                direction = Direction::up;
                break;
            case Direction::right:
                direction = Direction::left;
                break;
            case Direction::up:
                direction = Direction::right;
                break;
            // case Direction::down:
            //     direction = Direction::left;
            //     break;
        }
    }
    if (moveTimer == 45) {
        walking = false;
    }
    moveTimer--;
    if (moveTimer == 0) moveTimer = 60;

    if (walking) {
        switch (direction) {
            case Direction::left:
                this->ox -= speed;
                walkLeft->update();
                overworldSprite = walkLeft->getCurrentFrame();
                break;
            case Direction::right:
                this->ox += speed;
                this->oy += speed;
                walkRight->update();
                overworldSprite = walkRight->getCurrentFrame();
                break;
            case Direction::up:
                this->oy -= speed;
                walkUp->update();
                overworldSprite = walkUp->getCurrentFrame();
                break;
            // case Direction::down:
            //     this->oy += speed;
            //     walkDown->update();
            //     overworldSprite = walkDown->getCurrentFrame();
            //     break;
        }
    } else {
        switch (direction) {
            case Direction::left:
                overworldSprite = walkLeft->getCurrentFrame();
                break;
            case Direction::right:
                overworldSprite = walkRight->getCurrentFrame();;
                break;
            case Direction::up:
                overworldSprite = walkUp->getCurrentFrame();
                break;
            // case Direction::down:
            //     overworldSprite = walkDown->getCurrentFrame();
            //     break;
        }
    }
}

void Ghost::inOverworldDraw() {
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void Ghost::fightingUpdate() {
    fightingSprite = fighting->getCurrentFrame();
    fighting->update();
}

void Ghost::reset() {
}

Ghost::~Ghost() {
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
    delete fighting;
}