#ifndef _HASH_SET_CPP_
#define _HASH_SET_CPP_

#include <iostream>
#include <vector>
#include <list>
#include <set>

#include "hashSet.h"
#include "iterator.cpp"

using std::cout;
using std::cerr;
using std::endl;

namespace HusnuAkcak {

  template<class E, class C>
  Iterator<E, C> //return type
  HashSet<E, C>::iterator()noexcept {
    Iterator<E,C> itr(container);
    return itr;
  }

  template<class E, class C>
  void
  HashSet<E, C>::add(E e)noexcept {
    if(contains(e)!=true)
      container.insert(container.end(),e);
  }

  template<class E, class C>
  void
  HashSet<E, C>::addAll(C &c)noexcept {
    Iterator<E,C> itr = Iterator<E,C>(c);
    while(itr.hasNext()){
      add(*itr);
      itr.next();
    }
  }

  template<class E, class C>
  void
  HashSet<E, C>::clear()noexcept {
    container.clear();
    return;
  }

  template<class E, class C>
  bool
  HashSet<E, C>::contains(E elm)noexcept {

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
  HashSet<E, C>::containsAll(C &c)noexcept {
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
  HashSet<E, C>::isEmpty()noexcept {
    return container.empty();
  }

  template<class E, class C>
  void
  HashSet<E, C>::remove(E e)noexcept {
    Iterator<E,C> itr = iterator();
    while(itr.hasNext()){
      if(*itr == e)
        itr.remove();
      else
        itr.next();
    }
    return;
  }

  template<class E, class C>
  void
  HashSet<E, C>::removeAll(C &c2)noexcept {
    Iterator<E,C> itr = iterator();
    while(itr.hasNext()){
      Iterator<E,C> itr2 = Iterator<E,C>(c2);
      while(itr2.hasNext()){
        if(*itr == *itr2)
          itr.remove();
        else
          itr2.next();
      }
      itr.next();
    }
    return;
  }

  template<class E, class C>
  void
  HashSet<E, C>::retainAll(C &c2)noexcept {
    HashSet temp;
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
  HashSet<E, C>::size()noexcept {
    return container.size();
  }
}//end of HusnuAkcak namespace

#endif
