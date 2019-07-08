#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <vector>

#include "collection.h"

using std::vector;
using std::out_of_range;

namespace HusnuAkcak {
  template <class E, class C= vector<E> >
  class Queue:virtual public Collection<E, C> {
  public:
    virtual E element()noexcept=0;
    //retrives but does not remove, the head of this queue.
    virtual void offer(E e)noexcept=0;
    // insert the element at the end of the queue.
    virtual E poll()throw(out_of_range)=0;
  private:
  };
}

#endif
