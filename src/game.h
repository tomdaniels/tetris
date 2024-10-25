#pragma once

#include "blocks.cpp"
#include "grid.h"
#include "ui.h"

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
  Block nextBlock;

  UI ui;
  Music music;

private:
  Grid grid;
  std::vector<Block> blocks;
  Block currentBlock;
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
