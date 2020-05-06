#include <iostream>
#include <list>
using namespace std;

template <class Container>
class insert_iterator {
  protected:
    Container* container;
    typename Container::iterator iter;
  public:
    typedef output_iterator_tag iterator_category;
    insert_iterator(Container& x, typename Container::iterator i)
    : container(&x), iter(i) {}
    insert_iterator<Container>&
    operator = (const typename Container::value_type& value) {
      iter = container->insert(iter,value);
      ++iter;
      return *this;
    }
};

// template <class Container, class Iterator>
// inline insert_iterator<Container>& inserter(Container& x, Iterator i) {
//   typedef typename Container::iterator iter;
//   return insert_iterator<Container>(x, i);
// }

int main() {
  int myint[] = {10, 20, 30, 40, 50, 60, 70};
  list<int>foo, bar;
  for (int i=1; i<=5; ++i) {
    foo.push_back(i);
    bar.push_back(i*10);
  }

  list<int>::iterator it = foo.begin();
  advance(it, 3);

  copy(bar.begin(), bar.end(), inserter(foo, it));
  return 0;
}