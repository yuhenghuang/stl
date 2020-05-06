#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <unordered_set>
#include <deque>
#include <ctime>
#include <functional>
using namespace std;

class MyString {
  public:
    static size_t num_default_construction;
    static size_t num_construction;
    static size_t num_copy_construction;
    static size_t num_copy_assignment;
    static size_t num_move_construction;
    static size_t num_move_assignment;
    static size_t num_destruction;
  private:
    char* _data;
    size_t _len;
    void _init_data(const char* s) {
      _data = new char[_len+1];
      memcpy(_data, s, _len);
      _data[_len] = '\0';
    }
  public:
    MyString(): _data(nullptr), _len(0) { ++num_default_construction; }
    MyString(const char* p): _len(strlen(p)) {
      ++num_construction;
      _init_data(p);
    }
    MyString(const MyString& str): _len(str._len) {
      ++num_copy_construction;
      _init_data(str._data);
    }
    MyString(MyString&& str) noexcept
    : _data(str._data), _len(str._len) {
      ++num_move_construction;
      str._len = 0;
      str._data = nullptr;
    }

    MyString& operator=(const MyString& str) {
      ++num_copy_assignment;
      if (this!=&str) {
        if (_data) delete _data;
        _len = str._len;
        _init_data(str._data);
      }
      return *this;
    }
    MyString& operator=(MyString&& str) {
      ++num_move_assignment;
      if (this!=&str) {
        if (_data) delete _data;
        _len = str._len;
        _data = str._data;
        str._len = 0;
        str._data = nullptr;
      }
      return *this;
    }
    virtual ~MyString() {
      ++num_destruction;
      if (_data) delete _data;
    }
    bool operator<(const MyString& rhs) const {
      return strcmp(_data, rhs._data)<0;
    }
    bool operator==(const MyString& rhs) const {
      return strcmp(_data, rhs._data)==0;
    }
    char* get() const { return _data; }
};

size_t MyString::num_construction = 0;
size_t MyString::num_copy_assignment = 0;
size_t MyString::num_copy_construction = 0;
size_t MyString::num_default_construction = 0;
size_t MyString::num_move_construction = 0;
size_t MyString::num_move_assignment = 0;
size_t MyString::num_destruction = 0;

namespace std{
template<>
struct hash<MyString> {
  size_t operator() (const MyString& x) const noexcept {
    return hash<char*>()(x.get());
  }
};
};


template <typename T>
void output_static_data(const T& str) {
  cout << typeid(str).name() << "--" << endl;
  cout << "default_construction: " << T::num_default_construction << endl;
  cout << "construction: " << T::num_construction << endl;
  cout << "copy_construction:" << T::num_copy_construction << endl;
  cout << "move_construction:" << T::num_move_construction << endl;
  cout << "copy_assignment: " << T::num_copy_assignment << endl;
  cout << "move_assignment: " << T::num_move_assignment << endl;
  cout << "destruction: " << T::num_destruction << endl;
}

template<typename M>
void test_moveable(M c1, long s) {
  char buf[10];

  typedef typename iterator_traits<typename M::iterator>::value_type value_type;

  clock_t timeStart = clock();
  for (long i=0; i<s; ++i) {
    snprintf(buf, 10, "%d", rand());
    auto iter = c1.end();
    c1.insert(iter, value_type(buf));
  }
  cout << "construction, ms: " << clock() - timeStart << endl;
  cout << "size = " << c1.size() << endl;
  output_static_data(*(c1.begin()));

  timeStart = clock();
  M c11(c1);
  cout << "copy, ms: " << clock() - timeStart << endl;

  timeStart = clock();
  // c1 should not be used anymore here forth
  M c12(std::move(c1));
  cout << "move copy, ms: " << clock() - timeStart << endl;

  timeStart = clock();
  c11.swap(c12); 
  cout << "swap, ms: " << clock() - timeStart << endl;
}

int main() {
  long s;
  cout << "Input size: ";
  cin >> s;
  vector<MyString> c1;
  test_moveable(c1, s);
  return 0;
}