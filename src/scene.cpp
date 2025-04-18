#include "scene.h"

Scene::Scene(float height, float width, std::vector<Object> objs)
    : height(height), width(width), objs(objs) {}

void Scene::addObject(Object &obj) { objs.push_back(obj); }

void Scene::handleScene() {
  for (auto &obj : objs) {
    obj.handleBoundaryCollision(height, width);
    obj.handleKeyboardInput();
    obj.accelerate(0, 9.81 / 50);
    obj.updatePosition();
    obj.drawCircle();
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Object obj = Object(mousePos, Vector2{0, 0}, 10);
    addObject(obj);
  }

  for (size_t i = 0; i < objs.size(); i++) {
    Object &a = objs[i];
    for (size_t j = i + 1; j < objs.size(); j++) {
      Object &b = objs[j];

      a.resolveCollision(b);
    }
  }
}
