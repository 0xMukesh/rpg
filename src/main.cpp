#include "common.h"
#include "core/render.h"
#include "core/shutdown.h"
#include "core/startup.h"
#include "raylib.h"

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RPG");
  SetTargetFPS(60);

  GameContext ctx;

  while (!WindowShouldClose()) {
    GameStartup(ctx);

    BeginDrawing();
    ClearBackground(BLACK);
    GameRender(ctx);
    EndDrawing();
  }

  GameShutdown(ctx);
  CloseWindow();

  return 0;
}