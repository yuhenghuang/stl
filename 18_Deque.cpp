#include <cstring>
#include <iostream>
using namespace std;

template <class T, std::size_t BufSiz>
struct __deque_iterator {
  public:
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef pointer* map_pointer;
    typedef __deque_iterator self;

    pointer cur;
    pointer first;
    pointer last;
    map_pointer node;

    inline size_type __deque_buf_size(size_type n, size_type sz) {
      return n!=0 ? n : (sz<512 ? size_type(512 / sz) : size_type(1));
    }
    size_type buffer_size() {
      return __deque_buf_size(BufSiz, sizeof(value_type));
    }

    bool operator== (const self& rhs) { return cur == rhs.cur; }
    difference_type operator- (const self& rhs) {
      return (node - x.node - 1) * difference_type(buffer_size()) + (cur - first) + (rhs.last - rhs.cur);
    }
    reference operator* () const { return *cur; }
    pointer operator-> () const { return &(operator*()); }
    void set_node(map_pointer new_node) {
      // map_pointer can be generalized as a vector iterator
      // if (new_node==map_pointer.begin() || end())
      node = new_node;
      first = *new_node;
      last = first + difference_type(buffer_size());
    }

    self& operator++ () {
      ++cur;
      if (cur==last) {
        set_node(node + 1);
        cur = first;
      }
      return *this;
    }
    self operator++ (int) {
      self tmp = *this;
      ++*this;
      return tmp;
    }

    self& operator-- () {
      if (cur==first) {
        set_node(node - 1);
        cur = last;
      }
      --cur;
      return *this;
    }
    self operator-- (int) {
      self tmp = *this;
      --*this;
      return tmp;
    }

    self& operator += (difference_type n) {
      difference_type offset = n + (cur - first);
      if (offset >= 0 && offset < difference_type(buffer_size())) // same buffer
        cur += n;
      else { // other buffer
        difference_type node_offset = offset > 0 ? offset / difference_type(buffer_size()) : -difference_type((-offset-1) / buffer_size())
        set_node(node + node_offset);
        cur = first + (offset - node_offset * difference_type(buffer_size()));
      }
      return *this;
    }
    self operator + (difference_type n) const {
      self tmp = *this;
      return tmp += n;
    }

    self& operator -= (difference_type n) {
      return *this+=(-n);
    }
    self operator - (difference_type n) const {
      self tmp = *this;
      return tmp -= n;
    }

    reference operator [] (difference_type n) const { return *(*this+n); }
};

template <class T, class Alloc, std::size_t BufSiz=0>
class deque {
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef __deque_iterator<T, BufSiz> iterator;
  protected:
    typedef pointer* map_pointer;
  protected:
    iterator start;
    iterator finish;
    map_pointer map;
    size_type map_size;
  public:
    iterator begin() { return start; }
    iterator end() { return finish; }
    size_type size() const { return finish - start; }

    reference operator[] (size_type n) { return start[difference_type(n)]; }
    reference front() { return *start; }
    reference back() { 
      iterator tmp = finish; 
      --tmp;
      return *tmp;
    }
    size_type size() const { return finish - start; }
    bool empty() const { return finish == start; }
};