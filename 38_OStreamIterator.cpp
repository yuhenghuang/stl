#include <iostream>

template <class T, class charT=char, class traits = std::char_traits<T>>
class ostream_iterator: public std::iterator<std::output_iterator_tag, void, void, void, void> {
  std::basic_ostream<charT, traits>* out_stream;
  const charT* delim;
  public:
    typedef charT char_type;
    typedef traits traits_type;
    typedef std::basic_ostream<charT, traits> ostream_type;
    ostream_iterator(ostream_type& s): out_stream(&s), delim(0) {}
    ostream_iterator(ostream_type& s, const charT* delimiter)
    : out_stream(&s), delim(delimiter) {}
    ostream_iterator(const ostream_iterator<T, charT, traits>& x) // copy constructor
    : out_stream(x.out_stream), delim(x.delim) { } // no need to reference because they are all pointers
    ~ostream_iterator() {}
    ostream_iterator<T, charT, traits>& 
    operator = (const T& value) {
      *out_stream << value;
      if (delim!=0) *out_stream << delim;
      return *this;
    }

    ostream_iterator<T, charT, traits>& operator * () { return *this; }
    ostream_iterator<T, charT, traits>& operator ++ () { return *this; }
    ostream_iterator<T, charT, traits>& operator ++ (int) { return *this; }
};

template<class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first,
                    InputIterator last,
                    OutputIterator result) {
  while (first!=last) {
    *result = *first; // key modification of operator =
    ++result; // auxiliary modification of operator ++
    ++first;
  }
  return result;
}

#include <iterator>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> vec;
  for (int i=1; i<10; ++i)
    vec.push_back(i*10);
  std::ostream_iterator<int> out_iter(std::cout, ", ");
  std::copy(vec.begin(), vec.end(), out_iter);
  return 0;
}