#include <iostream>
#include <cmath>
#include "rectangle.h"

using namespace std;

namespace geometrical {

  //static variable initialization
  int Rectangle::totalCount =0;
  double Rectangle::totalArea =0;
  double Rectangle::totalPerimeter =0;
  Rectangle::Rectangle(int col, int row, int width, int height) throw(invalid_argument) {
    setStartPoint(col, row);
    setWidth(width);
    setHeight(height);
    ++totalCount;
  }
  Rectangle::Rectangle(int width, int height) throw(invalid_argument) {
    setWidth(width);
    setHeight(height);
    ++totalCount;
  }
  Rectangle::Rectangle() noexcept :width(0), height(0) { 
    ++totalCount; 
  }

  int Rectangle::getStartPointCol()const noexcept {
    return startPoint.getCol(); 
  }
  int Rectangle::getStartPointRow()const noexcept {
    return startPoint.getRow(); 
  }
  int Rectangle::getWidth() const noexcept {
    return width; 
  }
  int Rectangle::getHeight() const noexcept {
    return height; 
  }

  void
  Rectangle::setStartPoint(int newCol, int newRow) throw(invalid_argument) {
    if(newCol >= 0 && newRow >= 0){
      startPoint.setCol(newCol);
      startPoint.setRow(newRow);
    }
    return;
  }

  void
  Rectangle::setWidth(int newWidth) throw(invalid_argument) {
    if(newWidth>0)
      updateTotalArea(getWidth(), getHeight(), newWidth, getHeight());
      updateTotalPerimeter(getWidth(), getHeight(), newWidth, getHeight());
      width = newWidth;
    return;
  }

  void
  Rectangle::setHeight(int newHeight) throw(invalid_argument) {
    if(newHeight > 0)
      updateTotalArea(getWidth(), getHeight(), getWidth(), newHeight);
      updateTotalPerimeter(getWidth(), getHeight(), getWidth(), newHeight);
      height = newHeight;
    return;
  }

  double 
  Rectangle::perimeter() const noexcept { 
    return 2*(width+height); 
  }
  double 
  Rectangle::area() const noexcept { 
    return width*height; 
  }

  int 
  Rectangle::getTotalCount() noexcept {
    return totalCount; 
  }
  double 
  Rectangle::getTotalPerimeter() noexcept {
    return totalPerimeter; 
  }
  double 
  Rectangle::getTotalArea() noexcept {
    return totalArea; 
  }

  void
  Rectangle::updateTotalArea(int oldWidth, int oldHeight, int newWidth, 
                                                      int newHeight) noexcept {
    double beforeArea, newArea;
    beforeArea = oldWidth*oldHeight;
    newArea = newWidth*newHeight;
    totalArea = totalArea - beforeArea + newArea;
    return;
  }

  void
  Rectangle::updateTotalPerimeter(int oldWidth, int oldHeight, int newWidth, 
                                                      int newHeight) noexcept {
    double beforePerimeter, newPerimeter;
    beforePerimeter = 2*(oldWidth+oldHeight);
    newPerimeter = 2*(newWidth+newHeight);
    totalPerimeter = totalPerimeter - beforePerimeter + newPerimeter;
    return;
  }

  ostream& 
  operator << (ostream & outputStream, Rectangle& rect) noexcept{
    return rect.print(outputStream);
  }
    
  ostream& 
  Rectangle::print(ostream& outputStream) noexcept {
    // const Rectangle &rect = dynamic_cast<const Rectangle*>(shape);
    outputStream  << "  <rect "
                  << " x = \"" << startPoint.getCol() << "\""
                  << " y = \"" << startPoint.getRow() << "\""
                  << " width= \"" << width << "\""
                  << " height= \"" << height << "\""
                  << " stroke = \"black\" stroke-width=\"1\" "
                  << " fill=\"rgb("<< width%255 <<","<< width%50 <<","<< width%25 <<")\"/> \n";

    return outputStream;
  } 

  Rectangle& 
  Rectangle::operator ++ () noexcept {
    ++startPoint; 
    return *this; 
  }
  Rectangle& 
  Rectangle::operator -- () noexcept {
    --startPoint; 
    return *this; 
  }
  Rectangle& 
  Rectangle::operator ++ (int) noexcept {
    Rectangle *temp= new Rectangle(*this);
    ++(*this); 
    return *temp; 
  }
  Rectangle& 
  Rectangle::operator -- (int) noexcept {
    Rectangle *temp= new Rectangle(*this);
    --(*this); 
    return *temp; 
  }

  bool 
  Rectangle::operator ==(const Shape& rect2)const noexcept {
    return area()== rect2.area(); 
  }
  bool 
  Rectangle::operator !=(const Shape& rect2)const noexcept {
    return area()!= rect2.area(); 
  }
  bool 
  Rectangle::operator >=(const Shape& rect2)const noexcept {
    return area()>= rect2.area();
  }
  bool 
  Rectangle::operator > (const Shape& rect2)const noexcept {
    return area()> rect2.area();
  }
  bool 
  Rectangle::operator <=(const Shape& rect2)const noexcept {
    return area()<= rect2.area();
  }
  bool 
  Rectangle::operator < (const Shape& rect2)const noexcept {
    return area() < rect2.area();
  }

  // rectangle + number
  Rectangle
  operator +(const Rectangle& rect, double increment)noexcept {
    Rectangle temp = rect;
    temp.width += increment;
    temp.height += increment;
    return temp;
  }

  // number + rectangle
  Rectangle
  operator +(double increment, const Rectangle& rect)noexcept {
    return rect + increment;
  }

  // rectangle + rectangle
  Rectangle
  operator +(const Rectangle& r1, const Rectangle& r2)noexcept {
    Rectangle temp = r1;
    temp.width += r2.width;
    temp.height += r2.height;
    return temp;
  }

  // rectangle - number
  Rectangle
  operator -(const Rectangle& rect, double decrement) throw(invalid_argument) {
    Rectangle temp = rect;

    temp.width -= decrement;
    temp.height -= decrement;
    //these two if statement could be a function
    if(temp.width < 0 || temp.height<0)
      throw invalid_argument("Dimension of rectangle could not be negative!\n");
    return temp;
  }

  // number - rectangle
  Rectangle
  operator -(double decrescent, const Rectangle& rect) throw(invalid_argument) {
    Rectangle temp = rect;

    temp.width = decrescent - temp.width;
    temp.height = decrescent - temp.height;
    if(temp.width < 0 || temp.height<0)
      throw invalid_argument("Dimension of rectangle could not be negative!\n");
  
    return temp;
  }

  // rectangle - rectangle
  Rectangle
  operator -(const Rectangle& r1, const Rectangle& r2) throw(invalid_argument) {
    Rectangle temp = r1;

    temp.width = temp.width - r2.width;
    temp.height = temp.height - r2.height;
    if(temp.width < 0 || temp.height<0)
      throw invalid_argument("Dimension of rectangle could not be negative!\n");

    return temp;
  }
} //end of geometrical namespace scope