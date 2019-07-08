#include <iostream>
#include <cmath>
#include "base.h"
#include "export.h"
#include "calc.h"
#include "rectangle.h"

using namespace std;

void
fill_rectangle_with_circle( const Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint; //  for center of circles
  double totalArea, coveredArea;
  int count,
      r, c,                   //  loop variables
      horizReqSmallCircleNum, //  horizontal req small circle
      vertReqSmallCircleNum,  //  vertical req small circle
      diameter;               //  dimaeter of the small circle


  diameter = smallShape.circle.radius*2;
  count=0;
  //  small circle numbers are calculated in horizontal and vertical.
  if (  ( mainContainer.rectangle.width < diameter ) ||
        ( mainContainer.rectangle.height < diameter)  ) {

    cout << "Unfortunately, any circle could not be fit to the main container.\n";
    return;
  }
  else  {
      horizReqSmallCircleNum  = mainContainer.rectangle.width  / (diameter);
      vertReqSmallCircleNum = mainContainer.rectangle.height  / (diameter);
  }

  tempPoint = NULL;
  currPoint = NULL;
  //  center of circles are determined.
  for (r=0;  r < vertReqSmallCircleNum; ++r) {
    for (c = 0; c < horizReqSmallCircleNum; ++c) {

      tempPoint = (Point*)malloc(sizeof(Point));
      tempPoint -> next = currPoint;

      tempPoint -> r = smallShape.circle.radius + (r * diameter);
      tempPoint -> c = smallShape.circle.radius + (c * diameter);

      currPoint = tempPoint;

      ++count;
    }
  }

  smallShape.headShapePoint = currPoint;

  totalArea = (mainContainer.rectangle.width * mainContainer.rectangle.height);
  coveredArea = (count*PI*smallShape.circle.radius*smallShape.circle.radius);

  cout  << "\nResults...\n"
        << count<< " number circle is fitted to main container.\n"
        << "Main container area : " << totalArea << endl
        << "Covered area : "        << coveredArea << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  draw_circle_in_rect (mainContainer, smallShape );

  return;
}

void
fill_rectangle_with_rectangle( const Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint;
  Shape vertSmallShape;   //  height and width of small shape are swapped
  double totalArea, coveredArea;
  int count,              //  counter
      r, c;               //  loop variables


  if( (smallShape.rectangle.width*smallShape.rectangle.height) >
  (mainContainer.rectangle.width*mainContainer.rectangle.height)
  ){
    cout<< "Unfortunately, any small rectangle can not be fit to the main Container.\n";
    return;
  }

  vertSmallShape.rectangle.width = smallShape.rectangle.height;
  vertSmallShape.rectangle.height = smallShape.rectangle.width;

  count=0;
  // It is wanted to keep as less as possible unused area at the top of stack.
  if (  (mainContainer.rectangle.height % smallShape.rectangle.height) >=
        (mainContainer.rectangle.height % smallShape.rectangle.width)     ) {

    // if normal form of smallShape is more efficient.
    currPoint=NULL;
    tempPoint=NULL;
    for ( r=0;
          r<= (mainContainer.rectangle.height - smallShape.rectangle.height);
          r+= smallShape.rectangle.height ) {
      for ( c=0;
            c<= (mainContainer.rectangle.width - smallShape.rectangle.width);
            c+= smallShape.rectangle.width ) {

        tempPoint = (Point*) malloc(sizeof(Point));
        tempPoint -> r = r;
        tempPoint -> c = c;
        tempPoint -> next = currPoint;
        currPoint = tempPoint;
        ++count;
        // cout<< count << "( "<< c <<", "<<r<<" )"<<" incremented\n";
      }
    }
    smallShape.headShapePoint = currPoint;

    currPoint = NULL;
    tempPoint = NULL;
    //if we still have some area to fit rotated rectangle.
    if( ( ((smallShape.headShapePoint->c) + vertSmallShape.rectangle.width) <=
          (mainContainer.rectangle.width)
        ) && (mainContainer.rectangle.height >= (vertSmallShape.rectangle.height))
      ) {
        for ( r = 0;
              r <= (mainContainer.rectangle.height - vertSmallShape.rectangle.height);
              r += vertSmallShape.rectangle.height) {
          for ( c = (smallShape.headShapePoint->c) + smallShape.rectangle.width;
                c <= (mainContainer.rectangle.width - vertSmallShape.rectangle.width);
                c += vertSmallShape.rectangle.width
              ) {
            tempPoint = (Point*) malloc(sizeof(Point));
            tempPoint -> r = r;
            tempPoint -> c = c;
            tempPoint -> next = currPoint;
            currPoint = tempPoint;
            ++count;
            // cout<< count << "( "<< c <<", "<<r<<" )"<<" Vert incremented\n";
          }
        }
    }
    vertSmallShape.headShapePoint = currPoint;

    totalArea = (mainContainer.rectangle.width * mainContainer.rectangle.height);
    coveredArea =count*(smallShape.rectangle.width * smallShape.rectangle.height);

    cout  << "\nResults...\n"
          << count<< " number rectangle is fitted to main container.\n"
          << "Main container area : " << totalArea << endl
          << "Covered area : "        << coveredArea << endl
          << "Left empty space :" << totalArea - coveredArea << endl;

    draw_rect_in_rect (mainContainer, smallShape, vertSmallShape);
  }
  else {
    // if vertical version of small shape is more efficient "width" and
    // "height" are swapped then this function is recalled.
    smallShape = vertSmallShape;
    fill_rectangle_with_rectangle( mainContainer, smallShape );
  }

  free_points ( vertSmallShape.headShapePoint);
  return;
}

