#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_multiset(long& value) {
  cout << "\ntest_multiset()......\n";

  multiset<string> c;
  char buf[10];
  clock_t timeStart = clock();

  for (long i=0; i<value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.insert(string(buf));
    } catch (exception& e) {
      cout << "i=" << i << " " << e.what() << endl;
      abort();
    }
  }

  cout << "milli-seconds: " << clock() - timeStart << endl;
  cout << "multiset.size()= " << c.size() << endl;
  // cout << "multiset.front()= " << c.front() << endl;
  cout << "multiset.max_size()= " << c.max_size() << endl;
  // cout << "multiset.back()= " << c.back() << endl;

  string target = get_a_target_string();

  timeStart = clock();
  auto pIter = find(c.begin(), c.end(), target);
  cout << "find(), milli-seconds: " << clock() - timeStart << endl;
  if (pIter!=c.end())
    cout << "found " << *pIter << endl;
  else
    cout << "not found!" << endl;


  timeStart = clock();
  pIter = c.find(target);
  cout << "c.find(), milli-seconds: " << clock() - timeStart << endl;
  if (pIter!=c.end())
    cout << "found " << *pIter << endl;
  else
    cout << "not found!" << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_multiset(size);
  return 0;
}