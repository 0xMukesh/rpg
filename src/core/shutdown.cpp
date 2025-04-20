#include "shutdown.h"

void GameShutdown(GameContext &ctx) {
  for (int i = 0; i < MAX_TEXTURES; i++) {
    UnloadTexture(ctx.textures[i]);
  }
}
