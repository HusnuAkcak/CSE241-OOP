#include <iostream>
#include <cmath>
#include "triangle.h"
#include "polygon.h"

using namespace std;

namespace geometrical {
  // static variable initializations
  int Triangle::totalCount= 0;
  double Triangle::totalArea= 0;
  double Triangle::totalPerimeter= 0;

  Triangle::Triangle(int c, int r, int edge, int rotationAngle)throw(invalid_argument) {
    setPeakPoint(c, r);
    setEdge(edge);
    setRotationAngle(rotationAngle);
    ++totalCount;
  }

  Triangle::Triangle(int edge, int rotationAngle)throw(invalid_argument) {
    setEdge(edge);
    setRotationAngle(rotationAngle);
    ++totalCount;
  }

  Triangle::Triangle(int edge)throw(invalid_argument) {
    setEdge(edge);
    setRotationAngle(0);
    ++totalCount;
  }

  Triangle::Triangle() noexcept:edge(0), rotationAngle(0){
    peakPoint.setRow(0);
    peakPoint.setCol(0);
    ++totalCount;
  }

  int
  Triangle::getPeakPointCol() const noexcept {
    return peakPoint.getCol();
  }
  int
  Triangle::getPeakPointRow() const noexcept {
    return peakPoint.getRow();
  }
  Point2D
  Triangle::getPeakPoint() const noexcept {
    return peakPoint;
  }
  int
  Triangle::getEdge() const noexcept {
    return edge;
  }
  int
  Triangle::getRotationAngle() const noexcept{
    return rotationAngle;
  }
  int
  Triangle::getTotalCount() noexcept {
    return totalCount;
  }
  double
  Triangle::getTotalArea() noexcept {
    return totalArea;
  }
  double
  Triangle::getTotalPerimeter() noexcept {
    return totalPerimeter;
  }

  void
  Triangle::setPeakPoint(int c, int r)throw(invalid_argument) {
    peakPoint.setCol(c);
    peakPoint.setRow(r);
    return;
  }

  void
  Triangle::setEdge(int newEdge) throw(invalid_argument) {
    if(newEdge > 0) {
      updateTotalArea(getEdge(), newEdge);
      updateTotalPerimeter(getEdge(), newEdge);
      edge = newEdge;
    }
    return;
  }

  void
  Triangle::setRotationAngle(int newRotation) noexcept{
    // newRotation is processec and it is gotten a degree btw 0 and 360;
    if(newRotation < 0) {
        newRotation = newRotation % 360;
        newRotation+=360;
    }
    else {
        newRotation = newRotation % 360;
    }

    rotationAngle = newRotation;
    return;
  }

  double
  Triangle::perimeter() const noexcept{
    return 3*edge;
  }
  double
  Triangle::area() const noexcept {
    return (edge*sqrt(3)/4);
  }
  void
  Triangle::calcTriangleBottomNodes (Point2D& tLeftBtmNode,
                                        Point2D& tRightBtmNode)const noexcept {

    tLeftBtmNode.setRow(peakPoint.getRow() + (double(edge)/ 2.0 )*(sqrt(3)) );
    tLeftBtmNode.setCol(peakPoint.getCol() + double(edge)/ 2.0 );
    tRightBtmNode.setRow(peakPoint.getRow() + (double(edge)/ 2.0 )*(sqrt(3)) );
    tRightBtmNode.setCol(peakPoint.getCol() - double(edge)/ 2.0 );
    return;
  }

  void
  Triangle::updateTotalArea(int oldEdge, int newEdge)noexcept {
    double beforeArea, newArea;
    beforeArea = (oldEdge*oldEdge)*sqrt(3.0)/4.0;
    newArea = (newEdge*newEdge)*sqrt(3.0)/4.0;
    totalArea = totalArea - beforeArea + newArea;
    return;
  }

  void
  Triangle::updateTotalPerimeter(int oldEdge ,int newEdge)noexcept {
    double beforePerimeter, newPerimeter;
    beforePerimeter = oldEdge *3;
    newPerimeter = newEdge *3;
    totalPerimeter = totalPerimeter - beforePerimeter + newPerimeter;
    return;
  }

