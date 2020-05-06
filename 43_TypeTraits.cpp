#include <iostream>
#include <type_traits>


// remove const
template <typename _Tp>
struct remove_const {
  typedef _Tp type;
};

template <typename _Tp>
struct remove_const<_Tp const> {
  typedef _Tp type;
};

// remove volatile
template <typename _Tp>
struct remove_volatile {
  typedef _Tp type;
};

template <typename _Tp>
struct remove_volatile<_Tp volatile> {
  typedef _Tp type;
};

// remove const and volatile
template <typename _Tp>
struct remove_cv {
  typedef typename remove_const<typename remove_volatile<_Tp>::type>::type type;
};

// add const
template <typename _Tp>
struct add_const {
  typedef _Tp const type;
};

// is void helper
template <typename _Tp>
struct __is_void_helper: public std::__false_type {};

template <>
struct __is_void_helper<void>: public std::__true_type {};

// is void
template <typename _Tp>
struct is_void: public __is_void_helper<typename remove_cv<_Tp>::type>::type {};


// is integral helper
template<typename>
struct __is_integral_helper: public std::__false_type {};

template <>
struct __is_integral_helper<bool>: public std::__true_type {};
template <>
struct __is_integral_helper<char>: public std::__true_type {};
template <>
struct __is_integral_helper<signed char>: public std::__true_type {};
template <>
struct __is_integral_helper<unsigned char>: public std::__true_type {};

// ....

template <>
struct __is_integral_helper<int>: public std::__true_type {};
template <>
struct __is_integral_helper<unsigned int>: public std::__true_type {};

// ....

template <>
struct __is_integral_helper<long long>: public std::__true_type {};
template <>
struct __is_integral_helper<unsigned long long>: public std::__true_type {};

// is integral
template <typename _Tp>
struct is_integral: public __is_integral_helper<typename remove_cv<_Tp>::type>::type {};