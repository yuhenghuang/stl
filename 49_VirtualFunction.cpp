#include <iostream>

using namespace std;

class Base1 {
  public:
    virtual void display() const;
};

void Base1::display() const {
  cout << "Base1::display()" << endl;
}

class Base2: public Base1 {
  public:
    virtual void display() const;
};

void Base2::display() const {
  cout << "Base2::display()" << endl;
}

class Derived: public Base2 {
  public:
    virtual void display() const;
};

void Derived::display() const {
  cout << "Derived::display()" << endl;
}

void fun(Base1 *ptr) {
  ptr->display();
}


int main() {
  Base1 b1;
  Base2 b2;
  Derived d;

  d.Base1::display();
  d.Base2::display();

  fun(&b1);
  fun(&b2);
  fun(&d);

  return 0;
}