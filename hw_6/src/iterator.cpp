#ifndef _ITERATOR_CPP_
#define _ITERATOR_CPP_

#include <iostream>

#include "iterator.h"

using std::cout;
using std::cerr;
using std::endl;
using std::advance;
using std::domain_error;

namespace HusnuAkcak {

  template<class E, class C>
  Iterator<E, C>::Iterator(C& c) {
    container =&c;
    itr= c.begin();
  }

  template<class E, class C>
  Iterator<E, C>::Iterator() {
    cout<<"TO EXPECT TO WORK 'ITERATOR' CLASS PROPERLY, \n"
        "YOU MUST USE THE CONTRUCTOR THAT TAKES A COLLECTION REFERANCE.\n";
  }

  template<class E, class C>
  bool
  Iterator<E,C>::hasNext()noexcept {
    return (itr != container->end());
  }

  template<class E, class C>
  typename C::iterator&
  Iterator<E,C>::next()noexcept {
    if(hasNext())
      ++itr;
    return itr;
  }

  template<class E, class C>
  typename C::iterator&
  Iterator<E,C>::remove()noexcept {
    itr=container->erase(itr);
    return itr;
  }

  template<class E, class C>
  const E&
  Iterator<E,C>::operator *()throw(domain_error) {
    if(itr!= (container->end()) )
      return *itr;
    else
      throw domain_error("Iterator is out of range!\n");
  }
} //end of HusnuAkcak namespace
#endif
