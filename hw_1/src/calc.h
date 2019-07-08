#ifndef _CALC_
#define _CALC_


/*
  bool is_circle_intesect_to_the_others(...)
  ------------------------------------------
  Controls, if the given the small shape circles are intersect or
    not at given point.
*/
bool is_circle_intersect_to_the_others(const Shape & smallShape,
                                      Point & smallCenter,Point *& currPoint);

/*
  is_rect_intersect_to_the_others(...)
  --------------------------------------
  Controls if the last small rectangle intersect the previous ones.
*/
bool is_rect_intersect_to_the_others(const Shape& smallShape,
                                      Point & newRect, Point *& currPoint);

/*
  bool is_rect_in_circle(...)
  ---------------------------------------
  Looks for if it is possible to add another recta next to prev one.
*/
bool is_rect_in_circle(const Shape & mainContainer,
                              const Shape & smallShape,  Point &rectStartPoint);

/*
  bool is_tri_in_circle(...)
  ---------------------------------------
  Looks for if it is possible to add another triangle next to prev one.
*/
bool is_tri_in_circle(const Shape & mainContainer,
                              const Shape & smallShape,  Point &triStartPoint);

/*
  void calc_triangle_bottom_nodes (...)
  -------------------------------------
  Calculates the two bottom node coord. of the equiliteral triangle.
*/
void calc_triangle_bottom_nodes (const Shape & shape, Point *& currPoint,
                                          Point & btmNode1, Point & btmNode2);



#endif
