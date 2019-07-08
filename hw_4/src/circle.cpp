#include <iostream>
#include <cmath>
#include <vector>
#include "circle.h"

using namespace std;

//static variables
int Circle::totalCount =0;
double Circle::totalArea =0;
double Circle::totalPerimeter =0;

Circle::Circle(int c, int r, int radius){
  setCenter(c, r);
  setRadius(radius);
  ++totalCount;
}

void Circle::setCenter(int c, int r) {
  if( c >=0 && r>=0 ) {
    center.setCol(c);
    center.setRow(r);
  }

  return;
}

void
Circle::setRadius(int newRadius) {
  if(newRadius > 0) {
    updateTotalArea(getRadius(), newRadius);
    updateTotalPerimeter(getRadius(), newRadius);
    radius = static_cast<int>(newRadius);
  }
  return;
}

void
Circle::updateTotalArea(int oldRadius, int newRadius) {
  double beforeAddedArea, newArea;

  beforeAddedArea = PI*(oldRadius*oldRadius);
  newArea = PI*(newRadius*newRadius);
  totalArea = totalArea - beforeAddedArea + newArea;
  return;
}

void
Circle::updateTotalPerimeter(int oldRadius, int newRadius) {
  double beforeAddedPerimeter, newPerimeter;

  beforeAddedPerimeter = 2*PI*oldRadius;
  newPerimeter = 2*PI*newRadius;
  totalPerimeter = totalPerimeter - beforeAddedPerimeter + newPerimeter;
  return;
}

ostream& //friend function of circle class
operator << (ostream& outputStream, const Circle& circle){
  outputStream  << "  <circle "
                << " cx= \"" << circle.center.getCol() << "\""
                << " cy= \"" << circle.center.getRow() << "\""
                << " r= \""  << circle.radius          << "\""
                << " stroke = \"black\" stroke-width=\"1\" "
                << " fill=\"rgb("<< circle.radius%150 <<","<< circle.radius%50 <<","<< circle.radius%25 <<")\"/> \n";

  return outputStream;
}

//  circle + number
Circle
operator +(const Circle& circle, double increment) {
  Circle temp = circle;
  temp.radius+= increment;
  return temp;
}

//  number + circle
Circle
operator +(double increment, const Circle& circle) {
  Circle temp = circle;
  temp.radius+= increment;
  return temp;
}

//  circle + circle
Circle
operator +(const Circle& c1, const Circle& c2) {
  Circle temp =c1;
  temp.radius += c2.radius;
  return temp;
}

// circle - number
Circle
operator -(const Circle& circle, double decrement) {
  Circle temp = circle;
  temp.radius -= decrement;
  if(temp.radius<0)
    temp.radius =0;
  return temp;
}

// number - circle
Circle
operator -(double decrescent, const Circle& circle) {
  Circle temp = circle;

  temp.radius = decrescent - temp.radius;
  if(temp.radius < 0)
    temp.radius =0;

  return temp;
}

// circle - circle
Circle
operator -(const Circle& c1, const Circle& c2) {
  Circle temp = c1;

  temp.radius -= c2.radius;
  if(temp.radius < 0)
    temp.radius =0;

  return temp;
}
