#include <iostream>

using namespace std;

int sum(int a, int b) {
  cout << "int sum called" << endl;
  return a + b;
}
double sum(double a, double b) {
  cout << "double sum called" << endl;
  return a + b;
}

template <class T> T sum(T a, T b) {
  T result;
  result = a + b;
  return a + b;
}

template <class T, class U> bool areEqual(T a, U b) { return a == b; }

template <class T, int N> T fixed_multiply(T val) { return val * N; }

int main() {
  int a = 2;
  int b = 3;
  double c = 4.0;
  double d = 5.5;
  int intSum = sum(a, b);
  double doubleSum = sum(c, d);
  int Tsum = sum<int>(a, b);
  bool equal = areEqual(a, c); // or areEqual<int,double>(a,c);
  double multiply = fixed_multiply<double, 5>(d);
  cout << intSum << endl;
  cout << doubleSum << endl;
  cout<<multiply<<endl;
}
