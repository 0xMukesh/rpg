#include "update.h"
#include "../ui/ui.h"
#include "../utils/utils.h"
#include <raylib.h>

void HandleWelcomePage(GameContext &ctx) {
  if (ctx.page != GAME_PAGE_WELCOME)
    return;

  auto layout = ui::ComputeWelcomePageLayout(ctx.pageState.welcome.title,
                                             ctx.pageState.welcome.subtitle);

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    bool clickedSubtitle =
        CheckCollisionPointRec(mousePos, layout.subtitleBounds);

    if (clickedSubtitle) {
      utils::game_pages::ChangeGamePage(ctx, GAME_PAGE_CHARACTER_SELECTION);
    }
  }
}

void HandleCharacterSelectionPage(GameContext &ctx) {
  if (ctx.page != GAME_PAGE_CHARACTER_SELECTION)
    return;

  auto layout = ui::ComputeCharacterSelectionPageLayout(
      ctx.pageState.characterSelection.title,
      ctx.pageState.characterSelection.maleText,
      ctx.pageState.characterSelection.femaleText);

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();
    bool selectedMaleCharacter =
        CheckCollisionPointRec(mousePos, layout.maleTextBounds);
    bool selectedFemaleCharacter =
        CheckCollisionPointRec(mousePos, layout.femaleTextBounds);

    if (selectedMaleCharacter) {
      ctx.player.type = PLAYER_TYPE_MALE;
      utils::game_pages::ChangeGamePage(ctx, GAME_PAGE_IN_GAME);
    }

    if (selectedFemaleCharacter) {
      ctx.player.type = PLAYER_TYPE_FEMALE;
      utils::game_pages::ChangeGamePage(ctx, GAME_PAGE_IN_GAME);
    }
  }
}

void HandleMainGamePage(GameContext &ctx) {
  float wheel = GetMouseWheelMove();

  if (wheel != 0) {
    ctx.camera.zoom += (wheel * 0.125);

    if (ctx.camera.zoom < 1.25)
      ctx.camera.zoom = 1.25;
    if (ctx.camera.zoom > 5.0)
      ctx.camera.zoom = 5.0;
  }

  float pos_x_inc = 0.0f;
  float pos_y_inc = 0.0f;

  if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    pos_x_inc -= TILE_WIDTH;
  if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    pos_x_inc += TILE_WIDTH;
  if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
    pos_y_inc -= TILE_HEIGHT;
  if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
    pos_y_inc += TILE_HEIGHT;

  int next_block_x = (int)(ctx.player.position.x + pos_x_inc) / TILE_WIDTH;
  int next_block_y = (int)(ctx.player.position.y + pos_y_inc) / TILE_HEIGHT;

  Tile next_block = ctx.world[next_block_x][next_block_y];

  if ((next_block.type == TILE_TYPE_DIRT ||
       next_block.type == TILE_TYPE_GRASS) &&
      next_block_x >= 0 && next_block_y >= 0) {
    ctx.player.position.x += pos_x_inc;
    ctx.player.position.y += pos_y_inc;
  }

  ctx.camera.target = ctx.player.position;
}

void GameUpdate(GameContext &ctx) {
  switch (ctx.page) {
  case GAME_PAGE_WELCOME:
    HandleWelcomePage(ctx);
    break;
  case GAME_PAGE_CHARACTER_SELECTION:
    HandleCharacterSelectionPage(ctx);
    break;
  case GAME_PAGE_IN_GAME:
    HandleMainGamePage(ctx);
    break;
  }
}
