#include <iostream>
#include <string>
#include <complex>
#include <tuple>
using namespace std;

int main() {
  cout << "string, sizeof = " << sizeof(string) << endl;
  cout << "double, sizeof = " << sizeof(double) << endl;
  cout << "float, sizeof = " << sizeof(float) << endl;
  cout << "int, sizeof = " << sizeof(int) << endl;
  cout << "complex<double>, sizeof = " << sizeof(complex<double>) << endl;

  tuple<int, int, float, complex<double>> t; // 12 + 16 = 28
  cout << "sizeof = " << sizeof(t) << endl;

  tuple<int, float, string> t1(41, 6.3, "nico");
  cout << "tuple<int, float, string>, sizeof = " << sizeof(t1) << endl;

  cout << "t1: " << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;

  auto t2 = make_tuple(22, 44, "stacy");
  get<1>(t1) = get<1>(t2);

  if (t1 < t2) 
    cout << "t1 < t2";
  else
    cout << "t1 >= t2";
  cout << endl;
  t1 = t2;
  //cout << "t1: " << t1 << endl;

  tuple<int, float, string> t3(77, 1.1, "maki");
  int i1;
  float f1;
  string s1;
  tie(i1, f1, s1) = t3;

  typedef tuple<int, float, string> TupleType;
  cout << tuple_size<TupleType>::value << endl;
  typename tuple_element<1, TupleType>::type f2 = 2.3;
  typedef tuple_element<1, TupleType> second_type;

  return 0;
}