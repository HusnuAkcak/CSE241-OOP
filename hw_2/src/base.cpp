#include <iostream>
#include "base.h"

Point::Point(int r, int c) {
  setRow(r);
  setCol(c);
}

void Point::setRow(int row) {
  if(row>=0)
    r = static_cast<int>(row);

  return;
}

void Point::setCol(int column) {
  if(column>=0)
    c = static_cast<int>(column);

  return;
}
