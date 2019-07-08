#include <iostream>
#include <cmath>
#include "base.h"
#include "export.h"
#include "calc.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "fill_container.h"

using namespace std;

void
fill_small_shapes_to_container( Shape & mainContainer, Shape & smallShape) {

  switch (mainContainer.name) {
    case Shape_name :: circle :
        fill_circle ( mainContainer, smallShape );
      break;

    case Shape_name :: rectangle :
        fill_rectangle ( mainContainer, smallShape );
      break;

    case Shape_name :: triangle :
        fill_triangle ( mainContainer, smallShape );
      break;
  }

  return;
}

void
fill_circle ( Shape & mainContainer, Shape & smallShape ) {

  switch( smallShape.name ) {
    case Shape_name :: circle :
      fill_circle_with_circle(mainContainer, smallShape );
      break;

    case Shape_name :: rectangle :
      fill_circle_with_rectangle(mainContainer, smallShape );
      break;

    case Shape_name :: triangle :
      fill_circle_with_triangle(mainContainer, smallShape );
      break;

    default:
      cout << "There is a problem with fill_circle function.\n";

  }

  return;
}

void
fill_rectangle ( Shape & mainContainer, Shape & smallShape ) {

  switch( smallShape.name ) {
    case Shape_name :: circle :
      fill_rectangle_with_circle(mainContainer, smallShape );
      break;
    case Shape_name :: rectangle :
      fill_rectangle_with_rectangle(mainContainer, smallShape );
      break;
    case Shape_name :: triangle :
      fill_rectangle_with_triangle(mainContainer, smallShape );
      break;
    default:
      cout << "There is a problem with fill_rectangle function.\n";

  }

  return;
}

void
fill_triangle(  Shape & mainContainer, Shape & smallShape ) {

  switch( smallShape.name ) {
    case Shape_name :: circle :
      fill_triangle_with_circle(mainContainer, smallShape );
      break;
    case Shape_name :: rectangle :
      fill_triangle_with_rectangle(mainContainer, smallShape );
      break;
    case Shape_name :: triangle :
      fill_triangle_with_triangle(mainContainer, smallShape );
      break;
    default:
      cout << "There is a problem with fill_triangle function.\n";

  }

  return;
}
