#pragma once
#include "colours.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  int id;
  void draw();
  void move(int rows, int columns);
  std::map<int, std::vector<Position>> cells;

private:
  int cellSize = 30;
  int rotationState = 0;
  std::vector<Color> colours = cellColours;

  std::vector<Position> getCellPositions();
  int rowOffset = 0;
  int columnOffset = 0;
};
