#ifndef _PRESENTATION_
#define _PRESENTATION_

using namespace std;

/*  ask_to_user_for_shapes(...)
 *  ----------------------------
 *  Gets the information about shapes from the user.
 */
void ask_to_user_for_shapes(Shape& mainContainer, Shape& smallShape);

void get_shape(Shape& shape, string message);

void get_circle_info(Shape& circle);

void get_rectangle_info(Shape& rectangle);

void get_triangle_info(Shape& triangle);
#endif
