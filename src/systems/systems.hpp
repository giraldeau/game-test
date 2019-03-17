#pragma once
#include "../components.hpp"
using namespace std;

// State system
struct EntityIndex{
  int index;
  int generation;
};

inline bool operator==(const EntityIndex& lhs, const EntityIndex& rhs) {
    return ((lhs.index == rhs.index) && (lhs.generation == rhs.generation));
}

struct Entity{
  EntityIndex entityIndex;
  Physics physics;
  bool hasPhysics;
  Graphics* graphics;
  bool hasGraphics;
  Pos position;
  bool hasPosition;
};


class State{
  vector<EntityIndex> freeEntities;
  int entityCount = 0;
public:
   int frameCount = 0;
  vector<Entity> entities;
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
void drawHandler(State& state, sf::RenderWindow& window);

// Physics system
void physicsHandler(State& state, float time);
