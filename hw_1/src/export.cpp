#include <fstream>
#include <iostream>
#include "base.h"
#include "export.h"
#include "calc.h"

using namespace std;

void
init_svg_file (const Shape & mainContainer, ofstream & file ) {

  Point *tHeadNode, tBtmNode1, tBtmNode2;  //  triangle nodes

  switch ( mainContainer.name ) {

    //svg file is initialized.
    case Shape_name :: circle :

      file  << "<svg version=\"1.1\" baseProfile=\"full\" "
            << " width= \"" << ( mainContainer.circle.radius * 2 ) << "\""
            << " height= \"" << ( mainContainer.circle.radius * 2 )  << "\""
            << " xmlns=\"http://www.w3.org/2000/svg\"> "
            << endl << endl;

      // main container is painted.
      file  << "  <circle "
            << " cx= \""   << ( mainContainer.circle.radius ) << "\""
            << " cy= \""   << ( mainContainer.circle.radius ) << "\""
            << " r= \""    << mainContainer.circle.radius  << "\""
            << " stroke = \"black\" stroke-width=\"1\" "
            << " fill=\"orange\" /> \n";

      break;

    case Shape_name :: rectangle :

      file  << "<svg version=\"1.1\" baseProfile=\"full\" "
            << " width= \"" << mainContainer.rectangle.width *2<< "\""
            << " height= \"" << mainContainer.rectangle.height *2 << "\""
            << " xmlns=\"http://www.w3.org/2000/svg\"> "
            << endl << endl;

      // main container is painted.
      file  << "  <rect "
            << " x = \"" << 0 << "\""
            << " y = \"" << 0 << "\""
            << " width= \"" << mainContainer.rectangle.width << "\""
            << " height= \"" << mainContainer.rectangle.height  << "\""
            << " stroke = \"black\" stroke-width=\"1\" "
            << " fill=\"orange\" /> \n";

      break;

    case Shape_name :: triangle :

      file  << "<svg version=\"1.1\" baseProfile=\"full\" "
            << " width= \"" << mainContainer.triangle.edge << "\""
            << " height= \"" << mainContainer.triangle.edge  << "\""
            << " xmlns=\"http://www.w3.org/2000/svg\"> "
            << endl << endl;

      tHeadNode = mainContainer.headShapePoint;
      calc_triangle_bottom_nodes(mainContainer, tHeadNode, tBtmNode1, tBtmNode2);

      file  << "  <polygon "
            << " points= \"" << (tHeadNode->c)<< " " << (tHeadNode->r) << " "
            << tBtmNode1.c <<" "<< tBtmNode1.r <<" "<< tBtmNode2.c <<" "<< tBtmNode2.r << "\""
            << " transform = \"rotate("
            << tHeadNode->rotateDeg  << " "<< (tHeadNode->c) << " "<< (tHeadNode->r) << ")\""
            << " stroke = \"black\" stroke-width=\"1\" "
            << " fill=\"rgb(95, 156, 212)\" /> \n";


      break;
  }

  return;
}

void
draw_circle_in_circle (const Shape & mainContainer, const Shape & smallShape) {

  ofstream file;
  Point * currPoint;

  file.open("results/circle_in_circle.svg");

  init_svg_file (mainContainer, file);

  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    file  << "  <circle "
          << " cx= \""      << ( currPoint -> c )       << "\""
          << " cy= \""      << ( currPoint -> r )       << "\""
          << " r= \""      << smallShape.circle.radius  << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(187, 221, 167)\" /> \n";

  }

  file << "</svg>";
  file.close();

  return;
}

void
draw_rect_in_circle( const Shape & mainContainer, const Shape & smallShape) {

  ofstream file;
  Point * currPoint;

  file.open("results/rect_in_circle.svg");

  init_svg_file (mainContainer, file);

  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    file  << "  <rect "
          << " x= \""      << ( currPoint -> c )       << "\""
          << " y= \""      << ( currPoint -> r )       << "\""
          << " width= \""      << smallShape.rectangle.width  << "\""
          << " height= \""     << smallShape.rectangle.height  << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(137, 199, 182)\" /> \n";

  }

  file << "</svg>";

  file.close();
  return;
}

void
draw_triangle_in_circle (const Shape & mainContainer, const Shape & smallShape ) {

  ofstream file;
  Point * currPoint;
  Point btmNode1, btmNode2; // bottom node coordinates of triangle.

  file.open("results/triangle_in_circle.svg");

  init_svg_file (mainContainer, file);


  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    calc_triangle_bottom_nodes (smallShape, currPoint, btmNode1, btmNode2);

    file  << "  <polygon "
          << " points= \"" << (currPoint -> c)<< " " << (currPoint -> r) << " "
          << btmNode1.c <<" "<< btmNode1.r <<" "<< btmNode2.c <<" "<< btmNode2.r << "\""
          << " transform = \"rotate("
          << currPoint->rotateDeg  << " "<< (currPoint->c) << " "<< (currPoint->r) << ")\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(199, 180, 137)\" /> \n";

  }


  file << "</svg>";
  file.close();
  return;
}

