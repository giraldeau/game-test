#include "systems.hpp"

using namespace std;

State physicsHandler(State state, float time) {
  for(vector<Entity>::iterator it = state.entities.begin(); it != state.entities.end(); ++it) {
    if ((*it).hasPhysics) {
      (*it).physics.velocity.x += (*it).physics.acceleration.x * time;
      (*it).physics.velocity.y += (*it).physics.acceleration.y * time;
      (*it).physics.velocity.x += (*it).physics.friction * time;
      (*it).physics.velocity.y += (*it).physics.friction * time;
      (*it).position.x += (*it).physics.velocity.x * time;
      (*it).position.y += (*it).physics.velocity.y * time;
    }
  }
  return state;
}
