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
    moveLeft();
    break;
  case KEY_RIGHT:
    moveRight();
    break;
  case KEY_DOWN:
    moveDown();
  }
}

void Game::moveLeft() {
  currentBlock.move(0, -1);
  if (isBlockOutOfBounds()) {
    currentBlock.move(0, 1);
  }
};
void Game::moveRight() {
  currentBlock.move(0, 1);
  if (isBlockOutOfBounds()) {
    currentBlock.move(0, -1);
  }
};
void Game::moveDown() {
  currentBlock.move(1, 0);
  if (isBlockOutOfBounds()) {
    currentBlock.move(-1, 0);
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
