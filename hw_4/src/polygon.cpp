#include <iostream>
#include <cmath>
#include "polygon.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

namespace {
  #define CIRCLE_POINT_COUNT 100.0
}

using namespace std;

namespace svg {

  /* Polgon::Point2D class codes starts...                                     */
  Polygon::Point2D::Point2D() { r=0, c=0; }

  Polygon::Point2D::Point2D(int r, int c) {
    setRow(r);
    setCol(c);
  }

  int Polygon::Point2D::getRotation() const { return rotation; }
  int Polygon::Point2D::getRow() const { return r; }
  int Polygon::Point2D::getCol() const { return c; }

  void
  Polygon::Point2D::setRow(int row) {
    if(row>=0)
      r = static_cast<int>(row);

    return;
  }

  void
  Polygon::Point2D::setCol(int column) {
    if(column>=0)
      c = static_cast<int>(column);

    return;
  }

  void
  Polygon::Point2D::setRotation(int newRotation) {
    if(newRotation >=0 && newRotation<= 360)
      rotation = newRotation;
    return;
  }

  bool
  Polygon::Point2D::operator ==(const Polygon::Point2D& secPoint) {
    if(r == secPoint.r && c==secPoint.c)
      return true;
    else
      return false;
  }

  bool
  Polygon::Point2D::operator !=(const Polygon::Point2D& secPoint) {
    if((*this == secPoint) ==false)
      return true;
    else
      return false;
  }

  Polygon::Point2D  Polygon::Point2D::operator ++() {
     ++r; ++c; return *this;
  }

  Polygon::Point2D  Polygon::Point2D::operator ++(int) {
     Polygon::Point2D temp=*this; ++(*this); return temp;
  }

  Polygon::Point2D  Polygon::Point2D::operator --() {
     --r; --c; return *this;
  }

  Polygon::Point2D  Polygon::Point2D::operator --(int) {
     Polygon::Point2D temp=*this; --(*this); return temp;
  }

  /* Polgon::Point2D class codes ends...                                      */

  /* Polgon class codes starts...                                             */

  Polygon::Polygon(const vector<Polygon::Point2D> newPoints) {
    setPolygon(newPoints);
  }

  Polygon::Polygon(const Polygon::Point2D& newPoint) {
    setPoint(newPoint);
  }

  Polygon::Polygon(const Circle& newCircle) {
    setCircle(newCircle);
  }

  Polygon::Polygon(const Rectangle& newRectangle) {
    setRectangle(newRectangle);
  }

  Polygon::Polygon(const Triangle& newTriangle) {
    setTriangle(newTriangle);
  }

  Polygon::Polygon( ) {
    /*intentionally empty */
  }

  /*BIG THERE OF POLYGON IS STARTED.                                          */
  Polygon::Polygon(const Polygon &newPolygon) { //COPY CONSTRUCTOR

    size = newPolygon.size;
    points = new Point2D[size];

    for(int i=0; i< size; ++i) {
      points[i] = newPolygon[i];
    }
  }

  Polygon
  Polygon::operator = (const Polygon &newPolygon) {  //ASSIGNMET OPERATOR

    if(&newPolygon != this) {
      if(points !=nullptr) {
        delete [] points; // dynamic array of this obj is deleted
        points = nullptr;
      }
      size=newPolygon.size;
      points = new Point2D[size]; // reallocation

      for(int i=0; i< size; ++i) {
        points[i] = newPolygon[i];
      }
    }
    return *this;
  }

  Polygon::~Polygon() { //DESTRUCTOR
    delete [] points;
    points = nullptr;
  }
  /*BIG THERE OF POLYGON IS ENDED.                                            */

  void
  Polygon::setSize(int newSize) {
    size = newSize;
    return;
  }

  void
  Polygon::setPolygon(const vector<Point2D> newPoints) {
    if(points != nullptr){
      delete [] points; //free dynamic array
      points = nullptr;
    }
    size = newPoints.size();
    points = new Point2D[size]; // allocation according to new size

    for(int i=0; i<size; ++i) {
      points[i]=newPoints[i];
    }
    return;
  }

  void
  Polygon::setPoint(const Point2D newPoint) {
    if(points != nullptr) {
      delete [] points;
      points = nullptr;
    }
    size=1;
    points = new Point2D[1];

    points[0]=newPoint;
    return;
  }

  void
  Polygon::setCircle(const Circle& newCircle) {

    double radius = newCircle.getRadius();   // radius of the circle
    if(points != nullptr) {
      delete [] points;
      points = nullptr;
    }

    size = CIRCLE_POINT_COUNT;
    points = new Point2D[size];

    // cout << "I am in the polygon constructor that takes circle\n";
    int i=0;
    for ( double d =360.0/CIRCLE_POINT_COUNT;
          d<=360.1;
          d+=(360.0/CIRCLE_POINT_COUNT) ){
      if(i>=size) break;
      points[i].setCol(newCircle.getCenterCol() + radius*cos(d/RAD));
      points[i].setRow(newCircle.getCenterRow() + radius*sin(d/RAD));
      ++i;
    }
    return;
  }

