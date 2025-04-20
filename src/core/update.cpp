#include "update.h"
#include <iostream>
#include <raylib.h>

void GameUpdate(GameContext &ctx) {
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
