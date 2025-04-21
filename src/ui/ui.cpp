#include "ui.h"
#include "../common.h"

WelcomePageLayout ui::ComputeWelcomePageLayout(const char *title,
                                               const char *subtitle) {
  float titleFontSize = 50.0f;
  float subtitleFontSize = 24.0f;
  float spacingBetween = 20.0f;

  float titleWidth = MeasureText(title, titleFontSize);
  float subtitleWidth = MeasureText(subtitle, subtitleFontSize);

  float totalHeight = titleFontSize + spacingBetween + subtitleFontSize;
  float startY = (SCREEN_HEIGHT / 2.0f) - (totalHeight / 2.0f) - 50;

  Rectangle titleBounds = {(SCREEN_WIDTH - titleWidth) / 2.0f, startY,
                           titleWidth, titleFontSize};

  Rectangle subtitleBounds = {(SCREEN_WIDTH - subtitleWidth) / 2.0f,
                              startY + titleFontSize + spacingBetween,
                              subtitleWidth, subtitleFontSize};

  return {titleBounds, subtitleBounds};
}

CharacterSelectionPageLayout
ui::ComputeCharacterSelectionPageLayout(const char *title, const char *maleText,
                                        const char *femaleText) {
  float titleFontSize = 30.0f;
  float choicesFontSize = 24.0f;
  float titleTopPadding = 50.0f;
  float spacingBetween = 80.0f;

  float maleWidth = MeasureText(maleText, choicesFontSize);
  float femaleWidth = MeasureText(femaleText, choicesFontSize);
  float titleWidth = MeasureText(title, titleFontSize);

  float choicesTotalWidth = maleWidth + spacingBetween + femaleWidth;

  float startX = (SCREEN_WIDTH - choicesTotalWidth) / 2.0f;

  float maleX = startX;
  float femaleX = startX + maleWidth + spacingBetween;
  float choicesY = SCREEN_HEIGHT / 2.0f;

  float centerOfChoices = (maleX + femaleX + femaleWidth) / 2.0f;
  float titleX = centerOfChoices - (titleWidth / 2.0f);
  float titleY = choicesY - titleFontSize - titleTopPadding;

  Rectangle titleBounds = {titleX, titleY, titleWidth, titleFontSize};
  Rectangle maleBounds = {maleX, choicesY, maleWidth, choicesFontSize};
  Rectangle femaleBounds = {femaleX, choicesY, femaleWidth, choicesFontSize};

  return {titleBounds, maleBounds, femaleBounds};
}
