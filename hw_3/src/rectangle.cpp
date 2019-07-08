#include <iostream>
#include <cmath>
#include "base.h"
#include "rectangle.h"

using namespace std;

//static variable initialization
int Rectangle::totalCount =0;
double Rectangle::totalArea =0;
double Rectangle::totalPerimeter =0;
Rectangle::Rectangle(int col, int row, int width, int height) {
  setStartPoint(col, row);
  setWidth(width);
  setHeight(height);
  ++totalCount;
}
Rectangle::Rectangle(int width, int height) {
  setWidth(width);
  setHeight(height);
  ++totalCount;
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
    updateTotalArea(getWidth(), getHeight(), newWidth, getHeight());
    updateTotalPerimeter(getWidth(), getHeight(), newWidth, getHeight());
    width = newWidth;
  return;
}

void
Rectangle::setHeight(int newHeight) {
  if(newHeight > 0)
    updateTotalArea(getWidth(), getHeight(), getWidth(), newHeight);
    updateTotalPerimeter(getWidth(), getHeight(), getWidth(), newHeight);
    height = newHeight;
  return;
}

void
Rectangle::updateTotalArea(int oldWidth, int oldHeight, int newWidth, int newHeight) {
  double beforeArea, newArea;
  beforeArea = oldWidth*oldHeight;
  newArea = newWidth*newHeight;
  totalArea = totalArea - beforeArea + newArea;
  return;
}

void
Rectangle::updateTotalPerimeter(int oldWidth, int oldHeight, int newWidth, int newHeight) {
  double beforePerimeter, newPerimeter;
  beforePerimeter = 2*(oldWidth+oldHeight);
  newPerimeter = 2*(newWidth+newHeight);
  totalPerimeter = totalPerimeter - beforePerimeter + newPerimeter;
  return;
}

ostream&
operator << (ostream & outputStream, const Rectangle& rect) {

  outputStream  << "  <rect "
                << " x = \"" << rect.startPoint.getCol() << "\""
                << " y = \"" << rect.startPoint.getRow() << "\""
                << " width= \"" << rect.width << "\""
                << " height= \"" << rect.height << "\""
                << " stroke = \"black\" stroke-width=\"1\" "
                << " fill=\"rgb("<< rect.width%255 <<","<< rect.width%50 <<","<< rect.width%25 <<")\"/> \n";

  return outputStream;
}

// rectangle + number
Rectangle
operator +(const Rectangle& rect, double increment) {
  Rectangle temp = rect;
  temp.width += increment;
  temp.height += increment;
  return temp;
}

// number + rectangle
Rectangle
operator +(double increment, const Rectangle& rect) {
  return rect + increment;
}

// rectangle + rectangle
Rectangle
operator +(const Rectangle& r1, const Rectangle& r2) {
  Rectangle temp = r1;
  temp.width += r2.width;
  temp.height += r2.height;
  return temp;
}

// rectangle - number
Rectangle
operator -(const Rectangle& rect, double decrement) {
  Rectangle temp = rect;

  temp.width -= decrement;
  temp.height -= decrement;
  //these two if statement could be a function
  if(temp.width < 0)
    temp.width =0;
  if(temp.height < 0)
    temp.height =0;

  return temp;
}

// number - rectangle
Rectangle
operator -(double decrescent, const Rectangle& rect) {
  Rectangle temp = rect;

  temp.width = decrescent - temp.width;
  temp.height = decrescent - temp.height;
  if(temp.width < 0)
    temp.width =0;
  if(temp.height < 0)
    temp.height =0;

  return temp;
}

// rectangle - rectangle
Rectangle
operator -(const Rectangle& r1, const Rectangle& r2) {
  Rectangle temp = r1;

  temp.width = temp.width - r2.width;
  temp.height = temp.height - r2.height;
  if(temp.width < 0)
    temp.width =0;
  if(temp.height < 0)
    temp.height =0;

  return temp;
}
