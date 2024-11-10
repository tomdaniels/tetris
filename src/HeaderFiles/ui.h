#pragma once

#include "block.h"

class UI {
public:
  void Paint(int score, Block nextBlock, bool isGameOver);

private:
  void DrawScore(int score);
  void DrawNextBlock(Block nextBlock);
  void DrawGameOver(bool isGameOver);
};
