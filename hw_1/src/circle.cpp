#include <iostream>
#include <cmath>
#include "base.h"
#include "export.h"
#include "calc.h"
#include "circle.h"

using namespace std;

void
fill_circle_with_circle( const Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint;
  Point smallCenter;     // center of small circles.
  double theta, totalArea, coveredArea;
  int count,
      designRadius;   // to determine pos of small circles.


  currPoint = NULL;
  tempPoint = NULL;
  count=0;
  cout << "It is being calculated..." << endl;
  for ( designRadius = (mainContainer.circle.radius - smallShape.circle.radius);
        designRadius >= smallShape.circle.radius;
        designRadius -= (smallShape.circle.radius*2)
      ) {
    for ( theta=0; theta <= (2*PI); theta+=(DEG/1000)) {
      // Possible small circle center is calculated.
      smallCenter.r = (mainContainer.circle.radius +(designRadius) * sin(theta));
      smallCenter.c = (mainContainer.circle.radius +(designRadius) * cos(theta));

      if (is_circle_intersect_to_the_others(smallShape, smallCenter, currPoint) == false) {

        tempPoint = (Point*) malloc( sizeof (Point));
        (tempPoint->r)    = smallCenter.r;
        (tempPoint->c)    = smallCenter.c;
        (tempPoint->next) = currPoint;
        currPoint=tempPoint;
        ++count;
      }
    }
  }
  smallShape.headShapePoint = currPoint;

  totalArea = (PI * mainContainer.circle.radius * mainContainer.circle.radius);
  coveredArea = (count*PI*smallShape.circle.radius*smallShape.circle.radius);

  cout  << "\nResults...\n"
        << count<< " number circle is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  draw_circle_in_circle (mainContainer, smallShape);

  return;
}

void
fill_circle_with_rectangle( const Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint;
  Point newRect;      // last added small rectangle.
  double theta, totalArea, coveredArea;
  int count,
      tolerance;  // some free space btw rect and circle to prevent intersection.

  cout << "It is being calculated...\n";
  count=0;
  tolerance=2;
  currPoint = NULL;
  tempPoint = NULL;
  for ( theta=(3*PI/2.0); theta >PI ; theta-=(DEG/100) ) { //from 8th to 7th octant of circle

    //applicant rectangle's top-left point.
    newRect.r = (mainContainer.circle.radius+tolerance +(mainContainer.circle.radius * sin(theta)));
    newRect.c = (mainContainer.circle.radius+tolerance +(mainContainer.circle.radius * cos(theta)));


    if((currPoint== NULL ||
           (abs((currPoint->r) - (newRect.r)) >= (smallShape.rectangle.height))) &&
        is_rect_in_circle(mainContainer, smallShape, newRect) == true &&
        is_rect_intersect_to_the_others(smallShape, newRect, currPoint) == false ) {

      tempPoint = (Point *) malloc (sizeof(Point));
      tempPoint ->r = newRect.r;
      tempPoint ->c = newRect.c;
      tempPoint ->next = currPoint;
      currPoint = tempPoint;

      //applicant rectangle's top-left point.
      newRect.r = (currPoint ->r);
      newRect.c = (currPoint ->c + smallShape.rectangle.width);
      // then it is started to add rectangles next to prev one as much as possible.
      while ( is_rect_in_circle(mainContainer, smallShape, newRect) ==true &&
              is_rect_intersect_to_the_others(smallShape, newRect, currPoint) == false){

        tempPoint = (Point *) malloc (sizeof(Point));
        tempPoint ->c = newRect.c;
        tempPoint ->r = newRect.r;
        tempPoint ->next = currPoint;
        currPoint = tempPoint;
        ++count;

        //applicant rectangle's top-left point.
        newRect.r = (currPoint ->r);
        newRect.c = (currPoint ->c + smallShape.rectangle.width);
      }
    }
  }

  for ( theta=PI; theta > (PI/2.0); theta-=(DEG/100)) { // from 8th to 7th octant of circle

    //applicant rectangle's top-left point.
    newRect.r = (mainContainer.circle.radius +(mainContainer.circle.radius * sin(theta)));
    newRect.c = (mainContainer.circle.radius +(mainContainer.circle.radius * cos(theta)));
    newRect.r -=  smallShape.rectangle.height*2 + (tolerance);  // it is shifted inside of circle.

    if((currPoint== NULL ||
           (abs((currPoint->r) - (newRect.r)) >= (smallShape.rectangle.height))) &&
       is_rect_in_circle(mainContainer, smallShape, newRect) == true     &&
        is_rect_intersect_to_the_others(smallShape,newRect, currPoint) == false) {

      tempPoint = (Point *) malloc (sizeof(Point));
      tempPoint ->r = newRect.r;
      tempPoint ->c = newRect.c;
      tempPoint ->next = currPoint;
      currPoint = tempPoint;
      ++count;

      //applicant rectangle's top-left point.
      newRect.r = (currPoint ->r);
      newRect.c = (currPoint ->c + smallShape.rectangle.width);
      // then it is started to add rectangles next to prev one as much as possible.
      while ( is_rect_in_circle(mainContainer, smallShape, newRect) ==true &&
              is_rect_intersect_to_the_others(smallShape, newRect, currPoint) == false){

        tempPoint = (Point *) malloc (sizeof(Point));
        tempPoint ->c = newRect.c;
        tempPoint ->r = newRect.r;
        tempPoint ->next = currPoint;
        currPoint = tempPoint;

        //applicant rectangle's top-left point.
        newRect.r = (currPoint ->r);
        newRect.c = (currPoint ->c + smallShape.rectangle.width);

      }
    }
  }
  smallShape.headShapePoint = currPoint;

  totalArea = (PI * mainContainer.circle.radius * mainContainer.circle.radius);
  coveredArea = (count*smallShape.rectangle.width*smallShape.rectangle.height);

  cout  << "\nResults...\n"
        << count<< " number rectangle is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  draw_rect_in_circle( mainContainer, smallShape);
  return;
}

