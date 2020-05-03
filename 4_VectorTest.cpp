#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_vector(long& value) {
  cout << "\ntest_vector..........\n";

  vector<string> c;
  char buf[10];

  clock_t timeStart = clock();
  
  for (long i=0; i<value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.push_back(string(buf));
    } catch (exception& e) {
      cout << "i=" << i << " " << e.what() << endl;
      abort();
    }
  }

  cout << "milli-seconds: " << clock() - timeStart << endl;
  cout << "vector.size()= " << c.size() << endl;
  cout << "vector.front()= " << c.front() << endl;
  cout << "vector.back()= " << c.back() << endl;
  cout << "vector.data()= " << c.data() << endl;
  cout << "vector.capacity()= " << c.capacity() << endl;

  string target = get_a_target_string();

  timeStart = clock();
  auto pIter = find(c.begin(), c.end(), target);
  cout << "find(), milli-seconds: " << clock() - timeStart << endl;
  if (pIter!=c.end())
    cout << "found " << *pIter << endl;
  else
    cout << "not found!" << endl;

  timeStart = clock();
  sort(c.begin(), c.end());
  string* pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareString);
  cout << "qsort()+bsearch(), milli-seconds: " << clock() - timeStart << endl;

  if (pItem!=nullptr)
    cout << "found " << *pItem << endl;
  else
    cout << "not found!" << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_vector(size);
  return 0;
}