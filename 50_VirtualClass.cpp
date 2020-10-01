#include <iostream>

using namespace std;

class Base0 {
  public:
    int var0;
    void fun0() {
      cout << "Member of Base0" << endl;
    }

    Base0(int var): var0(var) { }
};

class Base1: virtual public Base0 {
  public:
    int var1;
    Base1(int var): Base0(var+1) { }
};

class Base2: virtual public Base0 {
  public:
    int var2;
    Base2(int var): Base0(var+2) { }
};

class Derived: public Base1, public Base2 {
  public:
    int var;
    void fun() {
      cout << "Member of Derived" << endl;
    }
    Derived(int var): Base0(var), Base1(var), Base2(var) {}
};


int main() {
  Derived d(10);
  cout << d.var0 << endl;
  d.var0 = 2;
  d.fun0();

  return 0;
}