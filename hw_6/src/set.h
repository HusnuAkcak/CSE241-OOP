#ifndef _SET_H_
#define _SET_H_

#include <vector>

#include "collection.h"
#include "iterator.h"

using std::vector;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class Set:public Collection<E, C> { };
}

#endif
