#pragma once

#include "State.h"
#include "Player.h"
#include "Enemy.h"
#include "Area.h"

enum Move {rock, paper, scissors, none};
enum Outcome {win, lose, draw};
class BattleState : public State {
    private: 
        ofImage stage;
        Player *player;
        Enemy *enemy;
        Move choice = Move::none;
        Outcome outcome = Outcome::draw;
        int enemyChoice = 0;
        ofSoundPlayer buttonChange;
        ofSoundPlayer buttonSelect;
        ofImage button1;
        ofImage button2;
        ofImage button3;
        ofImage result1;
        ofImage result2;
        ofImage result3;
        int currentButton;
        int currentPlayerHealth;
        int currentEnemyHealth;
        int resultTimer;
        bool canInteract;
        int PLAYER_MAX_HP;
        int ENEMY_MAX_HP;
    public:
        BattleState(Player *player, Area *area);
        void update();
        void draw();
        void startBattle(Enemy *enemy);
        void drawHealthBar();
        void drawOutcome();
        void setEnemy(Enemy *enemy) {this-> enemy = enemy;};
        Enemy* getEnemy() {return enemy;};
        void setStage(ofImage stage) {this-> stage = stage;};
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
};