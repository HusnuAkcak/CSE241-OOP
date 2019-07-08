#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <fstream>
#include <vector>
#include "polygon.h"

using namespace std;
using namespace svg;

class Circle {

public:
  Circle(int c, int r, int radius); //center coordinates and radius
  Circle() :radius(0) { ++totalCount; };

  int getCenterRow()const { return center.getRow(); }
  int getCenterCol()const { return center.getCol(); }
  int getRadius() const { return radius; }
  double getPerimeter() const { return 2*PI*radius; }
  double getArea() const { return PI*radius*radius; }
  static int getTotalCount()  { return totalCount; }
  static double getTotalArea()  { return totalArea; }
  static double getTotalPerimeter()  { return totalPerimeter; }

  void setCenter(int c, int r);
  void setRadius(int radius);

  Circle operator ++ () { ++center; return *this; }
  Circle operator ++ (int) { Circle temp=*this; ++(*this); return temp; }
  Circle operator -- () { --center; return *this; }
  Circle operator -- (int) { Circle temp=*this; --(*this); return temp; }
  bool operator ==(const Circle& circle2)const { return getArea() == circle2.getArea(); }
  bool operator !=(const Circle& circle2)const { return !(*this==circle2); }

  friend ostream& operator << (ostream& outputStream, const Circle& circle);
  friend Circle operator +(const Circle& circle, double increment);
  friend Circle operator +(double increment, const Circle& circle);
  friend Circle operator +(const Circle& c1, const Circle& c2);
  friend Circle operator -(const Circle& circle, double decrement);
  friend Circle operator -(double decrescent, const Circle& circle);
  friend Circle operator -(const Circle& c1, const Circle& c2);

private:
  int radius=0;
  Polygon::Point2D center;
  static int totalCount;
  static double totalArea;
  static double totalPerimeter;
  //private functions
  void updateTotalArea(int oldRadius, int newRadius);
  void updateTotalPerimeter(int oldRadius, int newRadius);
};

#endif
