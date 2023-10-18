#include "EntityManager.h"

EntityManager::~EntityManager() {
    entities.clear();
    delete player;
}