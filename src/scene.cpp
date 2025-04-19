#include "scene.h"
#include "constants.h"
#include "utils.h"
#include <cmath>

Scene::Scene(float width, float height, std::vector<Object> objs)
    : width(width), height(height), objs(objs) {}

void Scene::update(float dt) {
  for (auto &obj : objs) {
    if (!obj.isGrounded) {
      obj.accelerate(Vector2{0, constants::g * dt});
      obj.updatePosition(dt);
    }

    handleBoundaryCollision(obj);
  }

  for (size_t i = 0; i < objs.size(); i++) {
    auto &obj = objs[i];
    for (size_t j = i + 1; j < objs.size(); j++) {
      auto &obj2 = objs[j];
      obj.handleCollision(obj2, width, height);
    }
  }

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    Vector2 mousePos = GetMousePosition();
    Object randomObj = utils::randomObject(mousePos);

    objs.push_back(randomObj);
  }
}

void Scene::render() {
  for (auto &obj : objs) {
    obj.drawCircle();
  }
}

void Scene::handleBoundaryCollision(Object &obj) {
  if (obj.position.x + obj.radius > width) {
    obj.position.x = width - obj.radius;
    obj.velocity.x = -0.8f * obj.velocity.x;
  }

  if (obj.position.x - obj.radius < 0) {
    obj.position.x = obj.radius;
    obj.velocity.x = -0.8f * obj.velocity.x;
  }

  if (obj.position.y - obj.radius < 0) {
    obj.position.y = obj.radius;
    obj.velocity.y = -0.8f * obj.velocity.y;
  }

  if (obj.position.y + obj.radius > height) {
    obj.position.y = height - obj.radius;

    if (std::abs(obj.velocity.y) < constants::REST_THRESHOLD) {
      obj.velocity.x = 0.0f;
      obj.velocity.y = 0.0f;
      obj.isGrounded = true;
    } else {
      obj.velocity.y = -0.8f * obj.velocity.y;
    }
  }
}