#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#include <vector>

#include "list.h"

using std::vector;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class ArrayList:public List<E, C> {
  public:
    virtual Iterator<E,C> iterator()noexcept;
    //ensures the conteiner contains specified element.
    virtual void add(E e)noexcept;
    //adds all element of collection to this collection.
    virtual void addAll(C &c)noexcept;
     //removes all element from the collection.
    virtual void clear()noexcept;
    //returns true if this collection contains the element.
    virtual bool contains(E e)noexcept;
    //returns true if this collection contains all the collection of the element.
    virtual bool containsAll(C &c)noexcept;
    virtual bool isEmpty()noexcept;
    virtual void remove(E e)noexcept;
    virtual void removeAll(C &c)noexcept;
    virtual void retainAll(C &c)noexcept;
    virtual int size()noexcept;
  private:
    C container;
  };
}

#endif
