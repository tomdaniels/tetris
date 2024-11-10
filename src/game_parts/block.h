#pragma once
#include "colours.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  int id;
  void Draw(int offsetX, int offsetY);
  void Rotate();
  void UndoRotate();
  void Move(int rows, int columns);
  std::map<int, std::vector<Position>> cells;
  std::vector<Position> GetCellPositions();

private:
  int cellSize = 30;
  int rotationState = 0;
  std::vector<Color> colours = cellColours;

  int rowOffset = 0;
  int columnOffset = 0;
};
