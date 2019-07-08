#ifndef _FILL_CONTAINER_H_
#define _FILL_CONTAINER_H_

/*
  void fill_small_shapes_to_container(...)
  ----------------------------------------
    Fills the small shapes to the maincontainer and save the center of
  the small shapes to a Point linked list.
*/
void fill_small_shapes_to_container( Shape & mainContainer, Shape & smallContainer);

/*
  void fill_circle (...)
  ----------------------
  if main container is a circle operation is continue with fill_circle.
*/
void fill_circle ( Shape & circle, Shape & smallShape );

/*
  void fill_rectangle (...)
  -------------------------
  if main container is a rectangle operation is continue with fill_rectangle.
*/
void fill_rectangle ( Shape & rectangle, Shape & smallShape );

/*
  void fill_triangle (...)
  ------------------------
  if main container is a triangle operation is continue with fill_triangle.
*/
void fill_triangle( Shape & triangle, Shape & smallShape );

#endif
