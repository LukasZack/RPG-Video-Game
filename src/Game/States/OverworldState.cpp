#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area) {
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
}

void OverworldState::loadArea(Area *area) {
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}

void OverworldState::update() {
    player->inOverworldUpdate();
    if(area->getRemainingGhost()==0){ 
        for (unsigned int i = 0; i < area->getEnemies().size(); i++){
            area->getEnemies().at(i)->spawn();
        }
    }
    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        if (!area->getEnemies().at(i)->isDead()&&area->getEnemies().at(i)->isSpawned()) {
            area->getEnemies().at(i)->inOverworldUpdate();
            if (player->collides(area->getEnemies().at(i))) {
                setEnemy(area->getEnemies().at(i));
                setNextState("Battle");
                setFinished(true);
                break;
            }
        }
    }
    for (unsigned int i = 0; i < area->getFriends().size(); i++) {
       area->getFriends().at(i)->inOverworldUpdate(); 
         
    }
    if(area->getName() == "Area3"){
        if(static_cast<int>(ofGetElapsedTimef()) % 2 == 0 && static_cast<int>(ofGetElapsedTimef()) > lastTime){
            player->setHealth(player->getHealth()-1);
            lastTime = static_cast<int>(ofGetElapsedTimef());
        } 
    }
    if(player->getHealth()<=0){
        
        setNextState("End");
        setFinished(true);
        player->resetHealth();
    }
    camera->update();
}

void OverworldState::draw() {
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->inOverworldDraw();
    for (unsigned int i = 0; i < area->getFriends().size(); i++) {
            int playerDistanceX = area->getFriends().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getFriends().at(i)->getOY() - camera->getPlayerY();
            area->getFriends().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getFriends().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getFriends().at(i)->inOverworldDraw();
    }

    for (unsigned int i = 0; i < area->getTrees().size(); i++) {
            int playerDistanceX = area->getTrees().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getTrees().at(i)->getOY() - camera->getPlayerY();
            area->getTrees().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getTrees().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getTrees().at(i)->inOverworldDraw();
        }
    

    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        if (!area->getEnemies().at(i)->isDead()&&area->getEnemies().at(i)->isSpawned()) {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->inOverworldDraw();
        }
    }
    print = area->getName();
    ofDrawBitmapString("Area: "+print ,0,((ofGetHeight()/2)-(ofGetHeight()/4))-(ofGetHeight()/8));
    print = "Enemies Alive: "+ofToString(area->getRemainingEnemies());
    ofDrawBitmapString(print ,0,(ofGetHeight()/2)-(ofGetHeight()/4));
    print = "Current Health: "+ofToString(player->getHealth());
    ofDrawBitmapString(print ,0,((ofGetHeight()/2)-(ofGetHeight()/4))+(ofGetHeight()/8)); 
}

void OverworldState::keyPressed(int key) {
    player->keyPressed(key);
}

void OverworldState::keyReleased(int key) {
    player->keyReleased(key);
    if(key == OF_KEY_ESC){
        setBattle(false);
        setNextState("Pause");
        setFinished(true);
    }
    if(key == 'r'){
        area->resetEnemies();
    }
    if(key == 'b'){
        for (unsigned int i = 0; i < area->getEnemies().size(); i++){
            area->getEnemies().at(i)->spawn();
        }
    }
}

void OverworldState::reset() {
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}