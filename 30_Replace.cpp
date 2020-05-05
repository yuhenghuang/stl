template <class ForwardIterator, class T>
void replace(ForwardIterator first, 
             ForwardIterator last, 
             const T& old_value, 
             const T& new_value) {
  for (; first!=last; ++first)
    if (*first==old_value)
      *first = new_value;
}

template <class InputIterator, class OutputIterator, class T>
OutputIterator replace_copy(InputIterator first,
                            InputIterator last,
                            OutputIterator result,
                            const T& old_value,
                            const T& new_value) {
  for (; first!=last; ++first, ++result)
    *result = *first==old_value ? new_value : *first;
  return result;
}

template <class ForwardIterator, class Predicate, class T>
void replace_if(ForwardIterator first,
                ForwardIterator last,
                Predicate pred,
                const T& new_value) {
  for (; first!=last; ++first)
    if (pred(*first))
      *first = new_value;
}