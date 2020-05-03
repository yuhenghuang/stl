#include <cstring>

template<class Value>
class __rb_tree_node {
  public:
    typedef __rb_tree_node<Value> self;
};

template <class Key,
          class Value,
          class KeyOfValue, // how to define key given value
          class Compare,
          class Alloc>
class rb_tree {
  protected:
    typedef __rb_tree_node<Value> rb_tree_node;
  public:
    typedef rb_tree_node* link_type;
    typedef std::size_t size_type;
  protected:
    size_type node_count;
    link_type hearder;
    Compare key_compare;
};