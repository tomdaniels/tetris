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
  void moveLeft();
  void moveRight();
  void moveDown();

private:
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  bool isBlockOutOfBounds();
  void rotateBlock();
};
