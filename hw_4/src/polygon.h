#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <ostream>
#include <vector>

class Circle;
class Rectangle;
class Triangle;

using namespace std;

namespace svg {
  #define PI 3.14159265359
  #define RAD 57.2958
  #define DEG 1/RAD
  enum class Shape_name { rectangle, triangle, circle };

  class Polygon {
  public:
    class Point2D {
    public:
      Point2D(int r, int c);
      Point2D();

      int getRow() const;
      int getCol() const;
      int getRotation() const;

      void setRow(int newR);
      void setCol(int newC);
      void setRotation(int newRotation);

      Point2D operator ++();
      Point2D operator ++(int);
      Point2D operator --();
      Point2D operator --(int);
      bool operator ==(const Point2D& secPoint);
      bool operator !=(const Point2D& secPoint);
    private:
      int r=0, c=0;
      int rotation =0;
    };

    //CONSTRUCTORS
    Polygon(const vector<Point2D> newPoints);
    Polygon(const Point2D& newPoint);
    Polygon(const Circle& newCircle);
    Polygon(const Rectangle& newRectangle);
    Polygon(const Triangle& newTriangle);
    Polygon();

    //BIG THREE
    Polygon(const Polygon &newPolygon);
    Polygon operator = (const Polygon &newPolygon);
    ~Polygon();

    //SETTERS AND GETTERS
    void setSize(int newSize);
    void setPolygon(const vector<Point2D> newPoints);
    void setPoint(const Point2D newPoint);
    void setCircle(const Circle& newCircle);
    void setRectangle(const Rectangle& newRectangle);
    void setTriangle(const Triangle& newTriangle);
    Point2D* getPolygon() const;
    int getSize() const;

    ostream& initSvgFile(ostream& outputStream);

    //OPERATOR OVERLOADINGS
    const Point2D& operator [] (int index) const;
    Point2D& operator [] (int index);
    bool operator ==(const Polygon& polygon2);
    bool operator !=(const Polygon& polygon2);
    Polygon operator +(const Polygon& polygon2);
    friend ostream& operator <<(ostream& outputStream, const Polygon& polygon);

  private:
    Point2D * points =nullptr;
    int size=0;
  };
}//end of svg namespace

#endif
