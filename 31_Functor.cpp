// #include <iostream>
// using namespace std;

template <class Arg1, class Arg2, class Result>
struct binary_function {
  typedef Arg1 first_argument_type;
  typedef Arg2 second_argument_type;
  typedef Result result_type;
};

// arithmetic
template <class T>
struct add: public binary_function<T, T, T> {
  T operator() (const T& x, const T& y) const { return x+y; }
};

template <class T>
struct subtract: public binary_function<T, T, T> {
  T operator() (const T& x, const &T y) const { return x-y; }
};

// logical
template <class T>
struct logical_and: public binary_function<T, T, bool> {
  bool operator() (const T& x, const T& y) const { return x && y; }
};

// relational
template <class T>
struct equal_to: public binary_function<T, T, bool> {
  bool operator() (const T& x, const &T y) { return x==y; }
};

template <class T>
struct less: public binary_function<T, T, bool> {
  bool operator() (const T& x, const &T y) { return x<y; }
};

template <class T>
struct greater: public binary_function<T, T, bool> {
  bool operator() (const T& x, const T& y) { return x>y; }
};


template <class Arg, class Result>
struct unary_function {
  typedef Arg argument_type;
  typedef Result result_type;
};

template <class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;
  pair(): first(T1(), T2());
  pair(const T1& a, const T2& b): first(a), second(b) { }
};

template <class T>
struct identity: public unary_function<T, T> {
  const T& operator() (const T& x) const { return x; }
};

template <class Pair>
struct select1st: public unary_function<Pair, typename Pair::first_type> {
  const typename Pair::first_type& operator() (const Pair& x) const {
    return x.first;
  }
};

template <class Pair>
struct select1st: public unary_function<Pair, typename Pair::second_type> {
  const typename Pair::second_type& operator() (const Pair& x) const {
    return x.second;
  }
};