void
fill_rectangle_with_triangle( const Shape & mainContainer, Shape & smallShape ) {

  Point *currPoint, *tempPoint;
  double totalArea, coveredArea;
  int count,  //  counter
      h,      //  height of the triangle
      r,c;    //  loop variables

  count = 0;
  h = (double(smallShape.triangle.edge)/2.0) * (sqrt(3.0));
  currPoint = NULL;
  tempPoint = NULL;

  //  plain triangles
  for( r=0; r <= (mainContainer.rectangle.height - h); r+=h ) {
    for ( c = double(smallShape.triangle.edge) / 2.0 ;
          c <= (mainContainer.rectangle.width - (smallShape.triangle.edge/2));
          c += smallShape.triangle.edge ) {

        tempPoint = (Point*) malloc(sizeof(Point));
        tempPoint -> r = r;
        tempPoint -> c = c;
        tempPoint -> next = currPoint;
        currPoint = tempPoint;
        ++count;
    }
  }

  //  reverse triangles
  for( r=h; r <= (mainContainer.rectangle.height); r+=h ) {
    for ( c = smallShape.triangle.edge;
          c <= (mainContainer.rectangle.width - smallShape.triangle.edge);
          c += smallShape.triangle.edge ) {

        tempPoint = (Point*) malloc(sizeof(Point));
        tempPoint -> r = r;
        tempPoint -> c = c;
        tempPoint -> next = currPoint;
        tempPoint -> rotateDeg = 180;
        currPoint = tempPoint;
        ++count;

    }
  }
  smallShape.headShapePoint = currPoint;

  totalArea = (mainContainer.rectangle.width * mainContainer.rectangle.height);
  coveredArea =count* (double(smallShape.triangle.edge * smallShape.triangle.edge * sqrt(3)) / 4.0);

  cout  << "\nResults...\n"
        << count<< " number triangle is fitted to main container.\n"
        << "Main container area : " << totalArea    << endl
        << "Covered area : "        << coveredArea  << endl
        << "Left empty space :" << totalArea - coveredArea << endl;

  // drawing is performed.
  draw_triangle_in_rect (mainContainer, smallShape);

  return;
}
