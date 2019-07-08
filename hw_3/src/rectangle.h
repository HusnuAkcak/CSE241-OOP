#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <fstream>

using namespace std;

class Rectangle {
public:
  Rectangle(int c, int r, int width, int height);
  Rectangle(int width, int height);
  Rectangle() :width(0), height(0) { ++totalCount; }

  int getStartPointCol() { return startPoint.getCol(); }
  int getStartPointRow() { return startPoint.getRow(); }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
  int getPerimeter() const { return 2*(width+height); }
  int getArea() const { return width*height; }
  static int getTotalCount() { return totalCount; }
  static double getTotalPerimeter() { return totalPerimeter; }
  static double getTotalArea() { return totalArea; }

  void setStartPoint(int c, int r);
  void setWidth(int width);
  void setHeight(int height);

  Rectangle operator ++ () { ++startPoint; return *this; }
  Rectangle operator ++ (int) { Rectangle temp=*this; ++(*this); return temp; }
  Rectangle operator -- () { --startPoint; return *this; }
  Rectangle operator -- (int) { Rectangle temp=*this; --(*this); return temp; }
  bool operator ==(const Rectangle& rect2)const { return getArea() == rect2.getArea(); }
  bool operator !=(const Rectangle& rect2)const { return getArea() != rect2.getArea(); }

  friend ostream& operator << (ostream& outputStream, const Rectangle& rect);
  friend Rectangle operator +(const Rectangle& rect, double increment);
  friend Rectangle operator +(double increment, const Rectangle& rect);
  friend Rectangle operator +(const Rectangle& r1, const Rectangle& r2);
  friend Rectangle operator -(const Rectangle& rect, double decrement);
  friend Rectangle operator -(double decrescent, const Rectangle& rect);
  friend Rectangle operator -(const Rectangle& r1, const Rectangle& r2);
private:
  Point startPoint;
  int width, height;
  static int totalCount;
  static double totalArea, totalPerimeter;
  //private functions
  void updateTotalArea(int oldWidth, int oldHeight, int newWidth, int newHeight);
  void updateTotalPerimeter(int oldWidth, int oldHeight, int newWidth, int newHeight);

};

#endif
