#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cache;
int Fibonacci(int n) {
  if (n <= 1)
    return n;
  if (!cache.count(n)) {
    cache[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
  }
  return cache[n];
}
int main() {
  int x = Fibonacci(10);
  cout << x << endl;
  return 1;
}
