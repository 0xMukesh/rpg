#include "utils.h"
#include "common.h"
#include <new>

void utils::DrawHoverableText(const char *text, float x, float y,
                              float fontSize, Color normalColor,
                              Color hoverColor) {
  float textWidth = MeasureText(text, fontSize);
  float textHeight = fontSize;

  Rectangle bounds = Rectangle{x, y, textWidth, textHeight};
  Vector2 mousePos = GetMousePosition();
  bool hovering = CheckCollisionPointRec(mousePos, bounds);

  DrawText(text, x, y, fontSize, hovering ? hoverColor : normalColor);
}

void utils::game_pages::InitializeWelcomePage(GameContext &ctx) {
  const char *title = "silly game";
  const char *subtitle = "choose character";
  Rectangle titleBounds = text_bounds::GetWelcomePageTitleRectBounds(title);
  Rectangle subtitleBounds =
      text_bounds::GetWelcomePageSubtitleRectBounds(subtitle);

  new (&ctx.pageState.welcome)
      WelcomePageText{title, subtitle, titleBounds, subtitleBounds};
}

void utils::game_pages::ChangeGamePage(GameContext &ctx, GamePage newPage) {
  switch (ctx.page) {
  case GAME_PAGE_WELCOME:
    ctx.pageState.welcome.~WelcomePageText();
    break;
  case GAME_PAGE_IN_GAME:
    break;
  }

  ctx.page = newPage;

  switch (newPage) {
  case GAME_PAGE_WELCOME:
    utils::game_pages::InitializeWelcomePage(ctx);
    break;
  case GAME_PAGE_IN_GAME:
    break;
  }
}

Rectangle
utils::text_bounds::GetWelcomePageSubtitleRectBounds(const char *subtitle) {
  float subtitleFontSize = 20.0f;
  float subtitleWidth = MeasureText(subtitle, subtitleFontSize);

  float x = SCREEN_WIDTH / 2.0f - subtitleWidth / 2.0f;
  float y = SCREEN_HEIGHT / 2.0f + 30;

  Rectangle bounds = Rectangle{x, y, subtitleWidth, subtitleFontSize};
  return bounds;
}

Rectangle utils::text_bounds::GetWelcomePageTitleRectBounds(const char *title) {
  float titleFontSize = 50.0f;
  float titleWidth = MeasureText(title, titleFontSize);

  float x = SCREEN_WIDTH / 2.0f - titleWidth / 2.0f;
  float y = SCREEN_HEIGHT / 2.0f - 50;

  Rectangle bounds = Rectangle{x, y, titleWidth, titleFontSize};
  return bounds;
}
