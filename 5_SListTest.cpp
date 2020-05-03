#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <algorithm>
#include <ext\slist>
#include "stlutil.h"
using namespace std;

void test_slist(long& value) {
  cout << "\ntest_slist().....\n";

  __gnu_cxx::slist<string> c;
  char buf[10];

  clock_t timeStart = clock();

  for (long i=0; i<value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.push_front(string(buf));
    } catch (exception& e) {
      cout << "i=" << i << " " << e.what() << endl;
      abort();
    }
  }

  cout << "milli-second: " << clock() - timeStart << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_slist(size);
  return 0;
}