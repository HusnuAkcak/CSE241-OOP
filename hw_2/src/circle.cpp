#include <iostream>
#include <cmath>
#include <vector>
#include "base.h"
#include "shape.h"
#include "circle.h"

using namespace std;

Circle::Circle(int c, int r, int radius){
  setCenter(c, r);
  setRadius(radius);
}

void Circle::setCenter(int c, int r) {
  if( c >=0 && r>=0 ) {
    center.setCol(c);
    center.setRow(r);
  }

  return;
}

void Circle::setRadius(int newRadius) {
  if(newRadius > 0)
    radius = static_cast<int>(newRadius);

  return;
}

void
Circle::draw(ofstream & filePtr) {
  filePtr  << "  <circle "
           << " cx= \"" << center.getCol() << "\""
           << " cy= \"" << center.getRow() << "\""
           << " r= \""  << radius          << "\""
           << " stroke = \"black\" stroke-width=\"1\" "
           << " fill=\"rgb(187, 221, 167)\" /> \n";
  return;
}
