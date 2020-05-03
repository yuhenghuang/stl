#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include <ctime>
#include <algorithm>
#include "stlutil.h"
using namespace std;

void test_unordered_multiset(long& value) {
  cout << "\ntest_unordered_multiset()......\n";

  unordered_multiset<string> c;
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
  cout << "unordered_multiset.size()= " << c.size() << endl;
  cout << "unordered_multiset.max_size()= " << c.max_size() << endl;
  cout << "unordered_multiset.bucked_count()= " << c.bucket_count() << endl;
  cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;
  cout << "unordered_multiset.max_bucked_count()= " << c.max_bucket_count() << endl;
  cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;

  for (unsigned i=0; i<20; ++i)
    cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements" << endl;

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
  test_unordered_multiset(size);
  return 0;
}