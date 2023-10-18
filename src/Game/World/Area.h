#pragma once

#include "Enemy.h"
#include "Boss.h"
#include "Ghost.h"
#include "OverworldCamera.h"
#include "Player.h"
#include "Tree.h"
#include "Friend.h"

class Area {
   private:
    string name;
    ofImage areaImage;
    ofSoundPlayer areaMusic;
    ofImage areaStage;
    ofPoint entrancePosition;
    std::vector<Enemy *> enemies;
    std::vector<Tree *> trees;
    std::vector<Friend *> friends;
    Area *nextArea;

   public:
    Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<Tree *> trees, vector<Friend *> friends);
    void resetEnemies();
    string getName() { return name; }
    ofImage getImage() { return areaImage; }
    ofSoundPlayer getMusic() { return areaMusic; }
    ofImage getStage() { return areaStage; }
    ofPoint getEntrancePos() { return entrancePosition; }
    vector<Enemy *> getEnemies() { return enemies; }
    vector<Tree *> getTrees() { return trees; }
    vector<Friend *> getFriends() {return friends;}
    int getRemainingEnemies();
    int getRemainingBosses();
    int getRemainingGhost();
    bool bossShower();
    Area *getNextArea() { return nextArea; }
    void setName(string name) { this->name = name; }
    void setEnemies(std::vector<Enemy *> enemies) { this->enemies = enemies; }
    void setTrees(std::vector<Tree *> trees) { this->trees = trees; }
    void setFriends(std::vector<Friend *> friends) {this->friends = friends; }
};