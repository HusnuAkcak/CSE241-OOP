#include <iostream>
#include <cmath>
#include "base.h"
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(int col, int row, int width, int height) {
  setStartPoint(col, row);
  setWidth(width);
  setHeight(height);
}
Rectangle::Rectangle(int width, int height) {
  setWidth(width);
  setHeight(height);
}

void
Rectangle::setStartPoint(int newCol, int newRow) {
  if(newCol >= 0 && newRow >= 0){
    startPoint.setCol(newCol);
    startPoint.setRow(newRow);
  }
  return;
}

void
Rectangle::setWidth(int newWidth) {
  if(newWidth>0)
    width = newWidth;
  return;
}

void
Rectangle::setHeight(int newHeight) {
  if(newHeight > 0)
    height = newHeight;
  return;
}

void
Rectangle::draw(ofstream &filePtr) {
  filePtr  << "  <rect "
          << " x = \"" << startPoint.getCol() << "\""
          << " y = \"" << startPoint.getRow() << "\""
          << " width= \"" << width << "\""
          << " height= \"" << height << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"orange\" /> \n";
  return;
}
