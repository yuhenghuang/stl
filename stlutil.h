#include <iostream>
#include <string>
using namespace std;

const int ASIZE = 500000;

long get_a_target_long() {
  long target=0;
  cout << "target (0~" << RAND_MAX << "): ";
  cin >> target;
  return target;
}

string get_a_target_string() {
  long target=0;
  char buf[10];

  cout << "target (0~" << RAND_MAX << "): ";
  cin >> target;
  snprintf(buf, 10, "%d", target);
  return string(buf);
}

int compareLong(const void* a, const void* b) {
  return *(long*)a - *(long*)b;
}

int compareString(const void* a, const void* b) {
  if ( *(string*)a > *(string*)b )
    return 1;
  else if ( *(string*)a < *(string*)b )
    return -1;
  else 
    return 0;
}