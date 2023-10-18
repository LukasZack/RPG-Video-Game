#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    ofSetFrameRate(30);
    ofSetWindowTitle("PA2");
    initAreas();
    // Declaration and Initialization of States
    player = new Player(100, 6);
    titleState = new TitleState();
    overworldState = new OverworldState(player, currentArea);
    battleState = new BattleState(player, currentArea);
    winState = new WinState();
    endGameState = new EndGameState();
    pauseState = new PauseState();

    // Initial State
    currentState = titleState;
}

//--------------------------------------------------------------
void ofApp::initAreas() {
    /**
     * @brief
     * each area is 672 pixels wide and 640 pixels high,
     * with 10 and 8 pixels of space between the player and the edge of the map respectively
     * each in-game pixel is 4 * 1 screen pixel
     */
    
    vector<Enemy *> enemies2;
    vector<Tree *>  trees2;
    vector<Friend *> friends2;
    Friend *area2Friend = new Friend("8", "charizard", 4 * 125, 4 * 320);
    friends2.push_back(area2Friend);
    Tree *area2Tree= new Tree("7", "Alientree1", 4 * 125, 4 * 320);
    trees2.push_back(area2Tree);
    ofPoint entrancePosition2(4 * 110, 4 * 116);
    Ghost *area2Enemy1 = new Ghost("21", 30, 6, "enemy2", 4 * 120, 4 * 342);
    Ghost *area2Enemy2 = new Ghost("22", 30, 6, "enemy2", 4 * 254, 4 * 130);
    Ghost *area2Enemy3 = new Ghost("23", 30, 6, "enemy2", 4 * 542, 4 * 124);
    Ghost *area2Enemy4 = new Ghost("24", 30, 6, "enemy2", 4 * 532, 4 * 368);
    Ghost *area2Enemy5 = new Ghost("25", 30, 6, "enemy2", 4 * 266, 4 * 312);
    Boss *area2Boss1 = new Boss("26", 70, 6, "enemy2", 4 * 194, 4 * 532);
    enemies2.push_back(area2Enemy1);
    enemies2.push_back(area2Enemy2);
    enemies2.push_back(area2Enemy3);
    enemies2.push_back(area2Enemy4);
    enemies2.push_back(area2Enemy5);
    enemies2.push_back(area2Boss1);
    area2 = new Area("Area2", NULL, "images/areas/area2.png", "audio/ice.wav", "images/stages/stage2.png", entrancePosition2, enemies2, trees2, friends2);
    
    vector<Enemy *> enemies3;
    vector<Tree *>  trees3;
    vector<Friend *> friends3;
    Friend *area3Friend = new Friend("8", "charizard", 4 * 125, 4 * 320);
    friends3.push_back(area3Friend);
    Tree *area3Tree= new Tree("7", "Alientree1", 4 * 125, 4 * 320);
    trees3.push_back(area3Tree);
    ofPoint entrancePosition3(4 * 414, 4 * 566);
    Ghost *area3Enemy1 = new Ghost("11", 25, 4, "enemy3", 4 * 480, 4 * 432);
    Ghost *area3Enemy2 = new Ghost("12", 25, 4, "enemy3", 4 * 225, 4 * 178);
    Ghost *area3Enemy3 = new Ghost("13", 25, 4, "enemy3", 4 * 420, 4 * 178);
    Boss *area3Boss1 = new Boss("12", 60, 6, "boss3", 4 * 125, 4 * 578);
    enemies3.push_back(area3Enemy1);
    enemies3.push_back(area3Enemy2);
    enemies3.push_back(area3Enemy3);
    enemies3.push_back(area3Boss1);
    area3 = new Area("Area3", area2, "images/areas/area3.png", "audio/fire.wav", "images/stages/stage3.png", entrancePosition3, enemies3, trees3, friends3);
    
    
    vector<Enemy *> enemies1;
    vector<Tree *>  trees1;
    vector<Friend *> friends1;
    Friend *area1Friend = new Friend("8", "charizard", 4 * 125, 4 * 320);
    friends1.push_back(area1Friend);
    Tree *area1Tree= new Tree("7", "Alientree1", 4 * 125, 4 * 320);
    trees1.push_back(area1Tree);
    ofPoint entrancePosition1(4 * 414, 4 * 566);
    Ghost *area1Enemy1 = new Ghost("11", 20, 4, "enemy1", 4 * 480, 4 * 432);
    Ghost *area1Enemy2 = new Ghost("12", 20, 4, "enemy1", 4 * 125, 4 * 178);
    Ghost *area1Enemy3 = new Ghost("13", 20, 4, "enemy1", 4 * 420, 4 * 178);
    Boss *area1Boss1 = new Boss("12", 50, 4, "boss1", 4 * 225, 4 * 178);
    enemies1.push_back(area1Enemy1);
    enemies1.push_back(area1Enemy2);
    enemies1.push_back(area1Enemy3);
    enemies1.push_back(area1Boss1);
    area1 = new Area("Area1", area3, "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, trees1, friends1);
    currentArea = area1;
}

//--------------------------------------------------------------
void ofApp::update() {
    currentState->update();
    if (currentState->hasFinished()) {
        currentState->toggleMusic();
        if (currentState->getNextState() == "Title") {
            endGameState->setWin(false);
            area1->resetEnemies();
            area2->resetEnemies();
            area3->resetEnemies();
            currentArea = area1;
            player->reset();
            battleState->reset();
            battleState->setStage(currentArea->getStage());
            overworldState->loadArea(currentArea);
            currentState = titleState;
        } 
        else if (currentState->getNextState() == "Overworld") {
            currentState = overworldState;
        } 
        else if (currentState->getNextState() == "Pause") {
            currentState = pauseState;
        } 
        else if (currentState->getNextState() == "Battle") {
            battleState->startBattle(overworldState->getEnemy());
            currentState = battleState;
        } 
        else if (currentState->getNextState() == "Win") {
            overworldState->getEnemy()->kill();
            if (currentArea->getRemainingBosses() == 0) {
                overworldState->getEnemy()->unSpawn();
                if (currentArea->getNextArea() == NULL) {
                    endGameState->setWin(true);
                    currentState = endGameState;
                } 
                else {
                    currentArea = currentArea->getNextArea();
                    overworldState->loadArea(currentArea);
                    battleState->setStage(currentArea->getStage());
                    currentState = winState;
                }
            } 
            else {
                currentState = winState;
            }
        } 
        else if (currentState->getNextState() == "End"){
            player->reset();
            currentState = endGameState;
            
        }
        currentState->toggleMusic();
        currentState->reset();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    currentState->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    currentState->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
    currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    currentState->dragEvent(dragInfo);
}