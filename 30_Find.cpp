template <class InputIterator, class T>
InputIterator find(InputIterator first,
                   InputIterator last,
                   const T& value) {
  while (first!=last && *first!=value)
    ++first;
  return first;
}

template <class InputIterator, class Predicate>
InputIterator find_if(InputIterator first,
                      InputIterator last,
                      Predicate pred) {
  while (first!=last && !pred(*first))
    ++first;
  return first;
}