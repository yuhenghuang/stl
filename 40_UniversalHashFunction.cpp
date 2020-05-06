#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


template <typename T>
inline void hash_combine(size_t& seed, const T& val) {
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

// end of recursion could be 
// either 
// template <typename T>
// inline void hash_val(size_t& seed, const T& val) {
//   hash_combine(seed, val); // last
// }

// or
inline void hash_val(size_t& seed) {}
// ... refers to non-negative number of parameters

template <typename T, typename... Types>
inline void hash_val(size_t& seed,
                     const T& val, const Types&... args) {
  hash_combine(seed, val);
  hash_val(seed, args...);
}

template <typename... Types>
inline size_t hash_val(const Types&... args) {
  size_t seed=0;
  hash_val(seed, args...);
  return seed;
}

class Customer {
  public:
    string fname, lname;
    long no;
    Customer(string f, string l, long n): fname(f), lname(l), no(n) {}
    bool operator == (const Customer& x) const {
      return fname.compare(x.fname)==0 && lname.compare(x.lname)==0 && no==x.no;
    } // never forget two const in this function!!!!
};

class CustomerHash {
  public:
    size_t operator () (const Customer& c) const {
      return hash_val(c.fname, c.lname, c.no);
    }
};

int main() {
  CustomerHash hh;

  unordered_set<Customer, CustomerHash> set3;
  set3.insert(Customer("Ace", "Hou", 1L));
  set3.insert(Customer("Beta", "Mao",2L));
  set3.insert(Customer("Light", "shiau", 3L));
  set3.insert(Customer("Paili", "Chen", 4L));
  size_t n = set3.bucket_count();
  cout << "Bucket count: " << n << endl;

  cout << "bucket position of Ace = " << hh(Customer("Ace", "Hou", 1L)) % n<< endl;
  cout << "bucket position of Ace = " << hh(Customer("Ace", "Hou", 1L)) % n<< endl;
  cout << "bucket position of Ace = " << hh(Customer("Light", "shiau", 3L)) % n << endl;
  cout << "bucket position of Ace = " << hh(Customer("Paili", "Chen", 4L)) % n<< endl;

  for (unsigned i=0; i<n; ++i)
    cout << "bucket #" << i << " has " << set3.bucket_size(i) << " elements." << endl;
  return 0;
}


// in namespace std
// partial specialization for hash<>()

template <>
struct hash<Customer> {
  size_t operator () (const Customer& c) const noexcept {
    // can be anyting that returns size_t
    // e.g.
    return hash<string>()(c.lname);
  }
};