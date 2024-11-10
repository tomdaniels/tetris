#pragma once

#include "../HeaderFiles/grid.h"
#include "../HeaderFiles/ui.h"
#include "../SourceFiles/blocks.cpp"

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
  std::vector<Block> allPossibleBlocks{IBlock(), JBlock(), LBlock(), OBlock(),
                                       SBlock(), TBlock(), ZBlock()};
  std::vector<Block> blocksToChooseFrom = allPossibleBlocks;

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
