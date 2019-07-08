#include <iostream>
#include <cmath>
#include "base.h"
#include "export.h"
#include "calc.h"

using namespace std;

bool
is_circle_intersect_to_the_others(const Shape & smallShape,
                                Point & smallCenter,Point *& currPoint) {

  Point * tempPoint;
  bool intersect;
  double distance;

  intersect = false;
  tempPoint = currPoint;

  while ( intersect == false && tempPoint!= NULL ) {

    distance = sqrt(  pow((tempPoint->c - smallCenter.c), 2) +
                      pow((tempPoint->r - smallCenter.r), 2) );

    if ( distance < (smallShape.circle.radius*2) )
      intersect = true;

    tempPoint=( tempPoint->next );
  }

  return intersect;
}

bool
is_rect_intersect_to_the_others(const Shape& smallShape,
                                      Point & newRect, Point *& currPoint) {

  Point * tempPoint;
  bool intersect;
  double distVert, distHoriz;

  intersect = false;
  tempPoint = currPoint;
  while ( intersect == false && tempPoint!= NULL ) {

    distVert  = abs((tempPoint -> r) - newRect.r);
    distHoriz = abs((tempPoint -> c) - newRect.c);

    if( distVert < smallShape.rectangle.height &&
        distHoriz < smallShape.rectangle.width    ){

      intersect = true;
    }

    tempPoint=( tempPoint->next );
  }

  return intersect;

}

bool
is_rect_in_circle(const Shape & mainContainer,
                              const Shape & smallShape,  Point & newRect) {

  double dist1, dist2, dist3, dist4;
  Point rightUp, rightDown, leftUp, leftDown;
  bool fit;

  // applicant rectangle vertices.
  leftUp     = newRect;
  leftDown.r = newRect.r + smallShape.rectangle.height;
  leftDown.c = newRect.c;
  rightUp.r  = newRect.r;
  rightUp.c  = newRect.c + smallShape.rectangle.width;
  rightDown.r= newRect.r + smallShape.rectangle.height;
  rightDown.c= newRect.c + smallShape.rectangle.width;

  // dist between new final point and main container center.
  dist1 =  sqrt( pow((leftUp.c - mainContainer.circle.radius), 2) +
                pow((leftUp.r - mainContainer.circle.radius), 2) );

  dist2 =  sqrt( pow((leftDown.c - mainContainer.circle.radius), 2) +
                pow((leftDown.r - mainContainer.circle.radius), 2) );

  dist3 =  sqrt( pow((rightUp.c - mainContainer.circle.radius), 2) +
                pow((rightUp.r - mainContainer.circle.radius), 2) );

  dist4 =  sqrt( pow((rightDown.c - mainContainer.circle.radius), 2) +
                pow((rightDown.r - mainContainer.circle.radius), 2) );

  if (
        (dist1 >= mainContainer.circle.radius) ||
        (dist2 >= mainContainer.circle.radius) ||
        (dist3 >= mainContainer.circle.radius) ||
        (dist4 >= mainContainer.circle.radius)

    ) {
    fit = false;
  }
  else {
    fit = true;
  }

  return fit;
}

bool
is_tri_in_circle(const Shape & mainContainer,
                              const Shape & smallShape,  Point &newTri){
  bool fit;
  double dist1, dist2, dist3;
  Point up, rightDown, leftDown;

  // applicant rectangle vertices.
  up     = newTri;
  leftDown.r = newTri.r + sqrt(3.0)/2.0*smallShape.triangle.edge;
  leftDown.c = newTri.c - smallShape.triangle.edge/2;
  rightDown.r= newTri.r + sqrt(3.0)/2.0*smallShape.triangle.edge;
  rightDown.c= newTri.c + smallShape.triangle.edge/2;

  // dist between new final point and main container center.
  dist1 =  sqrt( pow((up.c - mainContainer.circle.radius), 2) +
                pow((up.r - mainContainer.circle.radius), 2) );

  dist2 =  sqrt( pow((leftDown.c - mainContainer.circle.radius), 2) +
                pow((leftDown.r - mainContainer.circle.radius), 2) );

  dist3 =  sqrt( pow((rightDown.c - mainContainer.circle.radius), 2) +
                pow((rightDown.r - mainContainer.circle.radius), 2) );

  if (
        (dist1 >= mainContainer.circle.radius) ||
        (dist2 >= mainContainer.circle.radius) ||
        (dist3 >= mainContainer.circle.radius)
    ) {
    fit = false;
  }
  else {
    fit = true;
  }

  return fit;
}



void
calc_triangle_bottom_nodes (const Shape & shape, Point *& currPoint,
                                        Point & btmNode1, Point & btmNode2) {

  btmNode1.r = currPoint -> r + (double(shape.triangle.edge)/ 2.0 )*(sqrt(3));
  btmNode1.c = currPoint -> c + double(shape.triangle.edge)/ 2.0;
  btmNode2.r = currPoint -> r + (double(shape.triangle.edge)/ 2.0 )*(sqrt(3));
  btmNode2.c = currPoint -> c - double(shape.triangle.edge)/ 2.0;
  return;
}
