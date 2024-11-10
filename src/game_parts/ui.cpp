#include "ui.h"
#include "block.h"
#include "colours.h"
#include <cstdio>
#include <raylib.h>

void UI::Paint(int score, Block nextBlock, bool isGameOver) {
  DrawScore(score);
  DrawNextBlock(nextBlock);
  DrawGameOver(isGameOver);
}

void UI::DrawScore(int score) {
  DrawText("Score", 360, 15, 38, WHITE);
  DrawRectangleRounded({320, 55, 200, 60}, 0.3, 6, lightBlue);

  char scoreText[10];
  sprintf(scoreText, "%d", score);
  int textWidth = MeasureText(scoreText, 38);
  DrawText(scoreText, 360 + (120 - textWidth) / 2, 65, 38, WHITE);
}

void UI::DrawNextBlock(Block nextBlock) {
  DrawText("Next", 375, 175, 38, WHITE);
  DrawRectangleRounded({320, 215, 200, 180}, 0.3, 6, lightBlue);

  switch (nextBlock.id) {
  case 3:
    nextBlock.Draw(275, 285);
    break;
  case 4:
    nextBlock.Draw(275, 270);
    break;
  default:
    nextBlock.Draw(290, 270);
  }
}

void UI::DrawGameOver(bool isGameOver) {
  if (isGameOver) {
    DrawText("Game Over!", 320, 450, 38, WHITE);
  }
}
