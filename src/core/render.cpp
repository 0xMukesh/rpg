#include "render.h"
#include "../common.h"

void GameRender(GameContext &ctx) {
  for (int i = 0; i < SCREEN_WIDTH / TILE_WIDTH; i++) {
    for (int j = 0; j < SCREEN_HEIGHT / TILE_HEIGHT; j++) {
      Tile tile = {i, j};

      Rectangle src =
          Rectangle{TILE_WIDTH * 5, TILE_HEIGHT * 4, TILE_WIDTH, TILE_HEIGHT};
      Rectangle dest =
          Rectangle{(float)(tile.x * TILE_WIDTH), (float)(tile.y * TILE_HEIGHT),
                    TILE_WIDTH, TILE_HEIGHT};
      DrawTexturePro(ctx.textures[TEXTURE_TILEMAP], src, dest, Vector2{0, 0}, 0,
                     WHITE);
    }
  }
}
