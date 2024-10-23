#include "block.h"
#include <raylib.h>
#include <vector>

Block::Block() {}

void Block::draw() {
  std::vector<Position> tiles = getCellPositions();
  for (Position item : tiles) {
    DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1,
                  cellSize - 1, cellSize - 1, colours[id]);
  }
}

void Block::move(int rows, int columns) {
  rowOffset += rows;
  columnOffset += columns;
}

std::vector<Position> Block::getCellPositions() {
  std::vector<Position> movedTiles;
  for (Position item : cells[rotationState]) {
    movedTiles.emplace_back(item.row + rowOffset, item.column + columnOffset);
  }
  return movedTiles;
}

void Block::rotate() {
  rotationState = (rotationState + 1) % (int)cells.size();
}

void Block::undoRotate() {
  rotationState = (rotationState + ((int)cells.size() - 1)) % (int)cells.size();
}
