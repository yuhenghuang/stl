#include <iostream>

template <class ForwardIterator, class T>
ForwardIterator lower_bound(ForwardIterator first,
                            ForwardIterator last,
                            const T& val) {
  ForwardIterator it;
  typename std::iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first, last); // general function for all iterators
  while (count>0) {
    it = first; step=count/2; advance(it, step); // general function for all iterators
    if (*it<val) {
      first = ++it;
      count -= step+1;
    }
    else
      count = step;
  }
  return first;
}

template <class ForwardIterator, class T>
bool binary_search(ForwardIterator first,
                   ForwardIterator last,
                   const T& val) {
  first = lower_bound(first, last, val);
  return (first!=last && !(val < *first));
}