#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <vector>

#include "iterator.h"

using std::vector;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class Collection {
  public:
    virtual Iterator<E,C> iterator()noexcept=0;
    //ensures the conteiner contains specified element.
    virtual void add(E e)noexcept=0;
    //adds all element of collection to this collection.
    virtual void addAll(C &c)noexcept=0;
     //removes all element from the collection.
    virtual void clear()noexcept=0;
    //returns true if this collection contains the element.
    virtual bool contains(E e)noexcept=0;
    //returns true if this collection contains all the collection of the element.
    virtual bool containsAll(C &c)noexcept=0;
    virtual bool isEmpty()noexcept=0;
    virtual void remove(E e)noexcept=0;
    virtual void removeAll(C &c)noexcept=0;
    virtual void retainAll(C &c)noexcept=0;
    virtual int size()noexcept=0;
  };
}

#endif
