#include "systems.hpp"

// TODO : Make every component a derived class of a Component struct
// Component struct comtains :
//          f_component flags;
//          EntityPointers* entity;

template <typename T>
void addComponent(T* component, f_componentList flag,  EntityPointers* entityPointers) {
  entityPointers->componentFlags |= flag;
  if (flag & F_PHYSICS) {
    entityPointers->physics = component;
  }
  if (flag & F_GRAPHICS) {
    entityPointers->graphics = component;
  }
  if (flag & F_COLLISION) {
    entityPointers->collision = component;
  }
  if (flag & F_POSITION) {
    entityPointers->position = component;
  }
}

State::State() {

}

// Register components into state component vectors,
// update entityPointers in state accordingly
template <typename T>
void registerComponent(void* componentPtr, f_componentList type, vector<T> &vec, EntityPointers* entityPtr) {
  if (componentPtr) {
    if (type & F_PHYSICS){
      (Physics*)entityPtr->physics = &vec.back();
      (Physics*)componentPtr->entity = entityPtr;
      vec.push_back(*componentPtr);
    }
    else if (type & F_GRAPHICS) {
      (Graphics*)entityPtr->graphics = &vec.back();
      (Graphics*)componentPtr->entity = entityPtr;
      vec.push_back(*componentPtr);
    }
    else if (type & F_COLLISION) {
      (Collision*)entityPtr->collision = &vec.back();
      (Collision*)componentPtr->entity = entityPtr;
      vec.push_back(*componentPtr);
    }
    else if (type & F_POSITION) {
      (Position*)entityPtr->position = &vec.back();
      (Position*)componentPtr->entity = entityPtr;
      vec.push_back(*componentPtr);
    }
    vec.push_back(*componentPtr);
  }
}

Entity State::registerEntity(EntityPointers pointers) {
  entityPointers.push_back(pointers);
  EntityPointers* ptr = &entityPointers.back();
  registerComponent(ptr->physics, F_PHYSICS, physicsComponents, ptr);
  registerComponent(ptr->graphics, F_GRAPHICS, graphicsComponents, ptr);
  registerComponent(ptr->collision, F_COLLISION, collisionComponents, ptr);
  registerComponent(ptr->position, F_POSITION, positionComponents, ptr);

  return entityPointers.size()-1;
}

void State::registerComponents(Entity entity, EntityPointers *entityPtr) {
  EntityPointers* ptr = &entityPointers[entity];
  if (ptr->componentFlags) {
    registerComponent(entityPtr->physics, F_PHYSICS, physicsComponents, ptr);
    registerComponent(entityPtr->graphics, F_GRAPHICS, graphicsComponents, ptr);
    registerComponent(entityPtr->collision, F_COLLISION, collisionComponents, ptr);
    registerComponent(entityPtr->position, F_POSITION, positionComponents, ptr);
  }
}

void State::removeComponents(Entity entity, f_componentList flags) {
  EntityPointers ptrs = entityPointers[entity];
  // Disable flags in entityPointers
  ptrs.componentFlags &= ~flags;

  // Set disabled flag in disabled components
  if (flags & F_PHYSICS) ptrs.physics->flags |= F_CREMOVED;
  if (flags & F_GRAPHICS) ptrs.graphics->flags |= F_CREMOVED;
  if (flags & F_COLLISION) ptrs.collision->flags |= F_CREMOVED;
  if (flags & F_POSITION) ptrs.position->flags |= F_CREMOVED;
}

void State::removeEntity(Entity entity) {
  EntityPointers *ptr = &entityPointers[entity];
  ptr->componentFlags = 0;
  if (ptr->componentFlags & F_PHYSICS) ptr->physics->flags |= F_CREMOVED;
  if (ptr->componentFlags & F_GRAPHICS) ptr->graphics->flags |= F_CREMOVED;
  if (ptr->componentFlags & F_COLLISION) ptr->collision->flags |= F_CREMOVED;
  if (ptr->componentFlags & F_POSITION) ptr->position->flags |= F_CREMOVED;
}

bool State::hasComponents(Entity entity, f_componentList flags) {
  return (entityPointers[entity].componentFlags & flags) == flags;
}

template <typename T>
void freeRemovedComponent(T *&componentPtr, size_t &offset, size_t &index, f_componentList flags, f_componentList flag, vector<T> vec) {
    if (componentPtr) {
      componentPtr -= offset;
      if (flags & flag) index++;
      else {
        typename vector<T>::iterator it = vec.begin();
        advance(it, index);
        offset++;
        vec.erase(it);
    }
  }
}

void State::freeMemory() {
  size_t physicsOffset = 0;
  size_t graphicsOffset = 0;
  size_t collisionOffset = 0;
  size_t positionOffset = 0;

  size_t physicsIndex = 0;
  size_t graphicsIndex = 0;
  size_t collisionIndex = 0;
  size_t positionIndex = 0;

  using iterator = vector<EntityPointers>::iterator;
  for(iterator it = entityPointers.begin(); it != entityPointers.end(); ++it) {
    freeRemovedComponent(it->physics, physicsOffset, physicsIndex, it->componentFlags, F_PHYSICS, physicsComponents);
    freeRemovedComponent(it->graphics, graphicsOffset, graphicsIndex, it->componentFlags, F_GRAPHICS, graphicsComponents);
    freeRemovedComponent(it->collision, collisionOffset, collisionIndex, it->componentFlags, F_COLLISION, collisionComponents);
    freeRemovedComponent(it->position, positionOffset, positionIndex, it->componentFlags, F_POSITION, positionComponents);
  }
}
