#include "ui.h"
#include "colours.h"
#include <iostream>
#include <raylib.h>

void UI::paint(int score, bool isGameOver) {
  drawScore(score);
  drawNextBlock();
  drawGameOver(isGameOver);
}

void UI::drawScore(int score) {
  DrawText("Score", 360, 15, 38, WHITE);
  DrawRectangleRounded({320, 55, 200, 60}, 0.3, 6, lightBlue);

  char scoreText[10];
  sprintf(scoreText, "%d", score);
  int textWidth = MeasureText(scoreText, 38);
  DrawText(scoreText, 360 + (120 - textWidth) / 2, 65, 38, WHITE);
}

void UI::drawNextBlock() {
  DrawText("Next", 375, 175, 38, WHITE);
  DrawRectangleRounded({320, 215, 200, 180}, 0.3, 6, lightBlue);
}

void UI::drawGameOver(bool isGameOver) {
  if (isGameOver) {
    DrawText("Game Over!", 320, 450, 38, WHITE);
  }
}
