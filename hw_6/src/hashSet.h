#ifndef _HASH_SET_H_
#define _HASH_SET_H_

#include <vector>

#include "set.h"
#include "iterator.h"

using std::vector;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class HashSet:public Set<E,C> {
  public:
    virtual Iterator<E,C> iterator()noexcept override;
    //ensures the conteiner contains specified element.
    virtual void add(E e)noexcept override; 
    //adds all element of collection to this collection.
    virtual void addAll(C &c)noexcept override;
     //removes all element from the collection.
    virtual void clear()noexcept override;
    //returns true if this collection contains the element.
    virtual bool contains(E e)noexcept override;
    //returns true if this collection contains all the collection of the element.
    virtual bool containsAll(C &c)noexcept override;
    virtual bool isEmpty()noexcept override;
    virtual void remove(E e)noexcept override;
    virtual void removeAll(C &c)noexcept override;
    virtual void retainAll(C &c)noexcept override;
    virtual int size()noexcept override;
  private:
    C container;
  };
}

#endif
