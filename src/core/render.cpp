#include "render.h"
#include "../common.h"

void GameRender(GameContext &ctx) {
  BeginMode2D(ctx.camera);

  Tile tile;

  for (int i = 0; i < WORLD_WIDTH; i++) {
    for (int j = 0; j < WORLD_HEIGHT; j++) {
      tile = ctx.world[i][j];

      float texture_idx_x;
      float texture_idx_y;

      switch (tile.type) {
      case TILE_TYPE_DIRT:
        texture_idx_x = 4;
        texture_idx_y = 4;
        break;
      case TILE_TYPE_GRASS:
        texture_idx_x = 5;
        texture_idx_y = 4;
        break;
      case TILE_TYPE_DEFAULT_TREE:
        texture_idx_x = 5;
        texture_idx_y = 5;
        break;
      case TILE_TYPE_PINE_TREE:
        texture_idx_x = 4;
        texture_idx_y = 5;
        break;
      case TILE_TYPE_BEACH_TREE:
        texture_idx_x = 7;
        texture_idx_y = 5;
        break;
      }

      Rectangle src =
          Rectangle{TILE_WIDTH * texture_idx_x, TILE_HEIGHT * texture_idx_y,
                    TILE_WIDTH, TILE_HEIGHT};
      Rectangle dest =
          Rectangle{(float)(TILE_WIDTH * tile.x), (float)(TILE_HEIGHT * tile.y),
                    TILE_WIDTH, TILE_HEIGHT};

      DrawTexturePro(ctx.textures[TEXTURE_TILEMAP], src, dest,
                     Vector2{0.0f, 0.0f}, 0.0f, WHITE);
    }
  }

  Rectangle src =
      Rectangle{TILE_WIDTH * 4, TILE_HEIGHT * 0, TILE_WIDTH, TILE_HEIGHT};
  Rectangle dest = Rectangle{ctx.camera.target.x, ctx.camera.target.y,
                             TILE_WIDTH, TILE_HEIGHT};

  DrawTexturePro(ctx.textures[TEXTURE_TILEMAP], src, dest, Vector2{0.0f, 0.0f},
                 0.0f, WHITE);

  EndMode2D();
}
