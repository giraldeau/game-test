#pragma once
#include "../components.hpp"
using namespace std;

// State system
typedef unsigned int Entity;

template <typename T>
void addComponent(T* component, f_componentList,  EntityPointers);

class State{
  vector<Physics> physicsComponents;
  vector<Graphics> graphicsComponents;
  vector<Collision> collisionComponents;
  vector<Position> positionComponents;
public:
  State();
  vector<EntityPointers> entityPointers;
  float time = 0;
  Entity registerEntity(EntityPointers);
  void registerComponents(Entity entity, EntityPointers*);
  bool hasComponents(Entity entity, f_componentList flags);
  void removeComponents(Entity entity, f_componentList flags);
  void removeEntity(Entity entity);
  void freeMemory();
};

// Draw system
void drawHandler(State& state, sf::RenderWindow& window, float time);

// Physics system
void physicsHandler(State& state, float time);

// Sound system
void soundHandler(State& state, sf::Keyboard Keyboard);

// Input system
void inputHandler(State& state, sf::RenderWindow& window);
