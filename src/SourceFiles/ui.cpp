#include "../HeaderFiles/ui.h"
#include "../HeaderFiles/block.h"
#include "../HeaderFiles/colours.h"
#include <cstdio>
#include <raylib.h>

void UI::paint(int score, Block nextBlock, bool isGameOver) {
  drawScore(score);
  drawNextBlock(nextBlock);
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

void UI::drawNextBlock(Block nextBlock) {
  DrawText("Next", 375, 175, 38, WHITE);
  DrawRectangleRounded({320, 215, 200, 180}, 0.3, 6, lightBlue);

  switch (nextBlock.id) {
  case 3:
    nextBlock.draw(275, 285);
    break;
  case 4:
    nextBlock.draw(275, 270);
    break;
  default:
    nextBlock.draw(290, 270);
  }
}

void UI::drawGameOver(bool isGameOver) {
  if (isGameOver) {
    DrawText("Game Over!", 320, 450, 38, WHITE);
  }
}
