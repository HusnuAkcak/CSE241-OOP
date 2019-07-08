#include <iostream>
#include <cmath>
#include "base.h"
#include "export.h"
#include "calc.h"
#include "triangle.h"

using namespace std;

void
fill_triangle_with_circle( Shape & mainContainer, Shape & smallShape ) {

  Point *tempPoint, *currPoint;
  Point circlePos;
  double radius, height, totalArea, coveredArea;
  int count, i;  // counter


  cout << "It is being calculated.\n";
  mainContainer.headShapePoint  = (Point *) malloc(sizeof(Point));
  mainContainer.headShapePoint -> c= (mainContainer.triangle.edge/2);
  mainContainer.headShapePoint -> r= 0;

  tempPoint = NULL;
  currPoint = NULL;
  count =0;
  i=0;
  radius = smallShape.circle.radius;
  height = double(mainContainer.triangle.edge)/2.0*(sqrt(3.0));

  for ( circlePos.r =  height-radius;
        circlePos.r >= (radius*2.0);
        circlePos.r -= radius/sqrt(3.0)   ){
    for ( circlePos.c= (2.0*radius) +(2.0*i*sqrt(3.0));
          circlePos.c <(mainContainer.triangle.edge - (sqrt(3)*radius) - (2*i*sqrt(3.0)));
          circlePos.c+=radius/(sqrt(3.0))){

      if(is_circle_intersect_to_the_others(smallShape, circlePos, currPoint)==false){

        tempPoint=(Point*)malloc(sizeof(Point));
        tempPoint ->r =circlePos.r;
        tempPoint ->c =circlePos.c;
        tempPoint ->next= currPoint;
        currPoint = tempPoint;
        ++count;
      }
    }
    ++i;
  }
  smallShape.headShapePoint=currPoint;


  totalArea = (mainContainer.triangle.edge*mainContainer.triangle.edge)*sqrt(3)/4.0;
  coveredArea = count *( PI * radius* radius);

  cout  << "\nResults...\n"
        << count<< " number circle is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  draw_circle_in_triangle( mainContainer, smallShape);
  return;
}

void
fill_triangle_with_rectangle( Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint;
  double tHeight;
  double tempBase,r,c,i;
  double totalArea, coveredArea;
  int count;

  cout << "It is being calculated.\n";
  mainContainer.headShapePoint  = (Point *) malloc(sizeof(Point));
  mainContainer.headShapePoint -> c= (mainContainer.triangle.edge/2);
  mainContainer.headShapePoint -> r= 0;

  tHeight  = double(mainContainer.triangle.edge /2.0)*sqrt(3);

  currPoint=NULL;
  tempPoint= NULL;
  i=1;
  count=0;
  for(r=tHeight - smallShape.rectangle.height;
      r >= (smallShape.rectangle.width/2.0)*sqrt(3.0);
      r-=smallShape.rectangle.height    ){

    for ( c = i*(smallShape.rectangle.height/sqrt(3.0));
          c <= (mainContainer.triangle.edge)-(i/sqrt(3.0)*smallShape.rectangle.height)-smallShape.rectangle.width;
          c += (smallShape.rectangle.width)
    ) {
      tempPoint = (Point*) malloc( sizeof(Point));
      (tempPoint -> r)  = r;
      (tempPoint -> c)  = c;
      (tempPoint ->next)= currPoint;
      currPoint = tempPoint;
      ++count;
    }
    ++i;
  }
  smallShape.headShapePoint=currPoint;

  totalArea = (mainContainer.triangle.edge*mainContainer.triangle.edge)*sqrt(3)/4.0;
  coveredArea = count*(smallShape.rectangle.width*smallShape.rectangle.height);
  cout  << "\nResults...\n"
        << count<< " number rectangle is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  draw_rectangle_in_triangle(mainContainer, smallShape);

  return;
}

void
fill_triangle_with_triangle( Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint;
  double mainHeight, smallHeight;
  double tempBase,r,c,i;
  double totalArea, coveredArea;
  int count;

  cout << "It is being calculated.\n";
  mainContainer.headShapePoint  = (Point *) malloc(sizeof(Point));
  mainContainer.headShapePoint -> c= (mainContainer.triangle.edge/2);
  mainContainer.headShapePoint -> r= 0;

  mainHeight  = double(mainContainer.triangle.edge /2.0)*sqrt(3);
  smallHeight = double(smallShape.triangle.edge / 2.0)*sqrt(3);

  currPoint=NULL;
  tempPoint= NULL;
  i=1;
  count=0;
  for(r=mainHeight-smallHeight; r >= -smallHeight; r-=smallHeight ){
    //  plain small triangles are being determined.
    for ( c = i*((smallShape.triangle.edge)/2.0);
          c <= (mainContainer.triangle.edge - ((i/2.0)*smallShape.triangle.edge));
          c += (smallShape.triangle.edge)
    ) {
      tempPoint = (Point*) malloc( sizeof(Point));
      (tempPoint -> r)  = r;
      (tempPoint -> c)  = c;
      (tempPoint ->next)= currPoint;
      currPoint = tempPoint;
      ++count;
    }

    // reverse small triangles are being determined.
    for ( c = (i+1)*smallShape.triangle.edge/2.0;
          c < (mainContainer.triangle.edge - (i*smallShape.triangle.edge)/2.0);
          c += (smallShape.triangle.edge)
    ) {
      tempPoint = (Point*) malloc( sizeof(Point));
      (tempPoint -> r)  = r+smallHeight;
      (tempPoint -> c)  = c;
      (tempPoint -> rotateDeg) = 180;
      (tempPoint ->next)= currPoint;
      currPoint = tempPoint;
      ++count;
    }
    ++i;
  }
  smallShape.headShapePoint=currPoint;

  totalArea = (mainContainer.triangle.edge*mainContainer.triangle.edge)*sqrt(3)/4.0;
  coveredArea = count*((smallShape.triangle.edge*smallShape.triangle.edge)*sqrt(3)/4.0);
  cout  << "\nResults...\n"
        << count<< " number triangle is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  draw_triangle_in_triangle(mainContainer, smallShape);

  return;
}
