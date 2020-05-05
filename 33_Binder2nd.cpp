#include <functional>


template <class Operation>
class binder2nd: public std::unary_function<typename Operation::first_argument_type,
                                            typename Operation::result_type> {
  protected:
    Operation op;
    typename Operation::second_argument_type value;
    // Following line is implicitly executed by inheriting from class unary_function<,>
    // typedef Operation::first_argument_type argument_type;
  public:
    binder2nd(const Operation& x, 
              const typename Operation::second_argument_type& y): op(x), value(y) {}
    typename Operation::result_type
    operator () (const typename Operation::first_argument_type& x) const {
      return op(x, value);
    }
};

template<class Operation, class T>
inline binder2nd<Operation> bind2nd(const Operation& op, const T& x) {
  typedef typename Operation::second_argument_type arg2_type;
  return binder2nd<Operation>(op, arg2_type(x)); // coerce T to arg2_type
}


int main() {
  // cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
  return 0;
}