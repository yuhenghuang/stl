#include <iostream>
#include <cstdlib>
#include <map>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_map(long& value) {
  cout << "\ntest_map()......\n";

  map<long, string> c;
  char buf[10];
  clock_t timeStart = clock();

  for (long i=0; i<value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      // c.insert(pair<long, string>(i, string(buf)));
      c[i] = string(buf);
    } catch (exception& e) {
      cout << "i=" << i << " " << e.what() << endl;
      abort();
    }
  }

  cout << "milli-seconds: " << clock() - timeStart << endl;
  cout << "map.size()= " << c.size() << endl;
  // cout << "multiset.front()= " << c.front() << endl;
  cout << "map.max_size()= " << c.max_size() << endl;
  // cout << "multiset.back()= " << c.back() << endl;

  long target = get_a_target_long();

  timeStart = clock();
  auto pIter = c.find(target);
  cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
  if (pIter!=c.end())
    cout << "found " << (*pIter).second << endl;
  else
    cout << "not found!" << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_map(size);
  return 0;
}