#include "utils.h"

Rectangle
utils::text_bounds::GetWelcomePageSubtitleBounds(const char *subtitle) {
  float subtitleFontSize = 20.0f;
  float subtitleWidth = MeasureText(subtitle, subtitleFontSize);
  float subtitleX = SCREEN_WIDTH / 2.0f - subtitleWidth / 2.0f;
  float subtitleY = SCREEN_HEIGHT / 2.0f + 30;

  Rectangle subtitleBounds =
      Rectangle{subtitleX, subtitleY, subtitleWidth, subtitleFontSize};
  return subtitleBounds;
}

Rectangle
utils::text_bounds::GetCharacterSelectionMaleTextBounds(const char *maleText) {
  float maleTextFontSize = 28.0f;
  float maleTextWidth = MeasureText(maleText, maleTextFontSize);
  float maleTextX = SCREEN_WIDTH / 2.0f - maleTextWidth / 2.0f - 50;
  float maleTextY = SCREEN_HEIGHT / 2.0f - 80;

  Rectangle maleTextBounds =
      Rectangle{maleTextX, maleTextY, maleTextWidth, maleTextFontSize};
  return maleTextBounds;
}

Rectangle utils::text_bounds::GetCharacterSelectionFemaleTextBounds(
    const char *femaleText) {
  float femaleTextFontSize = 28.0f;
  float femaleTextWidth = MeasureText(femaleText, femaleTextFontSize);
  float femaleTextX = SCREEN_WIDTH / 2.0f - femaleTextWidth / 2.0f + 50;
  float femaleTextY = SCREEN_HEIGHT / 2.0f - 80;

  Rectangle femaleTextBounds =
      Rectangle{femaleTextX, femaleTextY, femaleTextWidth, femaleTextFontSize};
  return femaleTextBounds;
}