  ostream&
  operator << (ostream& outputStream, Triangle& tri ) noexcept {
    return tri.print(outputStream);
  }

  ostream&
  Triangle::print(ostream& outputStream)noexcept {

    Point2D tLeftBtmNode, tRightBtmNode;
    calcTriangleBottomNodes(tLeftBtmNode, tRightBtmNode);

    outputStream << "  <polygon points= \""
                  << peakPoint.getCol()    << " "
                  << peakPoint.getRow()    << " "
                  << tLeftBtmNode.getCol() << " " << tLeftBtmNode.getRow() << " "
                  <<tRightBtmNode.getCol() << " " << tRightBtmNode.getRow() << "\""
            << " transform = \"rotate("
                  << rotationAngle      << " "
                  << peakPoint.getCol() << " "
                  << peakPoint.getRow() << ")\""
            << " stroke = \"black\" stroke-width=\"1\" "
            << " fill=\"rgb("<< edge%150 <<","<< edge%50 <<","<< edge%25 <<")\"/> \n";
    return outputStream;
  }

  bool
  Triangle::operator == (const Shape& s2)const noexcept {
    return (area()==s2.area());
  }
  bool
  Triangle::operator != (const Shape& s2)const noexcept {
    return (area()!=s2.area());
  }
  bool
  Triangle::operator <  (const Shape& s2)const noexcept {
    return (area()< s2.area());
  }
  bool
  Triangle::operator <= (const Shape& s2)const noexcept {
    return (area()<=s2.area());
  }
  bool
  Triangle::operator >  (const Shape& s2)const noexcept {
    return (area() >s2.area());
  }
  bool
  Triangle::operator >= (const Shape& s2)const noexcept {
    return (area()>=s2.area());
  }

  //posfix and prefix operator overloadings (virtual, overridden)
  Triangle&
  Triangle::operator ++() noexcept {    // incr shape pos by 1
    ++peakPoint;
    return *this;
  }
  Triangle&
  Triangle::operator --() noexcept {    // decr shape pos by 1
    --peakPoint;
    return *this;
  }
  Triangle&
  Triangle::operator ++(int) noexcept { // incr shape pos by 1
    Triangle *temp= new Triangle(*this);
    ++(*this);
    return *temp;
  }
  Triangle&
  Triangle::operator --(int) noexcept { // decr shape pos by 1
    Triangle *temp=new Triangle(*this);
    --(*this);
    return *temp;
  }

  // triangle + number
  Triangle
  operator + (const Triangle& tri, double increment) noexcept {
    Triangle temp =tri;
    temp.edge += increment;
    return temp;
  }
  // number + triangle
  Triangle
  operator + (double increment, const Triangle& tri) noexcept {
    Triangle temp = tri;
    temp.edge += increment;
    return  temp;
  }
  //triangle + triangle
  Triangle
  operator + (const Triangle& t1, const Triangle& t2) noexcept {
    Triangle temp1= t1, temp2= t2;
    temp1.edge += temp2.edge;
    return temp1;
  }
  // triangle - number
  Triangle
  operator - (const Triangle& tri, double decrement) throw(invalid_argument) {
    Triangle temp =tri;

    temp.edge -= decrement;
    if(temp.edge < 0)
      temp.edge=0;

    return temp;
  }
  // number - triangle
  Triangle
  operator - (double decrescent, const Triangle& tri) throw(invalid_argument) {
    Triangle temp = tri;

    temp.edge = decrescent - temp.edge;
    if(temp.edge<0)
      temp.edge =0;

    return temp;
  }
  //triangle - triangle
  Triangle
  operator - (const Triangle& t1, const Triangle& t2) throw(invalid_argument) {
    Triangle temp =t1;

    temp.edge = temp.edge - t2.edge;
    if(temp.edge<0)
      temp.edge =0;

    return temp;
  }
} //end of geometrical namespace.
