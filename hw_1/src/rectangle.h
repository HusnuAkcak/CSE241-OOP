#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

/*
  void fill_rectangle_with_circle (...)
  ----------------------------------
  fill main container rectangle with small shape circles.
*/
void fill_rectangle_with_circle( const Shape & mainContainer, Shape & smallShape);

/*
  void fill_rectangle_with_rectangle (...)
  ----------------------------------
  fill main container rectangle with small shape rectangles.
*/
void fill_rectangle_with_rectangle( const Shape & mainContainer, Shape & smallShape);

/*
  void fill_rectangle_with_triangle (...)
  ----------------------------------
  fill main container rectangle with small shape triangles.
*/
void fill_rectangle_with_triangle( const Shape & mainContainer, Shape & smallShape);


#endif
