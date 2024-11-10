#include "game.h"
#include <cstdlib>
#include <raylib.h>
#include <vector>

Game::Game() {
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();

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

Block Game::GetRandomBlock() {
  if (blocksToChooseFrom.empty()) {
    blocksToChooseFrom = allPossibleBlocks;
  }

  int randomIndex = rand() % blocksToChooseFrom.size();
  Block block = blocksToChooseFrom[randomIndex];
  blocksToChooseFrom.erase(blocksToChooseFrom.begin() + randomIndex);

  return block;
}

void Game::Render() {
  grid.Draw();
  currentBlock.Draw(11, 11);

  ui.Paint(score, nextBlock, isGameOver);
}

void Game::HandleInput() {
  int keypressed = GetKeyPressed();

  if (isGameOver && keypressed != 0) {
    isGameOver = false;
    Reset();
  }

  switch (keypressed) {
  case KEY_LEFT:
    MoveBlockLeft();
    break;
  case KEY_RIGHT:
    MoveBlockRight();
    break;
  case KEY_DOWN:
    MoveBlockDown();
    UpdateScore(0, 1);
    break;
  case KEY_UP:
    RotateBlock();
  }
}

void Game::MoveBlockLeft() {
  currentBlock.Move(0, -1);
  if (IsBlockOutOfBounds() || !DoesBlockFit()) {
    currentBlock.Move(0, 1);
  }
};
void Game::MoveBlockRight() {
  currentBlock.Move(0, 1);
  if (IsBlockOutOfBounds() || !DoesBlockFit()) {
    currentBlock.Move(0, -1);
  }
};
void Game::MoveBlockDown() {
  currentBlock.Move(1, 0);
  if (IsBlockOutOfBounds() || !DoesBlockFit()) {
    currentBlock.Move(-1, 0);
    LockBlock();
  }
};

bool Game::IsBlockOutOfBounds() {
  for (Position item : currentBlock.GetCellPositions()) {
    if (grid.IsOutOfBounds(item.row, item.column)) {
      return true;
    }
  }

  return false;
}

void Game::RotateBlock() {
  currentBlock.Rotate();
  if (IsBlockOutOfBounds()) {
    currentBlock.UndoRotate();
  } else {
    PlaySound(rotateSound);
  }
}

void Game::LockBlock() {
  for (Position item : currentBlock.GetCellPositions()) {
    grid.grid[item.row][item.column] = currentBlock.id;
  }

  currentBlock = nextBlock;
  if (!DoesBlockFit()) {
    isGameOver = true;
  }

  nextBlock = GetRandomBlock();
  int rowsCleared = grid.ClearFullRows();
  if (rowsCleared > 0) {

    PlaySound(clearSound);
    UpdateScore(rowsCleared, 0);
  }
}

bool Game::DoesBlockFit() {
  for (Position item : currentBlock.GetCellPositions()) {
    if (!grid.IsCellEmpty(item.row, item.column)) {
      return false;
    }
  }

  return true;
}

void Game::Reset() {
  grid.Initialize();
  blocksToChooseFrom = allPossibleBlocks;
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints) {
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

void Game::Tick() {
  if (!isGameOver && TimeElapsed(0.2)) {
    MoveBlockDown();
  }
}
