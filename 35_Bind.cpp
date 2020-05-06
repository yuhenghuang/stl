#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

double my_divide(double x, double y) { return x/y; }
struct my_pair {
  double a, b;
  double multiply() { return a*b; }
};
using namespace std;
using namespace std::placeholders;


int main() {
  auto fn_five = bind(my_divide, 10, 2);
  cout << fn_five() << endl;

  auto fn_half = bind(my_divide, _1, 2);
  cout << fn_half(10) << endl;

  auto fn_invert = bind(my_divide, _2, _1);
  cout << fn_invert(10, 2) << endl;

  auto fn_rounding = bind<int>(my_divide, _1, _2);
  cout << fn_rounding(10, 3) << endl;


  my_pair ten_two {10, 2};

  auto bound_memfn = bind(&my_pair::multiply, _1);
  cout << bound_memfn(ten_two) << endl;

  auto bound_memdata = bind(&my_pair::a, ten_two);
  cout << bound_memdata() << endl;

  auto bound_memdata2 = bind(&my_pair::b, ten_two);
  cout << bound_memdata2() << endl;

  vector<int> v {15, 37, 94, 50, 73, 58, 28, 98};
  int n = count_if(v.cbegin(), v.cend(), not1(bind2nd(less<int>(), 50)));
  cout << "n = " << n << endl;

  auto fn_ = bind(less<int>(), _1, 50);
  cout << count_if(v.begin(), v.end(), fn_) << endl;
  cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 50));

  return 0;
}