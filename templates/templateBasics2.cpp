//
// class templates
//
#include <iostream>
using namespace std;

template <class T> class my_pair {
private:
  T a;
  T b;

public:
  my_pair(T first, T second) : a(first), b(second) {}
  T getMax();
};

template <class T> T my_pair<T>::getMax() { return a > b ? a : b; }

// template specialization

template <class T> class mycontainer {
  T a;

public:
  mycontainer(T arg) : a(arg) {}
  T increase() { return ++a; }
};

template <> class mycontainer<char> {
  char element;

public:
  mycontainer(char c) : element(c) {}
  char upperCase() {
    if (element >= 'a' && element <= 'z')
      element += 'A' - 'a';
    return element;
  }
};
int main() {
  my_pair<int> pair1{2, 3};
  int max1 = pair1.getMax();
  std::cout << max1 << std::endl;
  mycontainer<char> mc1 = mycontainer<char>('b');
  char uc1 = mc1.upperCase();
  mycontainer<int> mc2 = mycontainer<int>(2);
  int uc2 = mc2.increase();
  cout << uc1 << endl;
  cout << uc2 << endl;
}
