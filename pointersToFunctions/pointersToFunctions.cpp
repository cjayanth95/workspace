#include <iostream>
#include <string>
using namespace std;

int addition(int x, int y) { return x + y; }
int subtraction(int x, int y) { return x - y; }
int operation(int x, int y, int (*function)(int, int)) {
  int g = (*function)(x, y);
  return g;
}

int main() {
  int x = 5;
  int y = 3;
  int opAdd = operation(x, y, addition);
  int opSub = operation(x, y, subtraction);
  int (*minus)(int, int) = subtraction;
  int opMin = operation(x, y, minus);
  cout << opAdd << endl;

  cout << opSub << endl;
  cout << opMin << endl;
}
