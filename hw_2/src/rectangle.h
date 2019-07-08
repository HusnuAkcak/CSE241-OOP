#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <fstream>

using namespace std;

class Rectangle {
public:
  Rectangle(int c, int r, int width, int height);
  Rectangle(int width, int height);
  Rectangle() { /*intentionally empty */ }

  int getStartPointCol() { return startPoint.getCol(); }
  int getStartPointRow() { return startPoint.getRow(); }
  int getWidth() const { return width; }
  int getHeight() const { return height; }

  void setStartPoint(int c, int r);
  void setWidth(int width);
  void setHeight(int height);

  void draw(ofstream &file);

private:
  Point startPoint;
  int width, height;
};

#endif