void
draw_circle_in_rect (const Shape & mainContainer, const Shape & smallShape ) {

  ofstream file;
  Point * currPoint;

  file.open("results/circle_in_rect.svg");

  init_svg_file (mainContainer, file);

  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    file  << "  <circle "
          << " cx= \""      << ( currPoint -> c )       << "\""
          << " cy= \""      << ( currPoint -> r )       << "\""
          << " r= \""      << smallShape.circle.radius  << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(187, 221, 167)\" /> \n";

  }

  file << "</svg>";
  file.close();

}

void
draw_rect_in_rect (const Shape & mainContainer,
                const Shape & smallShape, const Shape & verticalSmallShape) {

  ofstream file;
  Point * currPoint, *vCurrPoint;

  file.open("results/rect_in_rect.svg");

  init_svg_file (mainContainer, file);

  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    file  << "  <rect "
          << " x= \""      << ( currPoint -> c )       << "\""
          << " y= \""      << ( currPoint -> r )       << "\""
          << " width= \""      << smallShape.rectangle.width  << "\""
          << " height= \""     << smallShape.rectangle.height  << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(197, 137, 219)\" /> \n";
  }

  for ( vCurrPoint = verticalSmallShape.headShapePoint;
        vCurrPoint != NULL;
        vCurrPoint = vCurrPoint->next) {

    file  << "  <rect "
          << " x= \""      << ( vCurrPoint -> c )       << "\""
          << " y= \""      << ( vCurrPoint -> r )       << "\""
          << " width= \""      << verticalSmallShape.rectangle.width  << "\""
          << " height= \""     << verticalSmallShape.rectangle.height  << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(137, 199, 182)\" /> \n";
  }

  file << "</svg>";

  file.close();

  return;
}

void
draw_triangle_in_rect (const Shape & mainContainer, const Shape & smallShape) {

  ofstream file;
  Point * currPoint;
  Point btmNode1, btmNode2; // bottom node coordinates of triangle.

  file.open("results/triangle_in_rect.svg");

  init_svg_file (mainContainer, file);


  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    calc_triangle_bottom_nodes (smallShape, currPoint, btmNode1, btmNode2);

    file  << "  <polygon "
          << " points= \"" << (currPoint -> c)<< " " << (currPoint -> r) << " "
          << btmNode1.c <<" "<< btmNode1.r <<" "<< btmNode2.c <<" "<< btmNode2.r << "\""
          << " transform = \"rotate("
          << currPoint->rotateDeg  << " "<< (currPoint->c) << " "<< (currPoint->r) << ")\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(199, 180, 137)\" /> \n";

  }


  file << "</svg>";
  file.close();

  return;
}

void
draw_triangle_in_triangle(const Shape & mainContainer, const Shape & smallShape) {


  ofstream file;
  Point * currPoint;
  Point btmLeftNode, btmRightNode; // bottom node coordinates of triangle.

  file.open("results/triangle_in_triangle.svg");

  init_svg_file (mainContainer, file);


  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    calc_triangle_bottom_nodes (smallShape, currPoint, btmLeftNode, btmRightNode);

    file  << "  <polygon "
          << " points= \"" << (currPoint -> c)<< " " << (currPoint -> r) << " "
          << btmLeftNode.c <<" "<< btmLeftNode.r <<" "<< btmRightNode.c <<" "<< btmRightNode.r << "\""
          << " transform = \"rotate("
          << currPoint->rotateDeg  << " "<< (currPoint->c) << " "<< (currPoint->r) << ")\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(137, 199, 182)\" /> \n";

  }

  file << "</svg>";
  file.close();
  return;
}

void
draw_circle_in_triangle(const Shape & mainContainer, const Shape & smallShape) {

  ofstream file;
  Point * currPoint;

  file.open("results/circle_in_triangle.svg");

  init_svg_file (mainContainer, file);

  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    file  << "  <circle "
          << " cx= \""      << ( currPoint -> c )       << "\""
          << " cy= \""      << ( currPoint -> r )       << "\""
          << " r= \""      << smallShape.circle.radius  << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(187, 221, 167)\" /> \n";
  }

  file << "</svg>";
  file.close();
  return;
}

void
draw_rectangle_in_triangle(const Shape & mainContainer, const Shape & smallShape) {

  ofstream file;
  Point * currPoint;

  file.open("results/rect_in_triangle.svg");

  init_svg_file (mainContainer, file);

  for ( currPoint = smallShape.headShapePoint;
        currPoint != NULL;
        currPoint = currPoint->next) {

    file  << "  <rect "
          << " x= \""      << ( currPoint -> c )       << "\""
          << " y= \""      << ( currPoint -> r )       << "\""
          << " width= \""      << smallShape.rectangle.width  << "\""
          << " height= \""     << smallShape.rectangle.height  << "\""
          << " stroke = \"black\" stroke-width=\"1\" "
          << " fill=\"rgb(137, 199, 182)\" /> \n";

  }

  file << "</svg>";
  file.close();
  return;
}
