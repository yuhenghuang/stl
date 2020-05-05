#include <iostream>
#include <type_traits>
#include <cstring>

// distance

template <class InputIterator>
inline ptrdiff_t  // iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last, std::input_iterator_tag) {
  ptrdiff_t n = 0; // iterator_traits<InputIterator>::difference_type
  while (first!=last) {
    ++first; ++n;
  }
  return n;
}

template <class RandomAccessIterator>
inline ptrdiff_t // iterator_traits<InputIterator>::difference_type
__distance(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag) {
  return last - first;
}

template <class InputIterator>
inline ptrdiff_t // iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last) {
  typedef typename std::iterator_traits<InputIterator>::iterator_category category;
  // why two variations of functions work out...
  // think about the inheritance of iterators
  // why pass object instead of typename
  return __distance(first, last, category())
}



// advance

template <class InputIterator, class Distance>
inline void __advance(InputIterator& i, Distance n, std::input_iterator_tag) {
  while (n--) ++i;
}

template <class BidirectionalIterator, class Distance>
inline void __advance(BidirectionalIterator& i, Distance n, std::bidirectional_iterator_tag) {
  if (n>=0)
    while (n--) ++i;
  else
    while (n++) --i;
}

template <class RandomAccessIterator, class Distance>
inline void __advance(RandomAccessIterator& i, Distance n, std::random_access_iterator_tag) {
  i += n;
}

template <class Iterator>
inline typename std::iterator_traits<Iterator>::iterator_category 
iterator_category(const Iterator&) {
  typedef typename std::iterator_traits<Iterator>::iterator_category category;
  return category();
}

template <class InputIterator, class Distance>
inline void advance(InputIterator& i, Distance n) {
  __advance(i, n, iterator_category(i));
}




template <class FI>
inline void __destroy_aux(FI, FI, std::true_type) { }

template <class FI>
inline void __destroy_aux(FI first, FI last, std::false_type) {
  for (; first < last; ++first)
    destory(&*first); // memo! how to destruct linearly
}

template <class FI>
inline void __destory(FI first, FI last) { }

template <class FI, class T>
inline void __destory(FI first, FI last, T*) {
  typedef typename std::is_trivially_destructible<T>::value trivial_destructor;
  __destroy_aux(first, last, trivial_destructor());
}

template <class Iterator>
inline typename std::iterator_traits<Iterator>::value_type*
value_type(const Iterator&) {
  return static_cast<typename std::iterator_traits<Iterator>::value_type*>(0);
}

inline void destory(char*, char*) { }

inline void destory(wchar_t*, wchar_t*) { }

template <class T>
inline void destroy(T* pointer) {
  pointer->~T();
}

template <class FI>
inline void destory(FI first, FI last) {
  __destroy(first, last, value_type(first));
}

template <class InputIterator, class OutputIterator, class T>
OutputIterator __unique_copy(InputIterator first,
                             InputIterator last,
                             OutputIterator result, T*) {
  // ostream_iterator is write-only
  T value = *first;
  *result = value;
  while (++first!=last) {
    if (value != *first) {
      value = *first;
      *++result = value;
    }
  }
  return ++result;
}

template <class InputIterator, class ForwardIterator>
ForwardIterator __unique_copy(InputIterator first,
                              InputIterator last,
                              ForwardIterator result,
                              std::forward_iterator_tag) {
  // other four iterators in this function
  *result = first;
  while (++first!=last) 
    if (*result!=*first)
      *++result = *first;
  return ++result;
}


template <class InputIterator, class OutputIterator>
inline OutputIterator __unique_copy(InputIterator first,
                                    InputIterator last,
                                    OutputIterator result,
                                    std::output_iterator_tag) {
  return __unique_copy(first, last, retult, value_type(first));
}