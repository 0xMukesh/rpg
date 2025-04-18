#include "scene.h"
#include <cmath>

Scene::Scene(float height, float width, std::vector<Object> objs)
    : height(height), width(width), objs(objs) {}

void Scene::addObject(Object &obj) { objs.push_back(obj); }

void Scene::handleScene() {
  for (auto &obj : objs) {
    // obj.handleKeyboardInput();
    // obj.accelerate(0, 9.81 / 50);
    obj.handleBoundaryCollision(height, width);
    obj.updatePosition();
    obj.drawCircle();

    for (auto &obj2 : objs) {
      if (&obj == &obj2) {
        continue;
      }

      float dx = obj2.position.x - obj.position.x;
      float dy = obj2.position.y - obj.position.y;
      float dist = sqrt(dx * dx + dy * dy);

      if (dist < 1.0f)
        continue;

      float nx = (dx / dist), ny = (dy / dist);

      float force =
          (6.67430 * pow(10, -7) * obj.mass * obj2.mass) / (dist * dist);
      float acc = force / obj.mass;

      obj.accelerate(acc * nx, acc * ny);
    }
  }

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    Object obj = Object(mousePos, Vector2{0, 0}, 10, 100);
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
