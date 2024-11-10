#include "../HeaderFiles/block.h"
#include <raylib.h>
#include <vector>

Block::Block() {}

void Block::Draw(int offsetX, int offsetY) {
  for (Position item : GetCellPositions()) {
    DrawRectangle(item.column * cellSize + offsetX,
                  item.row * cellSize + offsetY, cellSize - 1, cellSize - 1,
                  colours[id]);
  }
}

void Block::Move(int rows, int columns) {
  rowOffset += rows;
  columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions() {
  std::vector<Position> movedTiles;
  for (Position item : cells[rotationState]) {
    movedTiles.emplace_back(item.row + rowOffset, item.column + columnOffset);
  }
  return movedTiles;
}

void Block::Rotate() {
  rotationState = (rotationState + 1) % (int)cells.size();
}

void Block::UndoRotate() {
  rotationState = (rotationState + ((int)cells.size() - 1)) % (int)cells.size();
}
