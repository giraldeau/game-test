#pragma once
#include "../components.hpp"
#include <SFML/Audio.hpp>
using namespace std;

// State system
typedef unisgned int Entity;

class State{
  vector<EntityIndex> freeEntities;
  int entityCount = 0;
public:
  float time = 0;
  // Component vectors

  vector
  EntityIndex registerEntity(Entity entity){
    EntityIndex entityIndex;
    if (!freeEntities.empty()) {
      entityIndex = freeEntities.back();
      freeEntities.pop_back();
      entity.entityIndex = entityIndex;
    } else {
      entityIndex.index = entityCount++;
      entityIndex.generation = 0;
      entity.entityIndex = entityIndex;
    }
    entities.push_back(entity);
    return entityIndex;
  };

  void freeEntity(EntityIndex entityIndex) {
    for(vector<Entity>::iterator it = entities.begin(); it != entities.end(); ++it) {
      if ((*it).entityIndex == entityIndex) {
        EntityIndex entityIndex = (*it).entityIndex;
        entityIndex.generation++;
        freeEntities.push_back(entityIndex);
        entities.erase(it);
        return;
      }
    }
  }

};

// Draw system
void drawHandler(State& state, sf::RenderWindow& window, float time);

// Physics system
void physicsHandler(State& state, float time);

void soundHandler(State& state, sf::Keyboard Keyboard);
