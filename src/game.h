#pragma once

#include "blocks.cpp"
#include "grid.h"

class Game {
public:
  Game();
  Grid grid;
  Block getRandomBlock();

  Block currentBlock;
  Block nextBlock;

  void draw();
  void handleInput();
  void moveLeft();
  void moveRight();
  void moveDown();

private:
  std::vector<Block> blocks;
  std::vector<Block> getAllBlocks();
};
