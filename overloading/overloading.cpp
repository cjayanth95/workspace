#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CVector {
public:
  int x;
  int y;
  CVector(){};
  CVector(int x, int y) : x(x), y(y){};
  CVector operator+(const CVector &);
  CVector operator=(const CVector &);
};
CVector CVector::operator+(const CVector &v) {
  CVector temp;
  temp.x = x + v.x;
  temp.y = y + v.y;
  return temp;
}
// example. doesn't work though
CVector CVector::operator=(const CVector &v) {
  CVector temp;
  temp.x = v.x;
  temp.y = v.y;
  return *this;
}

// static member
//
class Dummy {
public:
  static int n;
  Dummy() { n++; };
};
int Dummy::n = 0;
int main() {
  CVector foo(3, 1);
  CVector bar(3, 1);
  CVector baz(3, 1);
  CVector temp = foo + bar.operator+(baz);
  // cout << temp.x << temp.y << endl;
  Dummy d1;
  Dummy d2;
  Dummy *d3 = new Dummy;
  cout << Dummy::n << endl;
}
