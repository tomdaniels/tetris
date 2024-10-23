#include "block.h"
#include <raylib.h>
#include <vector>

Block::Block() {}
void Block::draw() {
  std::vector<Position> tiles = cells[rotationState];
  for (Position item : tiles) {
    DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1,
                  cellSize - 1, cellSize - 1, colours[id]);
  }
}
