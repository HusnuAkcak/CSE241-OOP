#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <ostream>
#include "shape.h"
#include "math.h"

using namespace std;

// two of global functions are at the end of this file (printPoly, convertAll).
namespace geometrical {
  class Polygon :public Shape{
  public:
    // I do not declare a constructor, because there is no member variable.

    virtual double area()const override=0;     // area calculation.
    virtual double perimeter()const override=0;// perimeter calculation.

    virtual Polygon& operator ++()noexcept override=0;   //incr. shape pos. by 1
    virtual Polygon& operator --()noexcept override=0;   //decr. shape pos. by 1
    virtual Polygon& operator ++(int)noexcept override=0;//incr. shape pos. by 1
    virtual Polygon& operator --(int)noexcept override=0;//decr. shape pos. by 1

    // print function, prints the shape in a svg file
    virtual ostream& print(ostream& outputStream)noexcept override=0;

    //OPERATOR OVERLOADINGS
    virtual bool operator == (const Shape& s2)const noexcept override;
    virtual bool operator != (const Shape& s2)const noexcept override;
    virtual bool operator <  (const Shape& s2)const noexcept override;
    virtual bool operator <= (const Shape& s2)const noexcept override;
    virtual bool operator >  (const Shape& s2)const noexcept override;
    virtual bool operator >= (const Shape& s2)const noexcept override;

    double calcDistBtwTwoPoint (int x1, int x2, int y1, int y2) const {
          return( sqrt(pow((x2-x1), 2) + pow((y2-y1), 2)) );
    }
  };

  //GLOBAL FUNCTION PROTOTYPES STARTS (TWO OF FOUR FUNCTIONS)
  void printPoly(vector<Shape*>& polygons);
  vector<Shape*> convertAll(const vector<Shape*>& shapes);
  //GLOBAL FUNCTION PROTOTYPES END
}//end of geometrical namespace

#endif
