#include <iostream>

using namespace std;

class Base1 {
  public:
    void display() const {
      cout << "Base1::display()" << endl;
    }
};


class Base2: public Base1 {
  public:
    virtual void display() const {
      cout << "Base2::display()" << endl;
    }
};

class Derived: public Base2 {
  public:
    virtual void display() const {
      cout << "Derived::display()" << endl;
    }
};


void fun(Base1 *ptr) {
  ptr->display();
}


void fun2(Base2 *ptr) {
  ptr->display();
}


int main() {
  Base1 b1;
  Base2 b2;
  Derived d;

  fun(&b1);
  fun(&b2);
  fun(&d);

  fun2(&b2);
  fun2(&d);



  return 0;
}