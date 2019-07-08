#ifndef _EXPORT_H_
#define _EXPORT_H_

using namespace std;
/*
  void init_svg_file (...)
  ------------------------
  Takes mainContainer and initialize the svg file.
*/
void init_svg_file (const Shape & mainContainer, ofstream & file);

/*
  draw_* functions:
    Creates a svg file in results folder and exports the mainContainer and
  small shape to the svg file.
*/

void draw_circle_in_circle (const Shape & mainContainer, const Shape & smallShape);

void draw_rect_in_circle( const Shape & mainContainer, const Shape & smallShape);

void draw_triangle_in_circle (const Shape & mainContainer, const Shape & smallShape );

void draw_circle_in_rect (const Shape & mainContainer, const Shape & smallShape );

void draw_rect_in_rect (const Shape & mainContainer,
                const Shape & smallShape, const Shape & verticalSmallShape);

void draw_triangle_in_rect (const Shape & mainContainer, const Shape & smallShape);

void draw_triangle_in_triangle(const Shape & mainContainer, const Shape & smallShape);

void draw_circle_in_triangle(const Shape & mainContainer, const Shape & smallShape);

void draw_rectangle_in_triangle(const Shape & mainContainer, const Shape & smallShape);


#endif
