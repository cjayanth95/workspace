#include <iostream>
#include <string>
using namespace std;
int main() {
  char c = 'H';
  char *a = &c;
  char **b = &a;
  cout << c << endl;
  cout << a << endl;
  cout << b << endl;
}
