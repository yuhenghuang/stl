#include <iostream>
#include <cstdlib>
#include <forward_list>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_forward_list(long& value) {
  cout << "\ntest_forward_list..........\n";

  forward_list<string> c;
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

  cout << "milli-seconds: " << clock() - timeStart << endl;
  // cout << "list.size()= " << c.size() << endl;
  cout << "forward_list.front()= " << c.front() << endl;
  cout << "forward_list.max_size()= " << c.max_size() << endl;
  // cout << "vector.back()= " << c.back() << endl;

  string target = get_a_target_string();

  timeStart = clock();
  auto pIter = find(c.begin(), c.end(), target);
  cout << "find(), milli-seconds: " << clock() - timeStart << endl;
  if (pIter!=c.end())
    cout << "found " << *pIter << endl;
  else
    cout << "not found!" << endl;


  timeStart = clock();
  c.sort();
  cout << "sort(), milli-seconds: " << clock() - timeStart << endl;
}

int main() {
  long size;
  cout << "how many elements: ";
  cin >> size;
  test_forward_list(size);
  return 0;
}