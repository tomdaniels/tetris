#include "game.h"
#include <random>
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
