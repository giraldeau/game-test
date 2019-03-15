#include "../components.hpp"
using namespace std;

// State system
struct Entity{
  Physics physics;
  bool hasPhysics;
  Graphics graphics;
  bool hasGraphics;
  Pos position;
  bool hasPosition;
};

struct EntityIndex {
  int index;
  int generation;
};

class State{
  vector<EntityIndex> entityRegistry;
  vector<EntityIndex> freeEntities;
public:
  vector<Entity> entities;
  void registerEntity(Entity){};
};

// Draw system
int drawHandler(sf::RenderWindow window, vector<Entity> v);

// Physics system
State physicsHandler(State state, float time);
