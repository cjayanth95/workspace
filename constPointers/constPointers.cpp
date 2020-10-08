#include <iostream>

using namespace std;

void incrementPointers(int *start, int *end) {
  int i = 10;
  while (start != end) {
    *start = i;
    i++;
    start++;
  }
}

void printPointers(const int *start, const int *end) {
  while (start != end) {
    cout << *(start++) << endl;
  }
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  incrementPointers(arr, arr + 3);
  // printPointers(arr, arr + 3);
  int x = 5;
  int *p1 = &x; //non const pointer to non const int
  const int *p2 = &x;//non const pointer to const int i.e x cannot be modified through p2 
  int *const p3 = &x;//const pointer to non const int i.e p3 cannot be modified by incrementing /decrementing/ reassigning
  const int *const p4 = &x; //const pointer to const int
  cout << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;
  cout << p4 << endl;
}
