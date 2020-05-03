#include <iostream>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_queue(long& value) {
  cout << "\ntest_deque...........\n";

  queue<string> c;
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
  cout << "queue.size()= " << c.size() << endl;
  cout << "queue.front()= " << c.front() << endl;
  cout << "queue.back()= " << c.back() << endl;
  c.pop();
  cout << "queue.size()= " << c.size() << endl;
  cout << "queue.front()= " << c.front() << endl;
  cout << "queue.back()= " << c.back() << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_queue(size);
  return 0;
}