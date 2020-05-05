#include <iostream>

template <class InputIterator, class T>
typename std::iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const T& value) {
  typename std::iterator_traits<InputIterator>::difference_type n = 0;
  for (; first!=last; ++first)
    if (*first==value)
      ++n;
  return n;
}

template <class InputIterator, class Predicate>
typename std::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, Predicate pred) {
  typename std::iterator_traits<InputIterator>::difference_type n = 0;
  for (; first!=last; ++first)
    if (pred(*first))
      ++n;
  return n;
}