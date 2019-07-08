#ifndef _COMPOSED_SHAPE_H_
#define _COMPOSED_SHAPE_H_

#include <vector>
#include <cmath>
#include "base.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
using namespace std;

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
    Point getTrianglePeakPoint();
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

  ComposedShape(ShapeElem container, ShapeElem sampleSmallShape);
  ComposedShape() { ++outputCounter; };

  ShapeElem getContainer() const  { return container;  }
  ShapeElem getSampleSmallShape() const { return sampleSmallShape; }
  vector<ShapeElem> getSmallShape() const { return smallShape; }
  int getCounter() const { return outputCounter; }

  void input();
  void inputContainerData();
  void inputSmallShapeData();
  void inputShapeData(ShapeElem & newShape, string message);
  void inputCircleData(ShapeElem & newCircle);
  void inputRectangleData(ShapeElem & newRectangle);
  void inputTriangleData(ShapeElem & newTriangle);

  void setCounter(int newCounter);
  void setContainer(ShapeElem newContainer);
  void setSmallShapeVector(vector<ShapeElem> newSmallShape);
  void setSampleSmallShape(ShapeElem newSampleSmallShape);


  void initSvgFile (ostream& filePtr);
  //  Takes mainContainer and initialize the svg file.

  bool isCircleIntersectWithOtherCircles(int smallCircleCenterCol, int smallCircleCenterRow);
  // Controls, if the given the small shape circles are intersect or not at given point.

  bool isRectIntersectToTheOthers(Point & newRect);
  // controls if there is an intersection btw rectangles.

  bool isRectInCircle(Point &rectStartPoint);
  // controls if small shape rect is in main container circle or not

  bool isTriInCircle(Point &newTri);

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

  // void drawShapes(string fileName);
  void drawContainer(ostream& filePtr, int width, int height);

  void optimalFit();
  void showCalcResults(int count, int totalArea, int coveredArea);

  const ShapeElem& operator [] (const int index)const { return smallShape[index]; }
  ShapeElem& operator [] (const int index) { return smallShape[index]; }
  void operator += (const ShapeElem& innerShape) { smallShape.push_back(innerShape); return;}
  friend ostream& operator << (ostream& outputStream, ComposedShape& comShape);

private:
  static int outputCounter;
  ShapeElem container;
  vector<ShapeElem> smallShape;
  ShapeElem sampleSmallShape;
};

#endif
