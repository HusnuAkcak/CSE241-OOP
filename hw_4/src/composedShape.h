#ifndef _COMPOSED_SHAPE_H_
#define _COMPOSED_SHAPE_H_

#include <vector>
#include <cmath>
#include "polygon.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;
using namespace svg;

class ComposedShape {
public:
  class ShapeElem {
  public:
    ShapeElem (Shape_name sName);
    ShapeElem ();
    ShapeElem (const ShapeElem &obj);
    ShapeElem operator =(const ShapeElem &obj);
    ~ShapeElem ();

    Shape_name getShapeName()const { return name; }
    Circle getCircle()const      { if(name==Shape_name::circle) return *(static_cast<Circle*>(shape)); }
    Rectangle getRectangle()const{ if(name==Shape_name::rectangle) return *(static_cast<Rectangle*>(shape)); }
    Triangle getTriangle()const  { if(name==Shape_name::triangle) return *(static_cast<Triangle*>(shape)); }

    int getCircleCenterCol();
    int getCircleCenterRow();
    int getCircleRadius();

    int getRectStartPointCol();
    int getRectStartPointRow();
    int getRectWidth();
    int getRectHeight();

    int getTrianglePeakPointCol();
    int getTrianglePeakPointRow();
    Polygon::Point2D getTrianglePeakPoint();
    int getTriangleEdge();
    int getTriangleRotationAngle();

    void setShapeName(Shape_name newName);

    void setCircle(const Circle& obj);
    void setCircleRadius(int newRadius);
    void setCircleCenter(int newCol, int newRow);

    void setRectangle(const Rectangle& obj);
    void setRectStartPoint(int newCol, int newRow);
    void setRectWidth(int newWidth);
    void setRectHeight(int newHeight);

    void setTriangle(const Triangle& obj);
    void setTrianglePeakPoint(int newCol, int newRow);
    void setTriangleEdge(int newEdge);
    void setTriangleRotationAngle(int newRotationAngle);

  private:
    Shape_name name;
    void * shape = nullptr;
  };

  ComposedShape(const vector<Polygon> shape);
  ComposedShape(const Polygon container, const Polygon smallShape);
  ComposedShape(const ShapeElem container, const ShapeElem smallShape);
  ComposedShape() { /*intentionally empty */ };

  ShapeElem getContainer()   const { return container;  }
  ShapeElem getSmallShape()  const { return smallShape; }
  vector<Polygon> getShape() const { return shape; }

  void input();
  void inputContainerData();
  void inputSmallShapeData();
  void inputShapeData(ShapeElem & newShape, string message);
  void inputCircleData(ShapeElem & newCircle);
  void inputRectangleData(ShapeElem & newRectangle);
  void inputTriangleData(ShapeElem & newTriangle);

  void setShapeVector(const vector<Polygon> newShape);
  void setContainer(const ShapeElem newContainer);
  void setContainer(const Polygon newContainer);
  void setSmallShape(const ShapeElem newSmallShape);
  void setSmallShape(const Polygon newSmallShape);
  ShapeElem convertPolygonToShapeElem (const Polygon newPolygon);

  //  Takes mainContainer and initialize the svg file.
  void initSvgFile (ostream& filePtr);

  // Controls, if the given the small shape circles are intersect or not at given point.
  bool isCircleIntersectWithOtherCircles(int smallCircleCenterCol, int smallCircleCenterRow);

  // controls if there is an intersection btw rectangles.
  bool isRectIntersectToTheOthers(Polygon::Point2D & newRect);

  // controls if small shape rect is in main container circle or not
  bool isRectInCircle(Polygon::Point2D &rectStartPoint);

  bool isTriInCircle(Polygon::Point2D &newTri);

  double calcDistBtwTwoPoint(int x1, int x2, int y1, int y2) {
    return( sqrt(pow((x2-x1), 2) + pow((y2-y1), 2)) );
  }

  void fillCircleWithCircle( );
  void fillCircleWithRectangle();
  void fillCircleWithTriangle();
  void fillRectangleWithCircle();
  void fillRectangleWithRectangle();
  void fillRectangleWithTriangle();
  void fillTriangleWithCircle();
  void fillTriangleWithRectangle();
  void fillTriangleWithTriangle();

  void drawContainer(ostream& filePtr, int width, int height);

  void optimalFit();
  void showCalcResults(int count, int totalArea, int coveredArea);

  const Polygon& operator [] (const int index)const { return shape[index]; }
  Polygon& operator [] (const int index) { return shape[index]; }
  void operator += (const Polygon& newPolygon) { shape.push_back(newPolygon); return;}
  friend ostream& operator << (ostream& outputStream, ComposedShape& comShape);

private:
  vector<Polygon> shape;
  ShapeElem container;
  ShapeElem smallShape;
};

#endif
