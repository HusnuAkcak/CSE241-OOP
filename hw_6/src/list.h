#ifndef _LIST_H_
#define _LIST_H_

#include <vector>

#include "collection.h"

using std::vector;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class List:virtual public Collection<E, C>{ };

}

#endif
