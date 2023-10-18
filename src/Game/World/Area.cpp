#include "Area.h"

Area::Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<Tree *> trees, vector<Friend *> friends) {
    this->name = name;
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->trees = trees; 
    this->friends = friends;
}

void Area::resetEnemies() {
    for (unsigned int i = 0; i < enemies.size(); i++)
        enemies.at(i)->revive();
}

int Area::getRemainingEnemies() {
    int count = 0;
    for (unsigned int i = 0; i < enemies.size(); i++)
        if (!enemies.at(i)->isDead())
            count++;

    return count;
}

int Area::getRemainingBosses() {
    int count = 0;
    for (unsigned int i = 0; i < enemies.size(); i++)
        if (!enemies.at(i)->isDead()&&enemies.at(i)->getType()!="ghost")
            count++;

    return count;
}

int Area::getRemainingGhost() {
    int count = 0;
    for (unsigned int i = 0; i < enemies.size(); i++)
        if (!enemies.at(i)->isDead()&&enemies.at(i)->getType() != "boss")
            count++;

    return count;
}

bool Area::bossShower() {
    for (unsigned int i = 0; i < enemies.size(); i++){
        if (enemies.at(i)->isSpawned() && enemies.at(i)->getType() != "ghost"){
            return true;
        }
    }
    return false;
}