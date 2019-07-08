#ifndef _LINKED_LIST_CPP_
#define _LINKED_LIST_CPP_

#include <iostream>
#include <vector>
#include <list>
#include <set>

#include "linkedList.h"
#include "iterator.cpp"

using std::cout;
using std::cerr;
using std::endl;

namespace HusnuAkcak {
  template<class E, class C>
  Iterator<E, C> //return type
  LinkedList<E, C>::iterator()noexcept {
    Iterator<E,C> itr(container);
    return itr;
  }

  template<class E, class C>
  void
  LinkedList<E, C>::add(E e)noexcept {
    container.insert(container.end(),e);
  }

  template<class E, class C>
  void
  LinkedList<E, C>::addAll(C &c)noexcept {
    Iterator<E,C> itr = Iterator<E,C>(c);
    while(itr.hasNext()){
      add(*itr);
      itr.next();
    }
  }

  template<class E, class C>
  void
  LinkedList<E, C>::clear()noexcept {
    container.clear();
    return;
  }

  template<class E, class C>
  bool
  LinkedList<E, C>::contains(E elm)noexcept {

    Iterator<E,C> itr = Iterator<E,C>(container);
    while(itr.hasNext() ){
      if(*itr==elm)
        return true;
      itr.next();
    }
    return false;
  }

  template<class E, class C>
  bool
  LinkedList<E, C>::containsAll(C &c)noexcept {
    Iterator<E,C> itr = Iterator<E,C>(container);
    while(itr.hasNext() ){
      Iterator<E,C> itrNew = Iterator<E,C>(c);
      if(!contains(*itrNew))
        return false;
      itr.next();
    }
    return true;
  }

  template<class E, class C>
  bool
  LinkedList<E, C>::isEmpty()noexcept {
    return container.empty();
  }

  template<class E, class C>
  void
  LinkedList<E, C>::remove(E e)noexcept {
    Iterator<E,C> itr = iterator();
    while(itr.hasNext()){
      // cout <<"IN LINKED LIST iterator :::::"<< *itr <<endl;
      // cout <<"IN LINKED LIST element  :::::"<< e <<endl;
      if(*itr == e)
        itr.remove();
      else
        itr.next();
    }
    return;
  }

  template<class E, class C>
  void
  LinkedList<E, C>::removeAll(C &c2)noexcept {

    Iterator<E,C> itr2 = Iterator<E,C>(c2);
    while(itr2.hasNext()){
      Iterator<E,C> itr = iterator();
      while(itr.hasNext()){
        if(*itr2==*itr)
          itr.remove(); //removes and iterate to next
        else
          itr.next();
      }
      itr2.next();
    }
    return;
  }

  template<class E, class C>
  void
  LinkedList<E, C>::retainAll(C &c2)noexcept {

    LinkedList temp;
    temp.addAll(c2);

    auto itr2=temp.iterator();
    while(itr2.hasNext()) {
      auto itr=iterator();
      while(itr.hasNext()){
        if(!temp.contains(*itr))
          itr.remove();
        else
          itr.next();
      }
      itr2.next();
    }
    return;
  }

  template<class E, class C>
  int
  LinkedList<E, C>::size()noexcept {
    return container.size();
  }

  template<class E, class C>
  E
  LinkedList<E, C>::element()noexcept {
    return *(container.begin());
  }

  template<class E, class C>
  void
  LinkedList<E, C>::offer(E e)noexcept {
    container.insert(container.end(),e);
    return;
  }

  template<class E, class C>
  E
  LinkedList<E, C>::poll()throw(out_of_range) {
    if(container.size()!=0){
      E temp=*(container.begin());
      container.erase(container.begin());
      return temp;
    }
    else
      throw out_of_range("The linkedList is empty!\n");
  }
}

#endif
