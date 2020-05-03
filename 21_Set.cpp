#include <ext\rb_tree>

template <class Key, class Compare, class Alloc>
class set {
  public:
    typedef Key key_type;
    typedef Key value_type;
    typedef Compare key_compare;
    typedef Compare Value_compare;
  private:
    typedef std::_Rb_tree<key_type, value_type, std::_Identity<value_type>, key_compare, Alloc> rep_type;
    rep_type t;
  public:
    typedef typename rep_type::const_iterator iterator;
};

// std::_Rb_tree<int , int, std::_Identity<int>, std::less<int>>::const_iterator;