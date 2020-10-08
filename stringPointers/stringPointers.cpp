#include <iostream>
#include <string>

using namespace std;

int main() {
  const char *foo = "Hello";
  cout << *foo << endl;
  cout << *(foo + 4) << endl;
  cout << foo[4] << endl;
}
