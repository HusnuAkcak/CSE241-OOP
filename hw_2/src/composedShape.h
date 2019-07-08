#ifndef _COMPOSED_SHAPE_H_
#define _COMPOSED_SHAPE_H_

#include <vector>
#include <cmath>
#include "shape.h"
using namespace std;

class ComposedShape {
public:
  ComposedShape(Shape container, vector<Shape> smallShape);
  ComposedShape() { ++outputCounter; };

  Shape getContainer() const  { return container;  }
  Shape getSampleSmallShape() const { return sampleSmallShape; }
  vector<Shape> getSmallShape() const { return smallShape; }
  int getCounter() const { return outputCounter; }

  void input();
  void inputContainerData();
  void inputSmallShapeData();
  void inputShapeData(Shape & newShape, string message);
  void inputCircleData(Shape & newCircle);
  void inputRectangleData(Shape & newRectangle);
  void inputTriangleData(Shape & newTriangle);

  void setCounter(int newCounter);
  void setContainer(Shape newContainer);
  void setSmallShapeVector(vector<Shape> newSmallShape);
  void setSampleSmallShape(Shape newSampleSmallShape);
  void setFilePtr(ofstream newFilePtr);

  void initSvgFile ( );
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

  void drawShapes(string fileName);
  void drawContainer(int width, int height);

  void optimalFit();
  void showCalcResults(int count, int totalArea, int coveredArea);

private:
  static int outputCounter;
  Shape container;
  Shape sampleSmallShape;
  vector<Shape> smallShape;
  ofstream filePtr;

};

#endif
