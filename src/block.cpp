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
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;

  for (Position item : tiles) {
    Position newPos =
        Position(item.row + rowOffset, item.column + columnOffset);
    movedTiles.push_back(newPos);
  }

  return movedTiles;
}

void Block::rotate() {
  rotationState++;
  if (rotationState == (int)cells.size()) {
    rotationState = 0;
  }
}

void Block::undoRotate() {
  rotationState--;
  if (rotationState == -1) {
    rotationState = cells.size() - 1;
  }
}
