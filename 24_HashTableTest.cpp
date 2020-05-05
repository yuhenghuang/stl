#include <ext\hash_map>
#include <cstring>
using namespace std;

inline size_t __stl_hash_string(const char* s) {
  unsigned long h = 0;
  for (; *s; ++s) {
    h = 5*h + *s;
  }
  return size_t(h);
}

template<class T>
struct __hash {};

template<>
struct __hash<const char*> {
  size_t operator () (const char* s) const { return __stl_hash_string(s);}
};

struct eqstr {
  bool operator() (const char* s1, const char* s2) const {
    return strcmp(s1, s2)==0; // strcmp() return int, not bool
  }
};

int main() {
  __gnu_cxx::hashtable<const char*, // Value
                       const char*, // Key
                       __hash<const char*>, // HashFcn
                       std::_Identity<const char*>, // ExtractKey
                       eqstr // EqualKey
                       > ht(50, __hash<const char*>(), eqstr());
  ht.insert_unique("kiwi");
  ht.insert_unique("plum");
  ht.insert_unique("apple");
  return 0;
}