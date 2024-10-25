#include "game.h"
#include <random>
#include <raylib.h>
#include <vector>

Game::Game() {
  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();

  InitAudioDevice();
  music = LoadMusicStream("src/assets/music.mp3");
  rotateSound = LoadSound("src/assets/rotate.mp3");
  clearSound = LoadSound("src/assets/clear.mp3");
  PlayMusicStream(music);
}

Game::~Game() {
  UnloadMusicStream(music);
  UnloadSound(rotateSound);
  UnloadSound(clearSound);
  CloseAudioDevice();
}

Block Game::getRandomBlock() {
  if (blocks.empty()) {
    blocks = allBlocks;
  }

  int randomIndex = rand() % blocks.size();
  Block block = blocks[randomIndex];
  blocks.erase(blocks.begin() + randomIndex);

  return block;
}

void Game::draw() {
  grid.draw();
  currentBlock.draw(11, 11);

  ui.paint(score, nextBlock, isGameOver);
}

void Game::handleInput() {
  int keypressed = GetKeyPressed();

  if (isGameOver && keypressed != 0) {
    isGameOver = false;
    reset();
  }

  switch (keypressed) {
  case KEY_LEFT:
    moveBlockLeft();
    break;
  case KEY_RIGHT:
    moveBlockRight();
    break;
  case KEY_DOWN:
    moveBlockDown();
    updateScore(0, 1);
    break;
  case KEY_UP:
    rotateBlock();
  }
}

void Game::moveBlockLeft() {
  currentBlock.move(0, -1);
  if (isBlockOutOfBounds() || !doesBlockFit()) {
    currentBlock.move(0, 1);
  }
};
void Game::moveBlockRight() {
  currentBlock.move(0, 1);
  if (isBlockOutOfBounds() || !doesBlockFit()) {
    currentBlock.move(0, -1);
  }
};
void Game::moveBlockDown() {
  currentBlock.move(1, 0);
  if (isBlockOutOfBounds() || !doesBlockFit()) {
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
  } else {
    PlaySound(rotateSound);
  }
}

void Game::lockBlock() {
  for (Position item : currentBlock.getCellPositions()) {
    grid.grid[item.row][item.column] = currentBlock.id;
  }

  currentBlock = nextBlock;
  if (!doesBlockFit()) {
    isGameOver = true;
  }

  nextBlock = getRandomBlock();
  int rowsCleared = grid.clearFullRows();
  if (rowsCleared > 0) {

    PlaySound(clearSound);
    updateScore(rowsCleared, 0);
  }
}

bool Game::doesBlockFit() {
  for (Position item : currentBlock.getCellPositions()) {
    if (!grid.isCellEmpty(item.row, item.column)) {
      return false;
    }
  }

  return true;
}

void Game::reset() {
  grid.initialize();
  blocks = allBlocks;
  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();
  score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints) {
  switch (linesCleared) {
  case 1:
    score += 100;
    break;
  case 2:
    score += 300;
    break;
  case 3:
    score += 500;
    break;
  default:
    break;
  }

  score += moveDownPoints;
}

double lastUpdatedTime = 0;

bool TimeElapsed(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdatedTime >= interval) {
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}

void Game::tick() {
  if (!isGameOver && TimeElapsed(0.2)) {
    moveBlockDown();
  }
}
