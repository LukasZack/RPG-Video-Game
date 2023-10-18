#include "BattleState.h"

BattleState::BattleState(Player *player, Area *area) {
    stage = area->getStage();
    music.load("audio/battle.wav");
    music.setLoop(true);
    music.setVolume(0.25);
    buttonChange.load("audio/ui/beep.mp3");
    buttonChange.setVolume(0.5);
    buttonSelect.load("audio/ui/boop.mp3");
    buttonSelect.setVolume(0.5);
    this->player = player;
    currentButton = 1;
    resultTimer = 0;
    canInteract = true;
    if(!getBattle()){
        currentPlayerHealth = PLAYER_MAX_HP = player->getHealth();
    }
    button1.load("images/ui/buttons/rock.png");
    button2.load("images/ui/buttons/paper.png");
    button3.load("images/ui/buttons/scissors.png");
    result1.load("images/ui/buttons/rock1.png");
    result2.load("images/ui/buttons/paper1.png");
    result3.load("images/ui/buttons/scissors1.png");
}

void BattleState::startBattle(Enemy *enemy) {
    this->enemy = enemy;
    if(!getBattle()){
        currentEnemyHealth = ENEMY_MAX_HP = enemy->getHealth();
    }
    currentEnemyHealth = enemy->getHealth();
    currentPlayerHealth = player->getHealth();
}

void BattleState::update() {
    if (canInteract) {
        if (currentPlayerHealth <= 0) {
            setNextState("End");
            setFinished(true);
            player->setHealth(currentPlayerHealth);
            
            return;
        } else if (currentEnemyHealth <= 0) {
            setNextState("Win");
            setFinished(true);
            player->setHealth(currentPlayerHealth);
            return;
        }
    }

    player->fightingUpdate();
    enemy->fightingUpdate();

    if (choice != Move::none && canInteract) {
        enemyChoice = rand() % 3 + 1;
        if ((choice == Move::rock && enemyChoice == 2) || (choice == Move::paper && enemyChoice == 3) || (choice == Move::scissors && enemyChoice == 1)) {
            currentPlayerHealth -= enemy->getDmg() * 2.0;
            currentEnemyHealth -= player->getDmg() / 2.0;
            outcome = Outcome::lose;
        } else if ((choice == Move::rock && enemyChoice == 3) || (choice == Move::paper && enemyChoice == 1) || (choice == Move::scissors && enemyChoice == 2)) {
            currentPlayerHealth -= enemy->getDmg() / 2.0;
            currentEnemyHealth -= player->getDmg() * 2.0;
            outcome = Outcome::win;
        } else {
            currentPlayerHealth -= enemy->getDmg();
            currentEnemyHealth -= player->getDmg();
            outcome = Outcome::draw;
        }
        resultTimer = ofGetFrameRate();
        canInteract = false;
    }
}

void BattleState::draw() {
    // render stage
    stage.draw(0, 0, ofGetWidth(), ofGetHeight());

    // render combatant sprites
    player->fightingDraw();
    enemy->fightingDraw();

    // render move buttons
    ofSetColor(180, 180, 180);
    if (currentButton == 1)
        ofSetColor(255, 255, 255);
    button1.draw(10 * 4, 84 * 4, 192, 192);

    ofSetColor(180, 180, 180);
    if (currentButton == 2)
        ofSetColor(255, 255, 255);
    button2.draw(56 * 4, 84 * 4, 192, 192);

    ofSetColor(180, 180, 180);
    if (currentButton == 3)
        ofSetColor(255, 255, 255);
    button3.draw(102 * 4, 84 * 4, 192, 192);

    ofSetColor(255, 255, 255);

    drawOutcome();
    drawHealthBar();

    ofSetColor(255, 255, 255);
}

