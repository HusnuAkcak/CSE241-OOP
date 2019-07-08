#ifndef _BASE_
#define _BASE_

// #define DEBUG
#define PI 3.14159265359
#define RAD 57.2958
#define DEG 1/RAD

/*######################  ENUM AND STRUCTS ###################################*/
enum class Shape_name { rectangle, triangle, circle };

//  r and c will represent the small shapes coordinates.
class Point {
public:
  Point(int r, int c);
  Point() { /*intentionally empty*/ }

  int getRow() const { return r; }
  int getCol() const { return c; }

  void setRow(int r);
  void setCol(int c);

  Point operator ++() { ++r; ++c; return *this; }
  Point operator ++(int) { Point temp=*this; ++(*this); return temp; }
  Point operator --() { --r; --c; return *this; }
  Point operator --(int) { Point temp=*this; --(*this); return temp; }
private:
  int r,c;
};


#endif
