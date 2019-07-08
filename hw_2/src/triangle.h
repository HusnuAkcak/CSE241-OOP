#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <fstream>

using namespace std;

class Triangle{

public:
  Triangle(int c, int r, int edge, int rotationAngle);
  Triangle(int edge, int rotationAngle);
  Triangle(int edge);
  Triangle() { /*intentionally empty */ }

  int getPeakPointCol() { return peakPoint.getCol(); }
  int getPeakPointRow() { return peakPoint.getRow(); }
  Point getPeakPoint()  { return peakPoint; }
  int getEdge()   const { return edge; }
  int getRotationAngle() const { return rotationAngle; }

  void setPeakPoint(int c, int r);
  void setEdge(int edge);
  void setRotationAngle(int rotationAngle);

  void calcTriangleBottomNodes (Point & tLeftBtmNode, Point & tRightBtmNode);

  void draw(ofstream &filePtr);

private:
  Point peakPoint;
  int edge;
  int rotationAngle;
};

#endif
