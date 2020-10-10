class Foo {
public:
  int x;
  int get() { return x; }
  const int &get2() const { return x; }
  // This is also allowed
  // const int &get() const { return x; } ;
};

int main() {
  Foo foo1{5};
  int f1 = foo1.get(); // allowed
  const Foo foo2{10};
  int f2 = foo2.get2(); // foo2.get() is not allowed
}
