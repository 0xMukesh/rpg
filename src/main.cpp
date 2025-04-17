#include "object.h"
#include "raylib.h"
#include "scene.h"
#include <cmath>
#include <vector>

struct Ball {
  Vector2 position;
  Vector2 velocity;
  float radius;
  Color color;
};

bool checkCollision(const Object &a, const Object &b) {
  float dx = a.position.x - b.position.x;
  float dy = a.position.y - b.position.y;
  float dist = std::sqrt(dx * dx + dy * dy);
  return dist < a.radius + b.radius;
}

int main() {
  const float width = 800;
  const float height = 1000;

  InitWindow(width, height, "gravity sim");
  SetTargetFPS(120);

  std::vector<Object> objs = {
      Object(Vector2{width / 2 + 50, height * 0.2f}, Vector2{0, 0}, 20),
      Object(Vector2{width / 2 - 50, height * 0.2f}, Vector2{0, 0}, 20)};

  Scene scene = Scene(height, width, objs);

  while (!WindowShouldClose()) {
    scene.handleScene();
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}