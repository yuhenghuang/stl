#include <cstring>
#include <vector>
using namespace std;

template <class Value>
struct __hashtable_node {
  __hashtable_node* next;
  Value val;
};

template <class Value, class Key, class HashFcn, class ExtractKey, class EqualKey, class Alloc>
struct __hashtable_iterator {
  typedef __hashtable_node<Value> node;
  typedef hashtable<Value, Key, HashFcn, ExtractKey, EqualKey, Alloc> hashtable;
  node* cur;
  hashtable* ht; // back to buckets vector to next bucket
};

template <class Value, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc>
class hashtable {
  public:
    typedef HashFcn hasher;
    typedef EqualKey key_equal;
    typedef size_t size_type;
    typedef Key key_type;
    typedef Value value_type;
  private:
    hasher hash;
    key_equal equals;
    ExtractKey get_key;
    typedef __hashtable_node<Value> node;
    vector<node*, Alloc> buckets;
    size_type num_elements;
  protected:
    size_type bkt_num(const value_type& obj, size_type n) const { return bkt_num_key(get_key(obj), n); }
    size_type bkt_num(const value_type& obj) const { return bkt_num_key(get_key(obj)); }
    size_type bkt_num_key(const key_type& key, size_type n) const { return hash(key) % n;}
    size_type bkt_num_key(const key_type& key) const { return bkt_num_key(key, buckets.size()); }
  public:
    size_type bucket_count() const { return buckets.size(); }
};