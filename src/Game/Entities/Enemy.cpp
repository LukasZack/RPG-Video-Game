#include "Enemy.h"

Enemy::Enemy(int ox, int oy, int moveTimer, int speed, int renderX, int renderY, bool walking, bool dead, int health, int baseDamage, string type, bool spawned) : Entity(ox, oy, 50, 64, 420, 220, 97, 125, health, baseDamage) {
    this->baseDamage = baseDamage;
    this->health = health;
    this->speed = speed;
    this->renderX = renderX;
    this->renderY = renderY;
    this->moveTimer = moveTimer;
    this->baseDamage = baseDamage;
    this->health = health;
    this->walking = walking;
    this->dead = dead;
    this->type = type;
    this->spawned = spawned;
}

Enemy::~Enemy() {}

void Enemy::inOverworldUpdate(){
    this->overworldSprite = overworldSprite;
}

void Enemy::fightingUpdate(){
    this->fightingSprite = fightingSprite;
}

void Enemy::inOverworldDraw() {
    overworldSprite.draw(renderX, renderY, ow, oh);
}