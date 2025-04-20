#include "common.h"
#include "context.h"
#include "core/render.h"
#include "core/shutdown.h"
#include "core/startup.h"
#include "raylib.h"

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RPG");
  SetTargetFPS(60);

  GameContext ctx;
  GameStartup(ctx);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    GameRender(ctx);
    EndDrawing();
  }

  GameShutdown(ctx);
  CloseWindow();

  return 0;
}