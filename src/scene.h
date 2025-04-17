#pragma once

#include "object.h"
#include <vector>

class Scene {
public:
  float height;
  float width;

  Scene(float height, float width, std::vector<Object> objs);
  void handleScene();

private:
  std::vector<Object> objs;
};
