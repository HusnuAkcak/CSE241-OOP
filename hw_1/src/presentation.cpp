#include <iostream>
#include <string>
#include "base.h"
#include "presentation.h"

using namespace std;

void
ask_to_user_for_shapes(Shape& mainContainer, Shape& smallShape) {

  string mainContainerMessage, smallShapeMessage;

  mainContainerMessage = "Please enter the main container shape";
  smallShapeMessage = "Please enter the small shape";
  get_shape(mainContainer, mainContainerMessage);
  get_shape(smallShape, smallShapeMessage);

  return;
}

void
get_shape(Shape& shape, string message) {

  char selection;

  cout  << endl
        << message << endl
        << "Circle    : C\n"
        << "Rectangle : R\n"
        << "Triangle  : T\n"
        << endl;

  // User's choice is being received.
  selection='\0';
  do {
    if(selection != '\0') { //if user makes an invalid choice.
      cout  << message << endl
            << "Circle    : C\n"
            << "Rectangle : R\n"
            << "Triangle  : T\n"
            << endl;

      cin >> selection;
    }
    else {
      cin >> selection;
    }
  } // loop goes on until user make a valid selection.
  while(
      selection!='c' && selection != 'C' &&
      selection!='r' && selection != 'R' &&
      selection!='t' && selection != 'T'
  );


  // According to user's selection, different operations are performed.
  switch ( selection ) {
    case 'c':
    case 'C':
      shape.name = Shape_name :: circle;
      get_circle_info(shape);
      break;

    case 'r':
    case 'R':
      shape.name = Shape_name :: rectangle;
      get_rectangle_info(shape);
      break;

    case 't':
    case 'T':
      shape.name = Shape_name :: triangle;
      get_triangle_info(shape);
      break;
    default :
      cout << "There is a problem in \"get_shape\" function.\n";
  }

  return;
}

void
get_circle_info (Shape & shape) {

  cout << "Please enter the radius: ";
  cin >> shape.circle.radius;
  return;
}

void
get_rectangle_info (Shape & shape) {

  cout << "Please enter the width: ";
  cin >> shape.rectangle.width;
  cout << "Please enter the height: ";
  cin >> shape.rectangle.height;
  return;
}

void
get_triangle_info (Shape& shape) {

  cout << "Please enter the edge of the equilateral triangle: ";
  cin >> shape.triangle.edge;
  return;
}
