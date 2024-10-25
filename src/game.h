#pragma once

#include "blocks.cpp"
#include "grid.h"
#include "ui.h"

class Game {
public:
  Game();
  ~Game();

  void handleInput();
  void tick();
  void render();

  int score = 0;
  bool isGameOver = false;
  Block nextBlock;
  void moveBlockDown();
  Block getRandomBlock();

  UI ui;
  Music music;

private:
  Grid grid;
  Block currentBlock;
  std::vector<Block> allBlocks{IBlock(), JBlock(), LBlock(), OBlock(),
                               SBlock(), TBlock(), ZBlock()};
  std::vector<Block> blocks = allBlocks;

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
