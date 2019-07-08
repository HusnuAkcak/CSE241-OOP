#include <iostream>
#include <cmath>
#include <memory>
#include <vector>
#include "point2d.h"
#include "circle.h"

using namespace std;
namespace geometrical {
  //static variables
  int Circle::totalCount =0;
  double Circle::totalArea =0;
  double Circle::totalPerimeter =0;

  Circle::Circle(int c, int r, int radius) throw(invalid_argument){
    setCenter(c, r);
    setRadius(radius);
    ++totalCount;
  }

  Circle::Circle() noexcept :radius(0){
    ++totalCount; 
  }

  int Circle::getCenterRow() noexcept {
    return center.getRow(); 
  }
  int Circle::getCenterCol() noexcept {
    return center.getCol(); 
  }
  int Circle::getRadius() const noexcept {
    return radius; 
  }

  int 
  Circle::getTotalCount() noexcept { // static function 
    return totalCount; 
  }  
  double 
  Circle::getTotalArea() noexcept { //static function
    return totalArea; 
  }
  double 
  Circle::getTotalPerimeter() noexcept { //static function
    return totalPerimeter; 
  }

  double 
  Circle::perimeter() const noexcept{
    return 2*PI*radius; 
  }

  double 
  Circle::area() const noexcept{
    return PI*radius*radius; 
  }

  void Circle::setCenter(int c, int r) throw(invalid_argument){
    if( c >=0 && r>=0 ) {
      center.setCol(c);
      center.setRow(r);
    }
    else
      throw invalid_argument("Both cordinates must be greater than or equal zero.");

    return;
  }

  void
  Circle::setRadius(int newRadius) throw(invalid_argument){
    if(newRadius > 0) {
      updateTotalArea(getRadius(), newRadius);
      updateTotalPerimeter(getRadius(), newRadius);
      radius = static_cast<int>(newRadius);
    }
    else 
      throw invalid_argument("Radius must be greater than zero.");
    return;
  }

  // total perimeter and area updater functions.
  void
  Circle::updateTotalArea(int oldRadius, int newRadius) noexcept {
    double beforeAddedArea, newArea;

    beforeAddedArea = PI*(oldRadius*oldRadius);
    newArea = PI*(newRadius*newRadius);
    totalArea = totalArea - beforeAddedArea + newArea;
    return;
  }
  void
  Circle::updateTotalPerimeter(int oldRadius, int newRadius) noexcept {
    double beforeAddedPerimeter, newPerimeter;

    beforeAddedPerimeter = 2*PI*oldRadius;
    newPerimeter = 2*PI*newRadius;
    totalPerimeter = totalPerimeter - beforeAddedPerimeter + newPerimeter;
    return;
  }

  // increment and decrement operators.
  Circle& 
  Circle::operator ++ () noexcept {
    ++center; 
    return *this;
  }
  Circle&
  Circle::operator -- () noexcept {
    --center; 
    return *this;
  }
  Circle&
  Circle::operator ++ (int) noexcept {
    Circle* temp =new Circle(*this);
    ++(*this);
    return *temp; 
  }
  Circle&
  Circle::operator -- (int) noexcept {
    Circle* temp =new Circle(*this);
    --(*this);
    return *temp; 
  }

  //comperison operators
  bool 
  Circle::operator ==(const Shape& circle2)const noexcept{ 
    return area() == circle2.area(); 
  }
  bool 
  Circle::operator !=(const Shape& circle2)const noexcept{ 
    return !(*this==circle2); 
  }
  bool 
  Circle::operator <(const Shape& circle2)const noexcept{
    return (area()<circle2.area());
  }
  bool 
  Circle::operator <=(const Shape& circle2)const noexcept{
    return (area()<=circle2.area());
  }
  bool 
  Circle::operator >(const Shape& circle2)const noexcept{
    return (area()>circle2.area());
  }
  bool 
  Circle::operator >=(const Shape& circle2)const noexcept{
    return (area()>=circle2.area());
  }

  ostream& //friend function of circle class
  operator << (ostream& outputStream, Circle& circle) noexcept{
    return circle.print(outputStream);  
  }

  ostream& 
  Circle::print(ostream& outputStream) noexcept{

    outputStream  << "  <circle "
                  << " cx= \"" << center.getCol() << "\""
                  << " cy= \"" << center.getRow() << "\""
                  << " r= \""  << radius          << "\""
                  << " stroke = \"black\" stroke-width=\"1\" "
                  << " fill=\"rgb("<< radius%150 <<","<< radius%50 <<","<< radius%25 <<")\"/> \n";

    return outputStream;
  }

  //  circle + number
  Circle
  operator +(const Circle& circle, double increment) noexcept {
    Circle temp = circle;
    temp.radius+= increment;
    return temp;
  }

  //  number + circle
  Circle
  operator +(double increment, const Circle& circle) noexcept {
    Circle temp = circle;
    temp.radius+= increment;
    return temp;
  }

  //  circle + circle
  Circle
  operator +(const Circle& c1, const Circle& c2) noexcept {
    Circle temp =c1;
    temp.radius += c2.radius;
    return temp;
  }

  // circle - number
  Circle
  operator -(const Circle& circle, double decrement) throw(invalid_argument) {
    Circle temp = circle;
    temp.radius -= decrement;
    if(temp.radius<0)
      throw invalid_argument("Circle radius must not be negative!\n");
    return temp;
  }

  // number - circle
  Circle
  operator -(double decrescent, const Circle& circle) throw(invalid_argument) {
    Circle temp = circle;

    temp.radius = decrescent - temp.radius;
    if(temp.radius < 0)
      throw invalid_argument("Circle radius must not be negative!\n");

    return temp;
  }

  // circle - circle
  Circle
  operator -(const Circle& c1, const Circle& c2) throw(invalid_argument) {
    Circle temp = c1;

    temp.radius -= c2.radius;
    if(temp.radius < 0)
      throw invalid_argument("Circle radius must not be negative!\n");

    return temp;
  }
} //end of geometrical namespace scope