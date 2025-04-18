#include "object.h"
#include <vector>

#ifndef SCENE
#define SCENE

class Scene {
public:
  float width;
  float height;
  std::vector<Object> objs;

  Scene(float width, float height, std::vector<Object> objs);
  void update(float dt);
  void render();
  void handleBoundaryCollision(Object &obj);
};

#endif