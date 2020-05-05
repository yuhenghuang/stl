#include <ext\rb_tree>
using namespace std;

template<class Arg, class Result>
struct unary_function {
  typedef Arg argument_type;
  typedef Result result_type;
};

template <class Pair>
struct select1st: public unary_function<Pair, typename Pair::first_type> {
  const typename Pair::first_type& operator() (const Pair& x) const { return x.first; }
};
// input is select1st<value_type>

template <class Key, class T, class Compare, class Alloc>
class map {
  public:
    typedef Key key_type;
    typedef T data_type;
    typedef T mapped_type;
    typedef pair<const Key, T> value_type;
    typedef Compare key_compare;
    // constructing inner class for select1st is doable.
    struct select1st: public unary_function<value_type, key_type> {
      const key_type& operator() (const value_type& _X) const { return _X.first; }
    };
    // input is select1st
  private:
    typedef _Rb_tree<key_type, value_type, select1st, key_compare, Alloc> rep_type;
    rep_type t;
  public:
    typedef typename rep_type::iterator iterator;
};