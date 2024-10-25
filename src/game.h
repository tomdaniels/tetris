#pragma once

#include "blocks.cpp"
#include "grid.h"

class Game {
public:
  Game();
  ~Game();
  Block getRandomBlock();
  std::vector<Block> getAllBlocks();

  void draw();
  void handleInput();
  void tick();
  void moveBlockDown();

  int score = 0;
  bool isGameOver = false;

  Music music;

private:
  Grid grid;
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  bool isBlockOutOfBounds();
  bool doesBlockFit();
  void lockBlock();
  void rotateBlock();
  void reset();
  void updateScore(int linesCleared, int moveDownPoints);
  void moveBlockLeft();
  void moveBlockRight();

  Sound rotateSound;
  Sound clearSound;
};
