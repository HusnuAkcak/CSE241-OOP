#include <iostream>
#include <fstream>
#include <cstdlib>
#include "src/base.h"
#include "src/shape.h"
#include "src/composedShape.h"

using namespace std;

int main () {

  ComposedShape cmp;

  cmp.input();
  cmp.optimalFit();

  return 0;
}
