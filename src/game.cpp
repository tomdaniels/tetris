#include "game.h"
#include <random>
#include <raylib.h>
#include <vector>

Game::Game() {
  Grid grid;
  blocks = getAllBlocks();
  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();
}

Block Game::getRandomBlock() {
  if (blocks.empty()) {
    blocks = getAllBlocks();
  }

  int randomIndex = rand() % blocks.size();
  Block block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);

  return block;
}

std::vector<Block> Game::getAllBlocks() {
  return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::draw() {
  grid.draw();
  currentBlock.draw();
}

void Game::handleInput() {
  int keypressed = GetKeyPressed();

  switch (keypressed) {
  case KEY_LEFT:
    moveBlockLeft();
    break;
  case KEY_RIGHT:
    moveBlockRight();
    break;
  case KEY_DOWN:
    moveBlockDown();
    break;
  case KEY_UP:
    rotateBlock();
  }
}

void Game::moveBlockLeft() {
  currentBlock.move(0, -1);
  if (isBlockOutOfBounds()) {
    currentBlock.move(0, 1);
  }
};
void Game::moveBlockRight() {
  currentBlock.move(0, 1);
  if (isBlockOutOfBounds()) {
    currentBlock.move(0, -1);
  }
};
void Game::moveBlockDown() {
  currentBlock.move(1, 0);
  if (isBlockOutOfBounds()) {
    currentBlock.move(-1, 0);
    lockBlock();
  }
};

bool Game::isBlockOutOfBounds() {
  for (Position item : currentBlock.getCellPositions()) {
    if (grid.isOutOfBounds(item.row, item.column)) {
      return true;
    }
  }

  return false;
}

void Game::rotateBlock() {
  currentBlock.rotate();
  if (isBlockOutOfBounds()) {
    currentBlock.undoRotate();
  }
}

void Game::lockBlock() {
  for (Position item : currentBlock.getCellPositions()) {
    grid.grid[item.row][item.column] = currentBlock.id;
  }

  currentBlock = nextBlock;
  nextBlock = getRandomBlock();
}
