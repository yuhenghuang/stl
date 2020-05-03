#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_set(long& value) {
  cout << "\ntest_set()......\n";

  set<string> c;
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
  cout << "set.size()= " << c.size() << endl;
  cout << "set.max_size()= " << c.max_size() << endl;

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
  test_set(size);
  return 0;
}