#include <type_traits>
#include <iostream>
using namespace std;

template <typename T>
void test_type_traits(const T& x) {
  cout << "\ntest_type_traits for type: " << typeid(T).name() << endl;

  cout << "is_void\t" << is_void<T>::value << endl;
  cout << "is_integral\t" << is_integral<T>::value << endl;
  cout << "is_volatile\t" << is_volatile<T>::value << endl;
  cout << "is_member_pointer\t" << is_member_pointer<T>::value << endl;
  cout << "has_virtual_destructor\t" << has_virtual_destructor<T>::value << endl;
  cout << "is_default_constructible\t" << is_default_constructible<T>::value << endl;
  cout << "is_copy_constructible\t" << is_copy_constructible<T>::value << endl;
  cout << "is_move_constructilble\t" << is_move_constructible<T>::value << endl;
  cout << "is_copy_assignable\t" << is_copy_assignable<T>::value << endl;
  cout << "is_move_assignable\t" << is_move_assignable<T>::value << endl;
  cout << "is_destructible\t" << is_destructible<T>::value << endl;
  cout << "is_polymophic\t" << is_polymorphic<T>::value << endl;
  cout << "is_object\t" << is_object<T>::value << endl;
}

class Zoo {
  private:
    int d1, d2;
  public:
    Zoo(int i1, int i2): d1(i1), d2(i2) {}
    Zoo(const Zoo&) = delete;
    Zoo(Zoo&&) = default;
    Zoo& operator = (const Zoo&) = default;
    Zoo& operator = (const Zoo&&) = delete;
    virtual ~Zoo() {}
};

int main() {
  test_type_traits(6);
  test_type_traits("string");
  test_type_traits(Zoo(1, 2));
  return 0;
}