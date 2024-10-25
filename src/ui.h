#pragma once

#include "block.h"
class UI {
public:
  void paint(int score, Block nextBlock, bool isGameOver);

private:
  void drawScore(int score);
  void drawNextBlock(Block nextBlock);
  void drawGameOver(bool isGameOver);
};
