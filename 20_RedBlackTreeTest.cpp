#include <ext\rb_tree>
#include <iostream>
//using namespace std;

template<class Arg, class Result>
struct unary_function {
  typedef Arg argument_type;
  typedef Result result_type;
};

template <class T>
struct identity: public unary_function<T, T> {
  const T& operator () (const T& x) const { return x; }
};


template <class Arg1, class Arg2, class Result>
struct binary_function {
  typedef Arg1 first_argument_type;
  typedef Arg2 second_argument_type;
  typedef Result result_type;
};

template <class T>
struct less: public binary_function<T, T, bool> {
  bool operator() (const T& x, const T& y) const { return x < y; }
};


int main() {
  std::_Rb_tree<int, int, identity<int>, less<int>> itree;
  using namespace std;
  cout << itree.empty() << endl;
  cout << itree.size() << endl;

  itree._M_insert_unique(3);
  itree._M_insert_unique(8);
  itree._M_insert_unique(5);
  itree._M_insert_unique(9);
  itree._M_insert_unique(13);
  itree._M_insert_unique(5);

  cout << itree.empty() << endl;
  cout << itree.size() << endl;
  cout << itree.count(5) << endl;

  itree._M_insert_equal(5);
  itree._M_insert_equal(5);
  cout << itree.size() << endl;
  cout << itree.count(5) << endl;
  return 0;
}