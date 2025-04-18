#include "scene.h"
#include "constants.h"

Scene::Scene(float width, float height, std::vector<Object> objs)
    : width(width), height(height), objs(objs) {}

void Scene::update(float dt) {
  for (auto &obj : objs) {
    obj.accelerate(Vector2{0, constants::g * dt});
    obj.updatePosition(dt);
    handleBoundaryCollision(obj);
  }

  for (size_t i = 0; i < objs.size(); i++) {
    auto &obj = objs[i];
    for (size_t j = i + 1; j < objs.size(); j++) {
      auto &obj2 = objs[j];
      obj.handleCollision(obj2);
    }
  }
}

void Scene::render() {
  for (auto &obj : objs) {
    obj.drawCircle();
  }
}

void Scene::handleBoundaryCollision(Object &obj) {
  if (obj.position.y + obj.radius > height) {
    obj.velocity.y =
        std::abs(obj.velocity.y) < 0.5f ? 0 : -obj.velocity.y * 0.7f;
    obj.position.y = height - obj.radius;
  }

  if (obj.position.y - obj.radius < 0) {
    obj.velocity.y =
        std::abs(obj.velocity.y) < 0.5f ? 0 : -obj.velocity.y * 0.7f;
    obj.position.y = obj.radius;
  }

  if (obj.position.x - obj.radius < 0) {
    obj.velocity.x =
        std::abs(obj.velocity.x) < 0.5f ? 0 : -obj.velocity.x * 0.7f;
    obj.position.x = obj.radius;
  }

  if (obj.position.x + obj.radius > width) {
    obj.velocity.x =
        std::abs(obj.velocity.x) < 0.5f ? 0 : -obj.velocity.x * 0.7f;
    obj.position.x = width - obj.radius;
  }
}
