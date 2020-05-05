#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// template <class InputIterator, class Function>
// Function for_each(InputIterator first, InputIterator last, Function f) {
//   for (; first!=last; ++first)
//     f(*first); // f() need & reference to modify original data;
//   return f;
// }

void myfunc(int i) {
  cout << " " << i;
}

struct myclass {
  void operator() (int i) { cout << " " << i; }
};

void test_for_each() {
  vector<int> myvec = {10, 20, 30};
  for_each(myvec.begin(), myvec.end(), myfunc);
  cout << endl;

  for_each(myvec.begin(), myvec.end(), myclass());
}

int main() {
  test_for_each();
  return 0;
}