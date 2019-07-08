#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <memory>
#include "point2d.h"
#include "shape.h"

using namespace std;

namespace geometrical {
  
  class Circle :public Shape {
  public:
    Circle(int c, int r, int radius) throw(invalid_argument);//center coord. and radius
    Circle() noexcept; 

    int getCenterRow() noexcept;
    int getCenterCol() noexcept;
    int getRadius() const noexcept;
    virtual double perimeter() const noexcept override;
    virtual double area() const noexcept override;
    static int getTotalCount() noexcept;
    static double getTotalArea() noexcept;
    static double getTotalPerimeter() noexcept;

    void setCenter(int c, int r) throw (invalid_argument);
    void setRadius(int radius) throw (invalid_argument);

    virtual Circle& operator ++ () noexcept override; // prefix
    virtual Circle& operator -- () noexcept override; // prefix
    virtual Circle& operator ++ (int) noexcept override; //postfix
    virtual Circle& operator -- (int) noexcept override; //postfix
    virtual bool operator ==(const Shape& circle2)const noexcept override;
    virtual bool operator !=(const Shape& circle2)const noexcept override;
    virtual bool operator < (const Shape& circle2)const noexcept override;
    virtual bool operator <=(const Shape& circle2)const noexcept override;
    virtual bool operator > (const Shape& circle2)const noexcept override; 
    virtual bool operator >=(const Shape& circle2)const noexcept override;

    virtual ostream& print(ostream& outputStream) noexcept override;
   
    friend ostream& operator << (ostream& outputStream, Circle& circle) noexcept;    
    friend Circle operator +(const Circle& circle, double increment) noexcept;
    friend Circle operator +(double increment, const Circle& circle) noexcept;
    friend Circle operator +(const Circle& c1, const Circle& c2) noexcept;
    friend Circle operator -(const Circle& circle, double decrement) throw(invalid_argument);
    friend Circle operator -(double decrescent, const Circle& circle) throw(invalid_argument);
    friend Circle operator -(const Circle& c1, const Circle& c2) throw(invalid_argument);

  private:
    int radius;
    Point2D center;
    static int totalCount;
    static double totalArea;
    static double totalPerimeter;
    //private functions
    void updateTotalArea(int oldRadius, int newRadius) noexcept;
    void updateTotalPerimeter(int oldRadius, int newRadius) noexcept;
  };

}// end of geometrical namespace scope

#endif