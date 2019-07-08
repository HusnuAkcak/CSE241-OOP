#include <iostream>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

void
Shape::setShapeName(Shape_name newName) {
  name=newName;
  return;
}

void
Shape::setCircleRadius(int newRadius) {
  circle.setRadius(newRadius);
  return;
}

void
Shape::setCircleCenter(int newCol, int newRow) {
  circle.setCenter(newCol, newRow);
  return;
}

void
Shape::setRectStartPoint(int newCol, int newRow) {
  rectangle.setStartPoint(newCol, newRow);
}

void
Shape::setRectWidth(int newWidth) {
  rectangle.setWidth(newWidth);
}

void
Shape::setRectHeight(int newHeight) {
  rectangle.setHeight(newHeight);
}


void
Shape::setTrianglePeakPoint(int newCol, int newRow) {
  triangle.setPeakPoint(newCol, newRow);
}

void
Shape::setTriangleEdge(int newEdge) {
  triangle.setEdge(newEdge);
}

void
Shape::setTriangleRotationAngle(int newRotationAngle) {
  triangle.setRotationAngle(newRotationAngle);
}
