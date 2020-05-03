#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_unordered_multimap(long& value) {
  cout << "\ntest_unordered_multimap()......\n";

  unordered_multimap<long, string> c;
  char buf[10];
  clock_t timeStart = clock();

  for (long i=0; i<value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.insert(pair<long, string>(i, string(buf)));
    } catch (exception& e) {
      cout << "i=" << i << " " << e.what() << endl;
      abort();
    }
  }

  cout << "milli-seconds: " << clock() - timeStart << endl;
  cout << "unordered_multiset.size()= " << c.size() << endl;
  cout << "unordered_multiset.max_size()= " << c.max_size() << endl;

  long target = get_a_target_long();

  timeStart = clock();
  auto pIter = c.find(target);
  cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
  if (pIter!=c.end())
    cout << "found " << pIter->second << endl;
  else
    cout << "not found!" << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_unordered_multimap(size);
  return 0;
}