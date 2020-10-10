#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

struct Student {
  double GPA;
  string name;
};

const static function<bool(const Student &, const Student &)> compareGPA =
    [](const Student &a, const Student &b) -> bool {
  if (a.GPA != b.GPA) {
    return a.GPA > b.GPA;
  } else
    return a.name > b.name;
};

bool SearchStudent(
    vector<Student> &students, Student &target,
    const function<bool(const Student &, const Student &)> &compGPA) {
  return binary_search(students.begin(), students.end(), target, compGPA);
}

int main() {
  Student s1{4.0, "Jayanth"};
  Student s3{4.0, "Sumanth"};
  Student s2{3.9, "Sumanth"};
  vector<Student> students = {s1, s2};
  bool search = SearchStudent(students, s3, compareGPA);
  cout << search << endl;
  return 0;
}
