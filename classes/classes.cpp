#include <ios>
#include <iostream>
using namespace std;
class Circle {
  double radius;

public:
  double area() { return 3.14 * radius * radius; };
  double perimeter() { return 2 * radius * 3.14; };
  Circle(double r) { radius = r; };
  Circle();
};
Circle::Circle() : radius(5) {}
class Rectangle {
  int width;
  int height;

public:
  Rectangle();
  Rectangle(int, int); // contructor. Not necessary. Same name as class name. No
                       // return type
  void set_values(int, int);
  int area() { return width * height; }
};
class Cylinder {
  Circle base;
  int height;

public:
  Cylinder(double r, double h)
      : base(r), height(h) {} // initializing circle with radius r
  double area();
};
void Rectangle::set_values(int h, int w) {
  width = w;
  height = h;
}
// constructors are only executed once when new objects of
// this class are created
//  not return type and don't return anything from the function
Rectangle::Rectangle(int h, int w) {
  height = h;
  width = w;
}
Rectangle::Rectangle() {
  width = 5;
  height = 5;
}
int main() {
  Rectangle rect(10, 20);
  Rectangle rectb;
  rect.set_values(10, 20);
  // cout << rectb.area() << endl;
  Circle c;
  Circle c1(10);
  Circle c2 = 20.0;
  Circle c3{30};
  // cout << c2.area() << endl;
  Rectangle rect2(10, 10);
  Rectangle *rect3, *rect4, *rect5;
  rect3 = new Rectangle(10, 10);
  rect4 = &rect2;
  rect5 = new Rectangle[3]{{5, 5}, {2, 2}, {3, 3}};
  cout << rect2.area() << endl;
  cout << rect3->area() << endl;
  cout << rect4->area() << endl;
  cout << rect5[0].area() << endl;
  return 0;
}
