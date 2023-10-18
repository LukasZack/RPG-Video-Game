#include "Friend.h"

Friend::Friend(string id, string friendName, int ox, int oy) : Thing(ox, oy, 128, 128, "images/objects/Friend/down/charizard-down1.png")
{
    this->id = id;
    this->friendName = friendName;
    moveTimer = 60;
    vector<ofImage> downFrames = {};
    vector<ofImage> upFrames = {};
    vector<ofImage> leftFrames = {};
    vector<ofImage> rightFrames = {};
    vector<ofImage> fightingFrames = {};
    ofImage temp;

    // reaction.load("images/ui/.png");

    for (int i = 1; i < 4; i++)
    {
        temp.load("images/objects/Friend/down/" + friendName + "-down" + std::to_string(i == 3 ? 1 : i) + ".png");
        downFrames.push_back(temp);
        temp.load("images/objects/Friend/up/" + friendName + "-up" + std::to_string(i == 3 ? 1 : i) + ".png");
        upFrames.push_back(temp);
        temp.load("images/objects/Friend/left/" + friendName + "-left" + std::to_string(i == 3 ? 1 : i) + ".png");
        leftFrames.push_back(temp);
        temp.load("images/objects/Friend/right/" + friendName + "-right" + std::to_string(i == 3 ? 1 : i) + ".png");
        rightFrames.push_back(temp);
    }

    walkDown = new Animation(3, downFrames);
    walkUp = new Animation(3, upFrames);
    walkLeft = new Animation(3, leftFrames);
    walkRight = new Animation(3, rightFrames);
}

void Friend::inOverworldUpdate()
{
    // if (!canInteract){
    if (moveTimer == 90)
    {
        walking = true;
        switch (direction)
        {
        case Direction::left:
            direction = Direction::down;
            break;
        case Direction::right:
            direction = Direction::up;
            break;
        case Direction::up:
            direction = Direction::left;
            break;
        case Direction::down:
            direction = Direction::right;
            break;
        }
    }
    if (moveTimer == 45)
    {
        walking = false;
    }
    moveTimer--;
    if (moveTimer == 0) moveTimer = 90;
    if (walking)
    {
        switch (direction)
        {
        case Direction::left:
            this->ox -= speed;
            walkLeft->update();
            overworldSprite = walkLeft->getCurrentFrame();
            break;
        case Direction::right:
            this->ox += speed;
            walkRight->update();
            overworldSprite = walkRight->getCurrentFrame();
            break;
        case Direction::up:
            this->oy -= speed;
            walkUp->update();
            overworldSprite = walkUp->getCurrentFrame();
            break;
        case Direction::down:
            this->oy += speed;
            walkDown->update();
            overworldSprite = walkDown->getCurrentFrame();
            break;
        }
    }
    // }
    else
    {
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
            case Direction::down:
                overworldSprite = walkDown->getCurrentFrame();
                break;
        }
    }
    // if(interacting){
    //     counter++;
    // }

    // if(counter==100){
    //     interacting = false;
    //     counter = 0;
    // }
}

void Friend::inOverworldDraw()
{
    // if(interacting && canInteract){
    //     reaction.draw(renderX-25, renderY-30, 64, 64);
    // }
    // uncomment these if you want the coordinates of the enemies in the current area
    // ofDrawBitmapString("rX:" + to_string(renderX), 100 + 125 * ((stoi(id) % 10) - 1), 100);
    // ofDrawBitmapString("rY:" + to_string(renderY), 100 + 125 * ((stoi(id) % 10) - 1), 120);
    // ofDrawBitmapString("ow:" + to_string(ox), 100 + 125 * ((stoi(id) % 10) - 1), 140);
    // ofDrawBitmapString("oy:" + to_string(oy), 100 + 125 * ((stoi(id) % 10) - 1), 160);
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void Friend::keyPressed(int key)
{
}

void Friend::keyReleased(int key)
{
}

void Friend::reset()
{
}

Friend::~Friend()
{
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
    delete fighting;
}
