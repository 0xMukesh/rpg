#include "scene.h"

Scene::Scene(float height, float width, std::vector<Object> objs)
    : height(height), width(width), objs(objs) {}

void Scene::handleScene() {
  for (auto &obj : objs) {
    obj.handleBoundaryCollision(height, width);
    obj.handleKeyboardInput();
    obj.accelerate(0, 9.81 / 50);
    obj.updatePosition();
    obj.drawCircle();
  }

  for (size_t i = 0; i < objs.size(); i++) {
    Object &a = objs[i];
    for (size_t j = i + 1; j < objs.size(); j++) {
      Object &b = objs[j];

      if (a.doesCollide(b)) {
        DrawText("Collision!", 10, 10 + 20 * i, 20, RED);

        a.velocity.x *= -1;
        a.velocity.y *= -1;
        b.velocity.x *= -1;
        b.velocity.y *= -1;
      }
    }
  }
}
