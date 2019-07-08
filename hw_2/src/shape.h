#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "base.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

class Shape {
public:
  Shape (Shape_name sName):name(sName){ /*intentionally empty*/ };
  Shape () { /*intentionally empty*/ };

  Shape_name getShapeName() { return name; }
  Circle getCircle() { return circle; }
  Rectangle getRectangle() { return rectangle; }
  Triangle getTriangle() { return triangle; }

  int getCircleCenterCol() { return circle.getCenterCol(); }
  int getCircleCenterRow() { return circle.getCenterRow(); }
  int getCircleRadius() { return circle.getRadius(); }

  int getRectStartPointCol() { return rectangle.getStartPointCol(); }
  int getRectStartPointRow() { return rectangle.getStartPointRow(); }
  int getRectWidth() { return rectangle.getWidth(); }
  int getRectHeight() { return rectangle.getHeight(); }

  int getTrianglePeakPointCol() { return triangle.getPeakPointCol();  }
  int getTrianglePeakPointRow() { return triangle.getPeakPointRow();  }
  Point getTrianglePeakPoint()  { return triangle.getPeakPoint();     }
  int getTriangleEdge()         { return triangle.getEdge(); }
  int getTriangleRotationAngle(){ return triangle.getRotationAngle(); }

  void setShapeName(Shape_name newName);

  void setCircleRadius(int newRadius);
  void setCircleCenter(int newCol, int newRow);

  void setRectStartPoint(int newCol, int newRow);
  void setRectWidth(int newWidth);
  void setRectHeight(int newHeight);

  void setTrianglePeakPoint(int newCol, int newRow);
  void setTriangleEdge(int newEdge);
  void setTriangleRotationAngle(int newRotationAngle);


private:
  Shape_name name;
  union {
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
  };
};


#endif
