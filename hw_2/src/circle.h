#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <fstream>
#include <vector>
#include "base.h"
#include "shape.h"

using namespace std;

class Circle {

public:
  Circle(int c, int r, int radius); //center coordinates and radius
  Circle() { /*intentionally empty*/ };

  int getCenterRow() { return center.getRow(); }
  int getCenterCol() { return center.getCol(); }
  int getRadius() const { return radius; }

  void setCenter(int c, int r);
  void setRadius(int radius);

  void draw(ofstream & filePtr);

private:
    int radius;
    Point center;
};

#endif
