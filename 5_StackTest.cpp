#include <iostream>
#include <cstdlib>
#include <stack>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_stack(long& value) {
  cout << "\ntest_deque...........\n";

  stack<string> c;
  char buf[10];

    clock_t timeStart = clock();
  
  for (long i=0; i<value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.push(string(buf));
    } catch (exception& e) {
      cout << "i=" << i << " " << e.what() << endl;
      abort();
    }
  }

  cout << "milli-seconds: " << clock() - timeStart << endl;
  cout << "stack.size()= " << c.size() << endl;
  cout << "stack.top()= " << c.top() << endl;
  c.pop();
  cout << "stack.size()= " << c.size() << endl;
  cout << "stack.top()= " << c.top() << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_stack(size);
  return 0;
}