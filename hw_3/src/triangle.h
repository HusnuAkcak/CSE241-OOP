#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <fstream>
#include <cmath>

using namespace std;

class Triangle{

public:
  Triangle(int c, int r, int edge, int rotationAngle);
  Triangle(int edge, int rotationAngle);
  Triangle(int edge);
  Triangle() :edge(0), rotationAngle(0){ peakPoint.setRow(0); peakPoint.setCol(0); ++totalCount; }

  int getPeakPointCol() { return peakPoint.getCol(); }
  int getPeakPointRow() { return peakPoint.getRow(); }
  Point getPeakPoint()  { return peakPoint; }
  int getEdge()   const { return edge; }
  int getRotationAngle() const { return rotationAngle; }
  int getPerimeter() const { return 3*edge; }
  double getArea() const { return (edge*sqrt(3)/4); }
  static int getTotalCount() { return totalCount; }
  static double getTotalArea() { return totalArea; }
  static double getTotalPerimeter() { return totalPerimeter; }

  void setPeakPoint(int c, int r);
  void setEdge(int edge);
  void setRotationAngle(int rotationAngle);

  void calcTriangleBottomNodes (Point & tLeftBtmNode, Point & tRightBtmNode) const;

  Triangle operator ++ () { ++peakPoint; return *this; }
  Triangle operator ++ (int) { Triangle temp=*this; ++(*this); return temp; }
  Triangle operator -- () { --peakPoint; return *this; }
  Triangle operator -- (int) { Triangle temp=*this; --(*this); return temp; }
  bool operator ==(const Triangle& tri2) const { return getArea() == tri2.getArea(); }
  bool operator !=(const Triangle& tri2) const { return getArea() != tri2.getArea(); }

  friend ostream& operator << (ostream& outputStream, const Triangle& triangle );
  friend Triangle operator + (const Triangle& tri, double increment);
  friend Triangle operator + (double increment, const Triangle& tri);
  friend Triangle operator + (const Triangle& t1, const Triangle& t2);
  friend Triangle operator - (const Triangle& tri, double decrement);
  friend Triangle operator - (double decrescent, const Triangle& tri);
  friend Triangle operator - (const Triangle& t1, const Triangle& t2);
private:
  Point peakPoint;
  int edge=0, rotationAngle=0;
  static int totalCount;
  static double totalArea, totalPerimeter;

  void updateTotalArea(int oldEdge, int newEdge);
  void updateTotalPerimeter(int oldEdge ,int newEdge);
};

#endif
