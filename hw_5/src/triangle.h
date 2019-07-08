#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <fstream>
#include <cmath>
#include "shape.h"
#include "point2d.h"

using namespace std;

namespace geometrical {

  class Triangle: public Shape{
  public:
    Triangle(int c, int r, int edge, int rotationAngle)throw(invalid_argument);
    Triangle(int edge, int rotationAngle)throw(invalid_argument);
    Triangle(int edge)throw(invalid_argument);
    Triangle() noexcept;

    int getPeakPointCol() const noexcept;
    int getPeakPointRow() const noexcept;
    Point2D getPeakPoint() const noexcept;
    int getEdge() const noexcept;
    int getRotationAngle() const noexcept;
    static int getTotalCount() noexcept;
    static double getTotalArea() noexcept;
    static double getTotalPerimeter() noexcept;

    void setPeakPoint(int c, int r) throw(invalid_argument);
    void setEdge(int edge) throw(invalid_argument);
    void setRotationAngle(int rotationAngle)noexcept;

    virtual double perimeter() const noexcept override;
    virtual double area() const noexcept override;

    void calcTriangleBottomNodes (Point2D & tLeftBtmNode,
                            Point2D & tRightBtmNode) const noexcept;

    //comperison operator overloadings
    virtual bool operator == (const Shape& s2)const noexcept override;
    virtual bool operator != (const Shape& s2)const noexcept override;
    virtual bool operator <  (const Shape& s2)const noexcept override;
    virtual bool operator <= (const Shape& s2)const noexcept override;
    virtual bool operator >  (const Shape& s2)const noexcept override;
    virtual bool operator >= (const Shape& s2)const noexcept override;

    virtual Triangle& operator ++() noexcept override;   // incr shape pos by 1
    virtual Triangle& operator --() noexcept override;   // decr shape pos by 1
    virtual Triangle& operator ++(int) noexcept override;// incr shape pos by 1
    virtual Triangle& operator --(int) noexcept override;// decr shape pos by 1

    virtual ostream& print(ostream& ouputStream) noexcept override;
    friend ostream& operator << (ostream& outputStream, Triangle& triangle) noexcept;

    friend Triangle operator + (const Triangle& tri, double increment) noexcept;
    friend Triangle operator + (double increment, const Triangle& tri) noexcept;
    friend Triangle operator + (const Triangle& t1, const Triangle& t2) noexcept;
    friend Triangle operator - (const Triangle& tri, double decrement)throw(invalid_argument);
    friend Triangle operator - (double decrescent, const Triangle& tri)throw(invalid_argument);
    friend Triangle operator - (const Triangle& t1, const Triangle& t2) throw(invalid_argument);
  private:
    Point2D peakPoint;
    int edge=0, rotationAngle=0;
    static int totalCount;
    static double totalArea, totalPerimeter;

    void updateTotalArea(int oldEdge, int newEdge) noexcept;
    void updateTotalPerimeter(int oldEdge ,int newEdge) noexcept;
  };
} // end of geometrical namespace
#endif
