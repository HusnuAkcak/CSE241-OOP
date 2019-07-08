#include <iostream>
#include "polygon.h"
#include "polyline.h"

using namespace std;

namespace svg {
  Polyline::Polyline (const Polygon& newPolygon) {
    polygon = newPolygon;
  }

  Polyline::Polyline (const vector<Polygon::Point2D> newPoints) {
    polygon = newPoints;
  }

  Polyline::Polyline (const Circle& newCircle) {
    polygon = newCircle;
  }

  Polyline::Polyline (const Rectangle& newRectangle) {
    polygon = newRectangle;
  }

  Polyline::Polyline (const Triangle& newTriangle) {
    polygon = newTriangle;
  }

  Polyline::Polyline (const Polygon::Point2D& newPoint) {
    polygon = newPoint;
  }

  Polyline::Polyline () {
    /* intentionally empty */
  }

  void
  Polyline::setPolygon(const Polygon& newPolygon) {
    polygon = newPolygon;
    return;
  }

  void
  Polyline::setCircle(const Circle& newCircle) {
    polygon = newCircle;
    return;
  }

  void
  Polyline::setRectangle(const Rectangle& newRectangle) {
    polygon = newRectangle;
    return;
  }

  void
  Polyline::setTriangle(const Triangle& newTriangle) {
    polygon = newTriangle;
    return;
  }

  void
  Polyline::setVectorPoint(const vector<Polygon::Point2D> vectorPoint2D) {
    polygon = vectorPoint2D;
    return;
  }

  void
  Polyline::setPoint(const Polygon::Point2D& newPoint) {
    polygon = newPoint;
    return;
  }

  Polygon
  Polyline::getPolygon() const {
    return polygon;
  }

  ostream&
  Polyline::initSvgFile(ostream& outputStream) {
    return polygon.initSvgFile(outputStream);
  }

  const Polygon::Point2D&
  Polyline::operator [] (int index) const {
    return polygon[index];
  }

  Polygon::Point2D&
  Polyline::operator [] (int index) {
    return polygon[index];
  }

  bool
  Polyline::operator ==(const Polyline& polyline2) {
    return polygon == polyline2.polygon;
  }

  bool
  Polyline::operator !=(const Polyline& polyline2) {
    return polygon != polyline2.polygon;
  }

  Polyline
  Polyline::operator +(const Polyline& polyline2) {
    polygon + polyline2.polygon;
    return *this;
  }


  ostream&
  operator <<(ostream& outputStream, const Polyline& polyline) {
    outputStream << "  <polyline points= \"";
    for (int i=0; i< polyline.polygon.getSize(); ++i) {
      outputStream  << polyline.polygon[i].getCol()<< ", "
                    << polyline.polygon[i].getRow()<< " ";
    }
    outputStream  << "\" stroke = \"red\" stroke-width=\"5\" "
                  << "fill = \"blue\"/> \n";

    return outputStream;
  }

};
