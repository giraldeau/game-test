#include "systems.hpp"

using namespace std;

void physicsHandler(State state, float time) {
  size_t index = 0;
  for(vector<EntityPointers>::iterator it = state.entityPointers.begin(); it != state.entityPointers.end(); ++it) {
    if (state.hasComponents(index++, F_PHYSICS)) {
      it->physics->velocity.x += it->physics->acceleration.x * time;
      it->physics->velocity.y += it->physics->acceleration.y * time;
      it->physics->velocity.x += it->physics->friction * time;
      it->physics->velocity.y += it->physics->friction * time;
      it->position->x += it->physics->velocityx * time;
      it->position->y += it->physics->velocity.y * time;
    }
  }
}
