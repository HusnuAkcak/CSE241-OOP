#ifndef _BASE_
#define _BASE_

// #define DEBUG
#define PI 3.14159265359
#define RAD 57.2958
#define DEG 1/RAD
/*######################  ENUM AND STRUCTS ###################################*/
enum class Shape_name { rectangle, triangle, circle };

//  r and c will represent the small shapes coordinates.
struct Point {
  int r=0, c=0;
  int rotateDeg = 0;
  struct Point *next;
};

struct Rectangle {
  int height, width;
};

struct Triangle {
  int edge;
};

struct Circle {
  int radius;
};

//  A shape can be a rectangle, a circle or a triangle, so I used union for this purpose.
struct Shape {
  Shape_name name;
  union {
    Rectangle rectangle;
    Triangle triangle;
    Circle circle;
  };
  Point * headShapePoint = NULL;
};

/*######################### FUNCTION DEFINITIONS #############################*/

void free_points ( Point * headPoint );



#endif
