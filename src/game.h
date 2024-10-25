#pragma once

#include "blocks.cpp"
#include "grid.h"

class Game {
public:
  Game();
  Grid grid;
  Block getRandomBlock();
  std::vector<Block> getAllBlocks();

  void draw();
  void handleInput();
  void moveBlockLeft();
  void moveBlockRight();
  void moveBlockDown();

  int score = 0;
  bool isGameOver = false;

private:
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  bool isBlockOutOfBounds();
  bool doesBlockFit();
  void lockBlock();
  void rotateBlock();
  void reset();
  void updateScore(int linesCleared, int moveDownPoints);
};