  void
  Polygon::setRectangle(const Rectangle& newRectangle) {

    if(points != nullptr) {
      delete [] points;
      points = nullptr;
    }
    size =4;
    points = new Point2D[size];

    // for vertice of the rectangle is calculated and set.
    points[0].setCol(newRectangle.getStartPointCol());
    points[0].setRow(newRectangle.getStartPointRow());
    points[1].setCol(points[0].getCol() + newRectangle.getWidth());
    points[1].setRow(points[0].getRow());
    points[2].setCol(points[1].getCol());
    points[2].setRow(points[1].getRow() + newRectangle.getHeight());
    points[3].setCol(points[2].getCol() - newRectangle.getWidth());
    points[3].setRow(points[2].getRow());

    return;
  }

  void
  Polygon::setTriangle(const Triangle& newTriangle) {

    Polygon::Point2D leftBtmNode, rightBtmNode; //left and right bottom node of triangle

    if(points != nullptr) {
      delete [] points;
      points = nullptr;
    }

    size =3;
    points = new Point2D[size];

    newTriangle.calcTriangleBottomNodes(leftBtmNode, rightBtmNode);

    points[0] = newTriangle.getPeakPoint();
    points[0].setRotation(newTriangle.getRotationAngle());
    points[1] = leftBtmNode;
    points[2] = rightBtmNode;

    return;
  }

  Polygon::Point2D*
  Polygon::getPolygon() const {
    return points;
  }

  int
  Polygon::getSize() const {
    return size;
  }

  ostream&
  Polygon::initSvgFile(ostream& outputStream) {
    Polygon::Point2D maxPoint;

    for(int i=0; i<size; ++i) {
      if(points[i].getCol()>maxPoint.getCol())
        maxPoint.setCol(points[i].getCol());

      if(points[i].getRow()>maxPoint.getRow())
        maxPoint.setRow(points[i].getRow());
    }

    outputStream  << "<svg version=\"1.1\" baseProfile=\"full\" "
          << " width= \"" << maxPoint.getCol()*(1.5) << "\""
          << " height= \"" <<  maxPoint.getRow()*(1.5) << "\""
          << " xmlns=\"http://www.w3.org/2000/svg\"> "
          << endl << endl;

    return outputStream;
  }

  const Polygon::Point2D&
  Polygon::operator [] (int index) const {
    return points[index];
  }

  Polygon::Point2D&
  Polygon::operator [] (int index) {
    return points[index];
  }

  bool
  Polygon::operator ==(const Polygon& polygon2) {
    bool equal;

    if(size == polygon2.size){
      int i=0;
      equal =true;

      do{
        if(points[i]!=polygon2.points[i])
          equal = false;
        ++i;
      }while(i<size && equal==true);

    }
    else
      equal =false;

    return equal;
  }

  bool
  Polygon::operator !=(const Polygon& polygon2) {

    if((*this == polygon2) ==false)
      return true;
    else
      return false;
  }

  Polygon
  Polygon::operator +(const Polygon& polygon2) {
    Polygon newPolygon;
    int i;

    newPolygon.size = size + polygon2.size;
    newPolygon.points = new Point2D[newPolygon.size];

    for(i = 0; i<size; ++i)
      newPolygon.points[i] = points[i];

    for(i=size; i<newPolygon.size; ++i)
      newPolygon.points[i] = polygon2[i-size];

    return newPolygon;
  }

  ostream&
  operator <<(ostream& outputStream, const Polygon& polygon) {
    Polygon::Point2D rotationPoint; //we assume there is only one point to use as a pivot while rotation
    outputStream << "  <polygon points= \"";
    for (int i=0; i< polygon.size; ++i) {
      outputStream  << polygon.points[i].getCol()<< ", "
                    << polygon.points[i].getRow()<< " ";

      if(polygon.points[i].getRotation()>0) // if it is rotation point.
        rotationPoint = polygon.points[i];
    }

    outputStream  << "\" transform = \"rotate("
                  << rotationPoint.getRotation() << " "
                  << rotationPoint.getCol()      << " "
                  << rotationPoint.getRow()      << ")\""
    << " stroke = \"black\" stroke-width=\"1\" ";
    if(polygon.getSize()>=3){
      outputStream << " fill=\"rgb(" << polygon[0].getCol()%255 <<
                                ", " << polygon[1].getCol()%155  <<
                                ", " << polygon[2].getCol()%55 <<")\"/> \n";
    }
    else {
      outputStream << "fill = \"rgb(240,50,120)\"/> \n";
    }
    return outputStream;
  }


  /* Polgon class codes ends...                                               */
}//end svg namespace
