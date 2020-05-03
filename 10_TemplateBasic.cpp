#include <iostream>
//using namespace std;

template <typename T>
class Complex {
  public:
    Complex(T r=0, T i=0): re(r), im(i) {}
    Complex& operator += (const Complex&);
    T real() const { return re; }
    T imag() const { return im; }
  private:
    T re, im;
    //friend Complex& __doapl(Complex*, const Complex&);
};

class stone {
  private:
    int _w, _h, _weight;
  public:
    stone(): _w(0), _h(0), _weight(0) {};
    stone(int w, int h, int we): _w(w), _h(h), _weight(we) {}
    bool operator < (const stone& rhs) const {
      return _weight < rhs._weight;
    }
    int getWeight() const { return _weight; }
};

template <class T>
inline const T& min(const T& a, const T& b) {
  return b<a ? b : a;
}

int main() {
  stone s1(2,3,4), s2(3,4,5), s3;
  s3 = min(s1, s2);
  std::cout << s3.getWeight() << std::endl;
}