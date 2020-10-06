#include <string>
#include <iostream>
using namespace std;
void f( string &str) { str += "abc"; }
int main() {
  string i = "abc";
  f(i);
  cout<<i<<endl;
}