void BattleState::drawHealthBar() {
    ofImage healthbar;
    healthbar.load("images/ui/healthbar.png");
    healthbar.draw(64, 64, 192, 192);
    if(enemy->getType()=="boss"){ healthbar.load("images/ui/healthbar2.png"); }
    healthbar.draw(384, 64, 192, 192);

    for (int i = 0; i < 3; i++) {
        double playerHealthRatio = (double)currentPlayerHealth / (double)PLAYER_MAX_HP;
        double enemyHealthRatio = (double)currentEnemyHealth / (double)ENEMY_MAX_HP;
        double enemyHealthRatio2 = enemyHealthRatio *2;
        if (playerHealthRatio < 0)
            playerHealthRatio = 0;
        else if (playerHealthRatio < 0.33)
            ofSetColor(200 - i * 20, 60 - i * 20, 60 - i * 20);
        else if (playerHealthRatio < 0.66)
            ofSetColor(180 - i * 20, 200 - i * 20, 60 - i * 20);
        else
            ofSetColor(60 - i * 20, 180 - i * 20, 80 - i * 20);

        ofDrawRectangle(108, 152 + i * 4, (int)(36 * playerHealthRatio) * 4, 4);
        if(enemy->getType()=="ghost"){
            if (enemyHealthRatio < 0)
                enemyHealthRatio = 0;
            else if (enemyHealthRatio < 0.33)
                ofSetColor(200 - i * 20, 60 - i * 20, 60 - i * 20);
            else if (enemyHealthRatio < 0.66)
                ofSetColor(180 - i * 20, 200 - i * 20, 60 - i * 20);
            else
                ofSetColor(60 - i * 20, 180 - i * 20, 80 - i * 20);

            ofDrawRectangle(428, 152 + i * 4, (int)(36 * enemyHealthRatio) * 4, 4);
        }

        if(enemy->getType()=="boss"){
            if (enemyHealthRatio2 >= 1){
                if (enemyHealthRatio2 <= 1.40){
                    ofSetColor(180 - i * 20, 200 - i * 20, 60 - i * 20);
                }
                else{
                    ofSetColor(60 - i * 20, 180 - i * 20, 80 - i * 20);
                }

                ofDrawRectangle(428, 152 + i * 4, (int)(36 * enemyHealthRatio) * 4, 4);
                ofSetColor(60 - i * 20, 180 - i * 20, 80 - i * 20);
                ofDrawRectangle(428, 125 + i * 4, (int)(36 * 1) * 4, 4);
            }

            else{ 
                if(enemyHealthRatio2< 0){ enemyHealthRatio2 = 0; }

                if (enemyHealthRatio < 0.30){
                    ofSetColor(200 - i * 20, 60 - i * 20, 60 - i * 20);
                }

                else{
                    ofSetColor(180 - i * 20, 200 - i * 20, 60 - i * 20);
                }      
                ofDrawRectangle(428, 125 + i * 4, (int)(36 * enemyHealthRatio2) * 4, 4);          
            }
        }   
    }
    ofFill();
}

void BattleState::drawOutcome() {
    if (resultTimer > 1) {
        resultTimer--;
        float posY = 60 * 4;
        float pposX = 64 * 4;
        float eposX = 80 * 4;
        float dim = 64;

        switch (outcome) {
            case Outcome::win:
                ofSetColor(100, 255, 100);
                if (choice == Move::rock)
                    result1.draw(pposX, posY, dim, dim);
                if (choice == Move::paper)
                    result2.draw(pposX, posY, dim, dim);
                if (choice == Move::scissors)
                    result3.draw(pposX, posY, dim, dim);
                ofSetColor(255, 100, 100);
                if (enemyChoice == 1)
                    result1.draw(eposX, posY, dim, dim);
                if (enemyChoice == 2)
                    result2.draw(eposX, posY, dim, dim);
                if (enemyChoice == 3)
                    result3.draw(eposX, posY, dim, dim);
                break;
            case Outcome::lose:
                ofSetColor(255, 100, 100);
                if (choice == Move::rock)
                    result1.draw(pposX, posY, dim, dim);
                if (choice == Move::paper)
                    result2.draw(pposX, posY, dim, dim);
                if (choice == Move::scissors)
                    result3.draw(pposX, posY, dim, dim);
                ofSetColor(100, 255, 100);
                if (enemyChoice == 1)
                    result1.draw(eposX, posY, dim, dim);
                if (enemyChoice == 2)
                    result2.draw(eposX, posY, dim, dim);
                if (enemyChoice == 3)
                    result3.draw(eposX, posY, dim, dim);
                break;
            case Outcome::draw:
                ofSetColor(200, 200, 100);
                if (choice == Move::rock)
                    result1.draw(pposX, posY, dim, dim);
                if (choice == Move::paper)
                    result2.draw(pposX, posY, dim, dim);
                if (choice == Move::scissors)
                    result3.draw(pposX, posY, dim, dim);
                if (enemyChoice == 1)
                    result1.draw(eposX, posY, dim, dim);
                if (enemyChoice == 2)
                    result2.draw(eposX, posY, dim, dim);
                if (enemyChoice == 3)
                    result3.draw(eposX, posY, dim, dim);
                break;
        }
        ofSetColor(255, 255, 255);
    }
    if (resultTimer == 1) {
        canInteract = true;
        choice = Move::none;
        resultTimer--;
    }
}

void BattleState::keyPressed(int key) {
    if (canInteract) {
        if (key == OF_KEY_LEFT || key == 'a') {
            buttonChange.play();
            if (currentButton == 1)
                currentButton = 3;
            else
                currentButton--;
        }
        if (key == OF_KEY_RIGHT || key == 'd') {
            buttonChange.play();
            if (currentButton == 3)
                currentButton = 1;
            else
                currentButton++;
        }
        if (key == OF_KEY_RETURN) {
            buttonSelect.play();
            switch (currentButton) {
                case 2:
                    choice = Move::paper;
                    break;
                case 3:
                    choice = Move::scissors;
                    break;
                default:
                    choice = Move::rock;
                    break;
            }
        }
    } 
    if (key == 'h') { 
        player->resetHealth(); 
        currentPlayerHealth = PLAYER_MAX_HP = player->getHealth();
    
    }
}

void BattleState::keyReleased(int key) {
    if(key == OF_KEY_ESC){
        setBattle(true);
        setNextState("Pause");
        setFinished(true);
        player->setHealth(currentPlayerHealth);
        enemy->setHealth(currentEnemyHealth);
    }
}

void BattleState::reset() {
    setFinished(false);
    setNextState("");
    currentPlayerHealth = player->getHealth();
}