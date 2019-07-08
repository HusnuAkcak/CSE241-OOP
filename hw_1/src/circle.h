#ifndef _CIRCLE_H_
#define _CIRCLE_H_

/*
  void fill_circle_with_circle (...)
  ----------------------------------
  fill main container circle with small shape circles.
*/
void fill_circle_with_circle( const Shape & mainContainer, Shape & smallShape);

/*
  void fill_circle_with_rectangle (...)
  ----------------------------------
  fill main container circle with small shape rectangles.
*/
void fill_circle_with_rectangle( const Shape & mainContainer, Shape & smallShape);

/*
  void fill_circle_with_triangle (...)
  ----------------------------------
  fill main container circle with small shape triangles.
*/
void fill_circle_with_triangle( const Shape & mainContainer, Shape & smallShape);


#endif
