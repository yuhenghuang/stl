#include <iostream>

template <class T, class charT=char, class traits=std::char_traits<charT>, class Distance=std::ptrdiff_t>
class istream_iterator: public std::iterator<std::input_iterator_tag, T, Distance, const T*, const T&> {
    std::basic_istream<charT, traits>* in_stream;
    T value;
  public:
    typedef charT char_type;
    typedef traits traits_type;
    typedef std::basic_istream<charT, traits> istream_type;
    istream_iterator(): in_stream(0) {}
    istream_iterator(istream_type& s): in_stream(&s) { ++*this; }
    istream_iterator(const istream_iterator<T, charT, traits, Distance>& x)
    : in_stream(x.in_stream), value(x.value) {};
    ~istream_iterator() {};
    const T& operator * () const { return value; }
    const T* operator -> () const { return &value; }
    istream_iterator<T, charT, traits, Distance>& operator ++ () {
      if (in_stream && !(*in_stream >> value)) in_stream=0;
      return *this;
    }
    istream_iterator<T, charT, traits, Distance>& operator ++ (int) {
      istream_iterator<T, charT, traits, Distance> tmp = *this;
      ++*this;
      return *tmp;
    }
};

#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

void test1() {
  double value1, value2;
  cout << "Please input two values: ";
  std::istream_iterator<double> eos;
  std::istream_iterator<double> iit (cin);
  if (iit!=eos) value1 = *iit;
  ++iit;
  if (iit!=eos) value2 = *iit;

  cout << value1 << " * " << value2 << " = " << value1*value2 << endl;
}

void test2() {
  std::istream_iterator<int> iit(cin), eos; // start reading when defined
  vector<int> c;
  copy(iit, eos, inserter(c, c.begin()));

  copy(c.begin(), c.end(), ostream_iterator<int>(cout, ", "));
}

int main() {
  // test1();
  test2();
  return 0;
}