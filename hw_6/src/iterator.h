#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <iostream>
#include <stdexcept>
#include <vector>

using std::vector;
using std::domain_error;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class Iterator {
  public:
    Iterator(C& c);
    Iterator();
    bool hasNext()noexcept;
    //returns if the collection has more elements.
    typename C::iterator& next()noexcept;
    //returns the next element and advanced the iterator.
    typename C::iterator& remove()noexcept;
    //remove last element returned by this iterator.
    const E& operator *()throw(domain_error);
  private:
    typename C::iterator itr;
    C* container;
  };
}
#endif
