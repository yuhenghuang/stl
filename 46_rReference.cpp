#include <iostream>

using namespace std;


// const ref to allow binding to rvalues
void printAddress (const int& v) {
  cout << reinterpret_cast<const void*>( & v ) << endl;
}

int x=10;

int getInt() {
  return x;
}

// never do this...
int &&getRvaluInt(int &x) {
  int y = 20;
  int z = x * y;
  printAddress(z);
  return move(z);
}

int main() {

  // return 0 address...
  // y is destroyed in the function...
  // int z = getRvaluInt(x);
  // cout << z << endl;
  return 0;
}
