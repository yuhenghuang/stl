#include <iostream>
using namespace std;

class T {
  private:
    int val;
  public:
    T(int v): val(v) {};
    void display() { cout << val << endl; }
    int& getVal() { return val; }
};

class ListNode {
  public:
    ListNode(T d): data(d) {}
    T data;
    ListNode *next;
};

class Iterator {
  public:
    Iterator(ListNode* n): node(n){}
    Iterator(const Iterator& x): node(x.node) { }
    ListNode *node;
    T& operator*() const { return (*node).data; }
    T* operator->() const { return &(operator*()); } // use overloaded * in this way
    Iterator operator++(int) { Iterator tmp=*this; ++*this; return tmp; } // default * has highest priority, valid inside
    Iterator& operator++() { node = (*node).next; return *this; }
    Iterator* self() { return this; } // use other method to return the pointer of the whole object
};

int main() {
  ListNode n1(1), n2(3);
  n1.next = &n2;
  Iterator iter(&n1);
  Iterator* ptr = iter.self();
  iter->display();
  (*ptr)->display();
  iter++;
  iter->display();
  (*ptr)->display();
  iter->getVal()--;
  iter->display();
  (*ptr)->display();
  return 0;
}