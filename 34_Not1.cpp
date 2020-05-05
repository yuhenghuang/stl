#include <functional>

// template <class Operation>
// class unary_negate: public std::unary_function<typename Operation::argument_type, 
//                                          typename Operation::result_type> {
//   protected:
//     Operation op;
//   public:
//     unary_negate(const Operation& x): op(x) {} // constructor conflicts with auxiliary function...
//     typename Operation::result_type 
//     operator () (const typename Operation::argument_type& x) const {
//       return !op(x);
//     }
// };

template <class Predicate>
class unary_negate: public std::unary_function<typename Predicate::argument_type, bool> {
  protected:
    Predicate pred;
  public:
    explicit unary_negate(const Predicate& x): pred(x) {}
    bool operator () (const typename Predicate::argument_type x) { return !pred(x); }
};

template <class Predicate>
inline unary_negate<Predicate> not1(const Predicate& pred) {
  return unary_negate<Predicate>(pred);
}