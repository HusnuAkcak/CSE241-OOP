#include <iostream>
#include "base.h"


void
free_points ( Point * headPoint ) {

  Point *currPoint, *tempPoint;

  currPoint = headPoint;
  while( currPoint != NULL ) {

    tempPoint = currPoint->next;

    free(currPoint);
    currPoint=NULL;

    currPoint = tempPoint;

  }

}
