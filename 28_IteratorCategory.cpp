#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
using namespace std;

void _display_category(random_access_iterator_tag) {
  cout << "random_access_iterator" << endl;
}

void _display_category(bidirectional_iterator_tag) {
  cout << "bidirectional_iterator" << endl;
}

void _dispaly_category(forward_iterator_tag) {
  cout << "forward_iterator" << endl;
}

void _display_category(output_iterator_tag) {
  cout << "output_iterator" << endl;
}

void _display_category(input_iterator_tag) {
  cout << "input_iterator" << endl;
}

template <typename I>
void display_category(I iter) {
  typedef typename iterator_traits<I>::iterator_category cate;
  _dispaly_category(cate());
  // typename iterator_traits<I>::iterator_category cate;
  // _dispaly_category(cate);

  cout <<"typeid(iter).name()= "<< typeid(iter).name() << endl;
}

void test_iterator_category() {
  cout << "\ntest_iterator_category.........\n" << endl;

  display_category(array<int, 10>::iterator());
  display_category(vector<int>::iterator());
  display_category(list<int>::iterator());
  display_category(forward_list<int>::iterator());
  display_category(deque<int>::iterator());
}

int main() {
  test_iterator_category();
  return 0;
}