#include <cstring>

template <class T> // allocator omitted
class vector {
  public:
    typedef T value_type;
    typedef value_type* iterator;
    typedef value_type& reference;
    typedef std::size_t size_type;
  protected:
    iterator start;
    iterator finish;
    iterator end_of_storage;
  public:
    iterator begin() { return start; }
    iterator end() { return finish; }
    size_type size() const { return size_type (end() - begin()); }
    size_type capacity() const { return size_type ( end_of_storage - begin()); }
    bool empty() const { return begin() == end(); }
    reference operator[] (size_type n) { return *(begin() + n); }
    reference front() { return *begin(); }
    reference end() { return *(end() - 1); }
};