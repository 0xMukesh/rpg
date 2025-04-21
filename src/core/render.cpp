#include "render.h"
#include "../common.h"
#include "../utils/utils.h"
#include "raylib.h"
#include <cmath>

void RenderWelcomePage(GameContext &ctx) {
  DrawText(ctx.pageState.welcome.title, ctx.pageState.welcome.titleBounds.x,
           ctx.pageState.welcome.titleBounds.y,
           ctx.pageState.welcome.titleBounds.height, WHITE);
  utils::DrawHoverableText(
      ctx.pageState.welcome.subtitle, ctx.pageState.welcome.subtitleBounds.x,
      ctx.pageState.welcome.subtitleBounds.y,
      ctx.pageState.welcome.subtitleBounds.height, WHITE, YELLOW);
}

void RenderCharacterSelectionPage(GameContext &ctx) {
  DrawText(ctx.pageState.characterSelection.title,
           ctx.pageState.characterSelection.titleBounds.x,
           ctx.pageState.characterSelection.titleBounds.y,
           ctx.pageState.characterSelection.titleBounds.height, WHITE);
  utils::DrawHoverableText(
      ctx.pageState.characterSelection.maleText,
      ctx.pageState.characterSelection.maleTextBounds.x,
      ctx.pageState.characterSelection.maleTextBounds.y,
      ctx.pageState.characterSelection.maleTextBounds.height, WHITE, YELLOW);
  utils::DrawHoverableText(
      ctx.pageState.characterSelection.femaleText,
      ctx.pageState.characterSelection.femaleTextBounds.x,
      ctx.pageState.characterSelection.femaleTextBounds.y,
      ctx.pageState.characterSelection.femaleTextBounds.height, WHITE, YELLOW);
}

void RenderMainGame(GameContext &ctx) {
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

  float player_texture_idx = ctx.player.type == PLAYER_TYPE_MALE ? 4 : 8;

  Rectangle src = Rectangle{TILE_WIDTH * player_texture_idx, TILE_HEIGHT * 0,
                            TILE_WIDTH, TILE_HEIGHT};
  Rectangle dest = Rectangle{ctx.camera.target.x, ctx.camera.target.y,
                             TILE_WIDTH, TILE_HEIGHT};

  DrawTexturePro(ctx.textures[TEXTURE_TILEMAP], src, dest, Vector2{0.0f, 0.0f},
                 0.0f, WHITE);

  EndMode2D();
}

void GameRender(GameContext &ctx) {
  switch (ctx.page) {
  case GAME_PAGE_WELCOME:
    RenderWelcomePage(ctx);
    break;
  case GAME_PAGE_CHARACTER_SELECTION:
    RenderCharacterSelectionPage(ctx);
    break;
  case GAME_PAGE_IN_GAME:
    RenderMainGame(ctx);
    break;
  }
}
