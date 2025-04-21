#include "utils.h"
#include <new>

void utils::game_pages::InitializeWelcomePage(GameContext &ctx) {
  const char *title = "Silly Game";
  const char *subtitle = "Choose your character";

  float titleFontSize = 50.0f;
  float titleWidth = MeasureText(title, titleFontSize);
  float titleX = SCREEN_WIDTH / 2.0f - titleWidth / 2.0f;
  float titleY = SCREEN_HEIGHT / 2.0f - 50;

  Rectangle titleBounds = Rectangle{titleX, titleY, titleWidth, titleFontSize};
  Rectangle subtitleBounds =
      text_bounds::GetWelcomePageSubtitleBounds(subtitle);

  new (&ctx.pageState.welcome)
      WelcomePageText{title, subtitle, titleBounds, subtitleBounds};
}

void utils::game_pages::InitializeCharacterSelectionPage(GameContext &ctx) {
  const char *title = "Choose your character";
  const char *maleText = "Bob";
  const char *femaleText = "Alice";

  Rectangle maleTextBounds =
      text_bounds::GetCharacterSelectionMaleTextBounds(maleText);
  Rectangle femaleTextBounds =
      text_bounds::GetCharacterSelectionFemaleTextBounds(femaleText);

  new (&ctx.pageState.characterSelection) CharacterSelectionPageText{
      title, maleText, femaleText, maleTextBounds, femaleTextBounds};
}

void utils::game_pages::ChangeGamePage(GameContext &ctx, GamePage newPage) {
  switch (ctx.page) {
  case GAME_PAGE_WELCOME:
    ctx.pageState.welcome.~WelcomePageText();
    break;
  case GAME_PAGE_CHARACTER_SELECTION:
    ctx.pageState.characterSelection.~CharacterSelectionPageText();
    break;
  case GAME_PAGE_IN_GAME:
    break;
  }

  ctx.page = newPage;

  switch (newPage) {
  case GAME_PAGE_WELCOME:
    utils::game_pages::InitializeWelcomePage(ctx);
    break;
  case GAME_PAGE_CHARACTER_SELECTION:
    utils::game_pages::InitializeCharacterSelectionPage(ctx);
  case GAME_PAGE_IN_GAME:
    break;
  }
}
