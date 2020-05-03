#include <ctime>
#include <iostream>
#include <array>
#include <cstdlib>
#include "stlutil.h"
using namespace std;

void test_array() {
  cout << "\ntest_array().......\n";

  array<long, ASIZE> c;
  clock_t timeStart = clock();
  for (int i=0; i<ASIZE; ++i)
    c[i] = rand();

  cout << "milli-seconds: " << clock() - timeStart << endl;
  cout << "array.size()" << c.size() << endl;
  cout << "array.front()" << c.front() << endl;
  cout << "array.back()" << c.back() << endl;
  cout << "array.data()" << c.data() << endl;

  long target = get_a_target_long();

  timeStart = clock();
  qsort(c.data(), ASIZE, sizeof(long), compareLong);
  long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLong);
  cout << "qsort()+bsearch(), milli-seconds: " << clock() - timeStart << endl;
  if (pItem!=nullptr)
    cout << "found " << *pItem << endl;
  else
    cout << "not found!" << endl;
}

int main() {
  test_array();
  return 0;
}