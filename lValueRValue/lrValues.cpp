#include <iostream>
using namespace std;
int main() {
  int firstValue = 10;
  int secondValue = 15;
  int *p1 = &firstValue;
  int *p2 = &secondValue;
  *p1 = 12; // dereference operator. Not to be confused by int*
  *p2 = *p1;
  p1 = p2;
  *p1 = 20;
  // cout << p1 << endl;
  // cout << p2 << endl;
  // cout << firstValue << endl;
  // cout << secondValue << endl;
  int numbers[5];
  int *p;
  p = numbers;
  *p = 11;
  p++;
  *p = 21;
  p = &(numbers[2]);
  *p = 31;
  p = numbers + 3;
  *p = 41;
  p = numbers;
  *(p + 4) = 51;
  // for (int i : numbers)
  // cout << i << endl;
  char charVal = 'a';
  int intVal = 10;
  long longVal = 10;
  char *pchar = &charVal;
  int *pint = &intVal;
  long *plong = &longVal;
  cout << pchar << endl;
  cout << ++pchar << endl;
  cout << sizeof(pchar) << endl;
  cout << pint << endl;
  cout << sizeof(pint) << endl;
  cout << pint++ << endl;
  cout << plong << endl;
  cout << ++plong << endl;
  cout << sizeof(plong) << endl;
  // post fix operators like ++ have higher precedence compared to pre fix
  // operators like *
  //
}
