#include "../ui/ui.h"
#include "utils.h"
#include <new>

void utils::game_pages::InitializeWelcomePage(GameContext &ctx) {
  const char *title = "Silly Game";
  const char *subtitle = "Enter the game";

  auto layout = ui::ComputeWelcomePageLayout(title, subtitle);

  new (&ctx.pageState.welcome) WelcomePageText{
      title, subtitle, layout.titleBounds, layout.subtitleBounds};
}

void utils::game_pages::InitializeCharacterSelectionPage(GameContext &ctx) {
  const char *title = "Choose your character";
  const char *maleText = "Bob";
  const char *femaleText = "Alice";

  auto layout =
      ui::ComputeCharacterSelectionPageLayout(title, maleText, femaleText);

  new (&ctx.pageState.characterSelection)
      CharacterSelectionPageText{title,
                                 maleText,
                                 femaleText,
                                 layout.titleBounds,
                                 layout.maleTextBounds,
                                 layout.femaleTextBounds};
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
