#include <iostream>
#include <cmath>
#include "base.h"
#include "triangle.h"
#include "shape.h"

using namespace std;

Triangle::Triangle(int c, int r, int edge, int rotationAngle) {
  setPeakPoint(c, r);
  setEdge(edge);
  setRotationAngle(rotationAngle);
}

Triangle::Triangle(int edge, int rotationAngle) {
  setEdge(edge);
  setRotationAngle(rotationAngle);
}

Triangle::Triangle(int edge) {
  setEdge(edge);
  setRotationAngle(0);
}

void
Triangle::setPeakPoint(int c, int r) {
  peakPoint.setCol(c);
  peakPoint.setRow(r);
  return;
}

void
Triangle::setEdge(int newEdge) {
  if(newEdge > 0) {
    edge = newEdge;
  }
  return;
}

void
Triangle::setRotationAngle(int newRotationAngle) {
  if(newRotationAngle >=0 && newRotationAngle <= 360) {
      rotationAngle = newRotationAngle;
  }
  return;
}

void
Triangle::draw(ofstream &filePtr) {
  Point tLeftBtmNode, tRightBtmNode;
  calcTriangleBottomNodes(tLeftBtmNode, tRightBtmNode);

  filePtr << "  <polygon points= \""
            << peakPoint.getCol()    << " "
            << peakPoint.getRow()    << " "
            << tLeftBtmNode.getCol() << " " << tLeftBtmNode.getRow() << " "
            <<tRightBtmNode.getCol() << " " << tRightBtmNode.getRow() << "\""
          << " transform = \"rotate("
            << rotationAngle      << " "
            << peakPoint.getCol() << " "
            << peakPoint.getRow() << ")\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb("<< edge%255 <<","<< edge%55 <<","<< edge%155 <<")\"/> \n";
  return;
}

void
Triangle::calcTriangleBottomNodes (Point & tLeftBtmNode, Point & tRightBtmNode) {

  tLeftBtmNode.setRow(peakPoint.getRow() + (double(edge)/ 2.0 )*(sqrt(3)) );
  tLeftBtmNode.setCol(peakPoint.getCol() + double(edge)/ 2.0 );
  tRightBtmNode.setRow(peakPoint.getRow() + (double(edge)/ 2.0 )*(sqrt(3)) );
  tRightBtmNode.setCol(peakPoint.getCol() - double(edge)/ 2.0 );
  return;
}
