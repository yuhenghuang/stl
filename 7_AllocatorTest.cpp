#include <list>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

#include <ext\array_allocator.h>
#include <ext\mt_allocator.h>
#include <ext\debug_allocator.h>
#include <ext\pool_allocator.h>
#include <ext\bitmap_allocator.h>
#include <ext\malloc_allocator.h>
#include <ext\new_allocator.h>

void test_list_with_special_allocator() {
  cout << "\ntest_list_with_special_allocator()........\n";

  list<string, allocator<string>> c1;
  list<string, __gnu_cxx::malloc_allocator<string>> c2;
  list<string, __gnu_cxx::new_allocator<string>> c3;
  list<string, __gnu_cxx::__pool_alloc<string>> c4;
  list<string, __gnu_cxx::__mt_alloc<string>> c5;
  list<string, __gnu_cxx::bitmap_allocator<string>> c6;
  // list<string, __gnu_cxx::debug_allocator<string>> c7;

  int choice;
  long value;

  cout << "select: ";
  cin >> choice;
  if (choice!=0) {
    cout << "how many elements: ";
    cin >> value;
  }

  char buf[10];
  clock_t timeStart = clock();

  for (long i=0; i<value; ++i) {
    try {
      snprintf(buf, 10, "%d", i);
      switch (choice) {
        case 1: c1.push_back(string(buf)); break;
        case 2: c2.push_back(string(buf)); break;
        case 3: c3.push_back(string(buf)); break;
        case 4: c4.push_back(string(buf)); break;
        case 5: c5.push_back(string(buf)); break;
        case 6: c6.push_back(string(buf)); break;
        default: break;
      }
    } catch (exception& e) {
      cout << "i=" << i << " " << e.what() << endl;
      abort();
    }
  }

  cout << "a lof of push_back(), milli-seconds: " << clock() - timeStart << endl;

  int* p;
  allocator<int> alloc1;
  p = alloc1.allocate(1);
  alloc1.deallocate(p, 1);

  __gnu_cxx::malloc_allocator<int> alloc2;
  p = alloc2.allocate(1);
  alloc2.deallocate(p, 1);

    __gnu_cxx::new_allocator<int> alloc3;
  p = alloc3.allocate(1);
  alloc3.deallocate(p, 1);

  __gnu_cxx::__pool_alloc<int> alloc4;
  p = alloc4.allocate(1);
  alloc4.deallocate(p, 1);

  __gnu_cxx::__mt_alloc<int> alloc5;
  p = alloc5.allocate(1);
  alloc5.deallocate(p, 1);

  __gnu_cxx::bitmap_allocator<int> alloc6;
  p = alloc6.allocate(3);
  alloc6.deallocate(p, 3);
}

int main() {
  test_list_with_special_allocator();
  return 0;
}