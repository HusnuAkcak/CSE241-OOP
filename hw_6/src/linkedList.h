#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdexcept>
#include <vector>

#include "list.h"
#include "queue.h"

using std::out_of_range;
using std::vector;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class LinkedList: public List<E, C>,public Queue<E, C> {
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
    //the following three function is blong to queue(is not override)
    virtual E element()noexcept override;
    //retrives but does not remove, the head of this queue.
    virtual void offer(E e)noexcept override;
    // insert the element at the end of the queue.
    virtual E poll()throw(out_of_range) override;
  private:
    C container;
  };
}

#endif
