#include <iostream>
#include <cmath>
#include "base.h"
#include "triangle.h"

using namespace std;

// static variable initializations
int Triangle::totalCount= 0;
double Triangle::totalArea= 0;
double Triangle::totalPerimeter= 0;

Triangle::Triangle(int c, int r, int edge, int rotationAngle) {
  setPeakPoint(c, r);
  setEdge(edge);
  setRotationAngle(rotationAngle);
  ++totalCount;
}

Triangle::Triangle(int edge, int rotationAngle) {
  setEdge(edge);
  setRotationAngle(rotationAngle);
  ++totalCount;
}

Triangle::Triangle(int edge) {
  setEdge(edge);
  setRotationAngle(0);
  ++totalCount;
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
    updateTotalArea(getEdge(), newEdge);
    updateTotalPerimeter(getEdge(), newEdge);
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
Triangle::calcTriangleBottomNodes (Point& tLeftBtmNode,Point& tRightBtmNode)const {

  tLeftBtmNode.setRow(peakPoint.getRow() + (double(edge)/ 2.0 )*(sqrt(3)) );
  tLeftBtmNode.setCol(peakPoint.getCol() + double(edge)/ 2.0 );
  tRightBtmNode.setRow(peakPoint.getRow() + (double(edge)/ 2.0 )*(sqrt(3)) );
  tRightBtmNode.setCol(peakPoint.getCol() - double(edge)/ 2.0 );
  return;
}

void
Triangle::updateTotalArea(int oldEdge, int newEdge) {
  double beforeArea, newArea;
  beforeArea = (oldEdge*oldEdge)*sqrt(3.0)/4.0;
  newArea = (newEdge*newEdge)*sqrt(3.0)/4.0;
  totalArea = totalArea - beforeArea + newArea;
  return;
}

void
Triangle::updateTotalPerimeter(int oldEdge ,int newEdge) {
  double beforePerimeter, newPerimeter;
  beforePerimeter = oldEdge *3;
  newPerimeter = newEdge *3;
  totalPerimeter = totalPerimeter - beforePerimeter + newPerimeter;
  return;
}

ostream&
operator << (ostream& outputStream, const Triangle& tri ) {
  Point tLeftBtmNode, tRightBtmNode;
  tri.calcTriangleBottomNodes(tLeftBtmNode, tRightBtmNode);

  outputStream << "  <polygon points= \""
                << tri.peakPoint.getCol()    << " "
                << tri.peakPoint.getRow()    << " "
                << tLeftBtmNode.getCol() << " " << tLeftBtmNode.getRow() << " "
                <<tRightBtmNode.getCol() << " " << tRightBtmNode.getRow() << "\""
          << " transform = \"rotate("
                << tri.rotationAngle      << " "
                << tri.peakPoint.getCol() << " "
                << tri.peakPoint.getRow() << ")\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb("<< tri.edge%150 <<","<< tri.edge%50 <<","<< tri.edge%25 <<")\"/> \n";
  return outputStream;
}

// triangle + number
Triangle
operator + (const Triangle& tri, double increment) {
  Triangle temp =tri;
  temp.edge += increment;
  return temp;
}

// number + triangle
Triangle
operator + (double increment, const Triangle& tri) {
  Triangle temp = tri;
  temp.edge += increment;
  return  temp;
}

//triangle + triangle
Triangle
operator + (const Triangle& t1, const Triangle& t2) {
  Triangle temp1= t1, temp2= t2;
  temp1.edge += temp2.edge ;
  return temp1;
}

// triangle - number
Triangle
operator - (const Triangle& tri, double decrement) {
  Triangle temp =tri;

  temp.edge -= decrement;
  if(temp.edge < 0)
    temp.edge=0;

  return temp;
}

// number - triangle
Triangle
operator - (double decrescent, const Triangle& tri) {
  Triangle temp = tri;

  temp.edge = decrescent - temp.edge;
  if(temp.edge<0)
    temp.edge =0;

  return temp;
}

//triangle - triangle
Triangle
operator - (const Triangle& t1, const Triangle& t2) {
  Triangle temp =t1;

  temp.edge = temp.edge - t2.edge;
  if(temp.edge<0)
    temp.edge =0;

  return temp;
}
