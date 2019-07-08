#include <iostream>
#include <fstream>
#include <cstdlib>
#include "src/base.h"
#include "src/calc.h"
#include "src/fill_container.h"
#include "src/presentation.h"


using namespace std;


int main () {

  Shape mainContainer, smallShape;

  ask_to_user_for_shapes(mainContainer, smallShape );

  fill_small_shapes_to_container(mainContainer, smallShape );

  free_points(smallShape.headShapePoint);
  free_points(mainContainer.headShapePoint);

  return 1;
}
