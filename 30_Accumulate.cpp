#include <iostream>
using namespace std;

template <class InputIterator, class T>
T accumulate(InputIterator first, InputIterator last, T init) {
  for (; first!=last; ++first)
    init += *first;
  return init;
}

template <class InputIterator, class T, class BinaryOperation>
T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation binary_op) {
  for (; first!=last; ++first)
    init = binary_op(init, *first);
  return init;
}

int myfunc(int x, int y) { return x+2*y;}

struct myclass {
  int operator() (int& x, int& y) { return x+3*y; }
} myobj;

void test_accumulate() {
  int init = 100;
  int nums[] = {10, 20, 30};

  cout << "using default accumulate: ";
  cout << accumulate(nums, nums+3, init) << endl;

  cout << "using functional's minus: ";
  cout << accumulate(nums, nums+3, init, minus<int>()) << endl;

  cout << "using custom function: ";
  cout << accumulate(nums, nums+3, init, myfunc) << endl;

  cout << "using custom object: ";
  cout << accumulate(nums, nums+3, init, myclass()) << endl;
}

int main() {
  test_accumulate();
  return 0;
}