void
fill_circle_with_triangle( const Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint;
  Point newTri;      // last added small triangle.
  double theta, totalArea, coveredArea, height;
  bool reversed;
  int count,
      tolerance;  // some free space btw triangle and circle to prevent intersection.

  height = sqrt(3.0)*smallShape.triangle.edge/2.0;
  cout << "It is being calculated...\n";
  count=0;
  tolerance=2;
  currPoint = NULL;
  tempPoint = NULL;

  //plain triangles for upper half circle
  for ( theta=(3*PI/2.0); theta >PI ; theta-=(DEG/100) ) { //from 8th to 7th octant of circle

    //applicant triangle's top-left point.
    newTri.r = (mainContainer.circle.radius +tolerance +(mainContainer.circle.radius * sin(theta)));
    newTri.c = (mainContainer.circle.radius +tolerance +(mainContainer.circle.radius * cos(theta))) +
          smallShape.triangle.edge/2; //temporary solution, fix it another way later.

    if( currPoint== NULL ||
        (abs((currPoint->r) - (newTri.r)) >= height ) &&
        is_tri_in_circle(mainContainer, smallShape, newTri) ){

      tempPoint = (Point *) malloc (sizeof(Point));
      tempPoint ->r = newTri.r;
      tempPoint ->c = newTri.c;
      tempPoint ->next = currPoint;
      currPoint = tempPoint;

      //applicant's top-left point.
      newTri.r = (currPoint ->r);
      newTri.c = (currPoint ->c)+(smallShape.triangle.edge);
      // then it is started to add triangles next to prev one as much as possible.
      while ( is_tri_in_circle(mainContainer, smallShape, newTri) ==true) {

        tempPoint = (Point *) malloc (sizeof(Point));
        tempPoint ->c = newTri.c;
        tempPoint ->r = newTri.r;
        tempPoint ->rotateDeg = newTri.rotateDeg;
        tempPoint ->next = currPoint;
        currPoint = tempPoint;
        ++count;

        //applicant triangle's top-left point.
        newTri.r = (currPoint ->r);
        newTri.c = (currPoint ->c + smallShape.triangle.edge );
      }
    }
  }



  for ( theta=PI; theta > (PI/2.0); theta-=(DEG/100)) { // from 8th to 7th octant of circle

    //applicant triangle's top-left point.
    if( currPoint == NULL)
      newTri.r = (mainContainer.circle.radius +(mainContainer.circle.radius * sin(theta)));
    else
      newTri.r = currPoint ->r + height;

    newTri.c = (mainContainer.circle.radius +(mainContainer.circle.radius * cos(theta))) +
        smallShape.triangle.edge; //temporary solution, fix it another way later.


    if(currPoint== NULL ||
           (abs((currPoint->r) ) > (sqrt(3.0)*smallShape.triangle.edge)) &&
       is_tri_in_circle(mainContainer, smallShape, newTri) == true ) {

      tempPoint = (Point *) malloc (sizeof(Point));
      tempPoint ->r = newTri.r;
      tempPoint ->c = newTri.c;
      tempPoint ->next = currPoint;
      currPoint = tempPoint;
      ++count;

      //applicant's top-left point.
      newTri.r = (currPoint ->r);
      newTri.c = (currPoint ->c + smallShape.triangle.edge);
      // then it is started to add triangles next to prev one as much as possible.
      while ( is_tri_in_circle(mainContainer, smallShape, newTri) ==true) {

        tempPoint = (Point *) malloc (sizeof(Point));
        tempPoint ->c = newTri.c;
        tempPoint ->r = newTri.r;
        tempPoint ->next = currPoint;

        currPoint = tempPoint;

        //applicant's top-left point.
        newTri.r = (currPoint ->r);
        newTri.c = (currPoint ->c + smallShape.triangle.edge);

      }
    }
  }
  smallShape.headShapePoint = currPoint;

  totalArea = (PI * mainContainer.circle.radius * mainContainer.circle.radius);
  coveredArea = count*(sqrt(3.0)*(smallShape.triangle.edge*smallShape.triangle.edge)/4.0);

  cout  << "\nResults...\n"
        << count<< " number triangle is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  draw_triangle_in_circle( mainContainer, smallShape);

  return;
}
