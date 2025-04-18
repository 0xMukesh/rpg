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
  const float width = 1200;
  const float height = 1000;

  InitWindow(width, height, "gravity sim");
  SetTargetFPS(120);

  std::vector<Object> objs = {
      Object(Vector2{600, 500}, Vector2{0, 0}, 30, 1e10), // central mass
      Object(Vector2{600, 300}, Vector2{4, 0}, 10, 1)     // orbiting body
  };

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