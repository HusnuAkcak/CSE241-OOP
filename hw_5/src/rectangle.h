#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <fstream>
#include "shape.h"
#include "point2d.h"

using namespace std;

namespace geometrical {

  class Rectangle :public Shape{
  public:
    Rectangle(int c, int r, int width, int height) throw(invalid_argument);
    Rectangle(int width, int height) throw(invalid_argument);
    Rectangle() noexcept;

    int getStartPointCol()const noexcept;
    int getStartPointRow()const noexcept;
    int getWidth() const noexcept;
    int getHeight() const noexcept;
    virtual double perimeter() const noexcept override;
    virtual double area() const noexcept override;

    static int getTotalCount() noexcept;
    static double getTotalPerimeter() noexcept;
    static double getTotalArea() noexcept;

    void setStartPoint(int c, int r) throw(invalid_argument);
    void setWidth(int width) throw(invalid_argument);
    void setHeight(int height) throw(invalid_argument);

    virtual Rectangle& operator ++ () noexcept override;
    virtual Rectangle& operator -- () noexcept override;
    virtual Rectangle& operator ++ (int) noexcept override;
    virtual Rectangle& operator -- (int) noexcept override;
    
    virtual bool operator ==(const Shape& rect2)const noexcept override;
    virtual bool operator !=(const Shape& rect2)const noexcept override;
    virtual bool operator >=(const Shape& rect2)const noexcept override;
    virtual bool operator > (const Shape& rect2)const noexcept override;
    virtual bool operator <=(const Shape& rect2)const noexcept override;
    virtual bool operator < (const Shape& rect2)const noexcept override;
    
    virtual ostream& print(ostream& outputStream) noexcept override; 

    friend ostream& operator << (ostream& outputStream, Rectangle& rect) noexcept;
    friend Rectangle operator +(const Rectangle& rect, double increment) noexcept;
    friend Rectangle operator +(double increment, const Rectangle& rect) noexcept;
    friend Rectangle operator +(const Rectangle& r1, const Rectangle& r2) noexcept;
    friend Rectangle operator -(const Rectangle& rect, double decrement) throw(invalid_argument);
    friend Rectangle operator -(double decrescent, const Rectangle& rect) throw(invalid_argument);
    friend Rectangle operator -(const Rectangle& r1, const Rectangle& r2) throw(invalid_argument);
  private:
    Point2D startPoint;
    int width=0, height=0;
    static int totalCount;
    static double totalArea, totalPerimeter;
    //private functions
    void updateTotalArea(int oldWidth, int oldHeight, int newWidth, 
                                                    int newHeight) noexcept;
    void updateTotalPerimeter(int oldWidth, int oldHeight, int newWidth, 
                                                    int newHeight) noexcept;

  };
} // end of geometrical namespace scope
#endif
