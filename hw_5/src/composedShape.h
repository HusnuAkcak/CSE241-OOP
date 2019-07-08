#ifndef _COMPOSED_SHAPE_H_
#define _COMPOSED_SHAPE_H_

#include <vector>
#include <cmath>
#include "shape.h"
#include "point2d.h"
using namespace std;

namespace geometrical {
  class ComposedShape :public Shape {
  public:
    ComposedShape(Shape* container, Shape* smallShape) noexcept;
    ComposedShape()noexcept;
    ComposedShape(ComposedShape& newComposedShape) throw(bad_cast);
    ComposedShape& operator =(const ComposedShape& cmp2) throw(bad_cast);
    virtual ~ComposedShape()noexcept;
    void freeVector()noexcept;

    Shape* getContainer() noexcept;
    Shape* getSmallShape() noexcept;
    vector<Shape*> getShape() noexcept;

    void setShapeVector(vector<Shape&> newShape);
    void setContainer(Shape* newContainer) throw(bad_cast);
    void setSmallShape(Shape* newSmallShape) throw (container_unavailable, bad_cast);

    virtual double area()const override;      // area calculation.
    virtual double perimeter()const override;  // perimeter calculation.

    virtual ComposedShape& operator ++() noexcept override;   // incr shape pos by 1
    virtual ComposedShape& operator --() noexcept override;   // decr shape pos by 1
    virtual ComposedShape& operator ++(int) noexcept override;// incr shape pos by 1
    virtual ComposedShape& operator --(int) noexcept override;// decr shape pos by 1

    // comperison operators.
    virtual bool operator == (const Shape& s2)const noexcept override;
    virtual bool operator != (const Shape& s2)const noexcept override;
    virtual bool operator <  (const Shape& s2)const noexcept override;
    virtual bool operator <= (const Shape& s2)const noexcept override;
    virtual bool operator >  (const Shape& s2)const noexcept override;
    virtual bool operator >= (const Shape& s2)const noexcept override;

    void initSvgFile (ostream& filePtr) throw(container_unavailable);
    //  Takes mainContainer and initialize the svg file.

    bool isCircleIntersectWithOtherCircles(int smallCircleCenterCol, int smallCircleCenterRow);
    // Controls, if the given the small shape circles are intersect or not at given point.

    bool isRectIntersectToTheOthers(Point2D & newRect);
    // controls if there is an intersection btw rectangles.

    bool isRectInCircle(Point2D &rectStartPoint);
    // controls if small shape rect is in main container circle or not

    bool isTriInCircle(Point2D &newTri);

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

    void optimalFit() throw(container_unavailable, smallShape_unavailable);
    void showCalcResults(int count, int totalArea, int coveredArea);

    // print function, prints the shape in a svg file
    virtual ostream& print(ostream& outputStream)noexcept override;
    friend ostream& operator << (ostream& outputStream, ComposedShape& comShape);

  private:
    vector<Shape*> composed;
  };
}//end of geometrical namespace.
#endif
