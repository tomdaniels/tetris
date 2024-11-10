#pragma once

#include "blocks.cpp"
#include "grid.h"
#include "ui.h"

class Game {
public:
  Game();
  ~Game();

  void HandleInput();
  void Tick();
  void Render();

  int score = 0;
  bool isGameOver = false;
  Block nextBlock;
  void MoveBlockDown();
  Block GetRandomBlock();

  UI ui;
  Music music;

private:
  Grid grid;
  Block currentBlock;
  std::vector<Block> allPossibleBlocks{IBlock(), JBlock(), LBlock(), OBlock(),
                                       SBlock(), TBlock(), ZBlock()};
  std::vector<Block> blocksToChooseFrom = allPossibleBlocks;

  bool IsBlockOutOfBounds();
  bool DoesBlockFit();
  void LockBlock();
  void RotateBlock();
  void Reset();
  void UpdateScore(int linesCleared, int moveDownPoints);
  void MoveBlockLeft();
  void MoveBlockRight();

  Sound rotateSound;
  Sound clearSound;
};
