#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct Star {
  double x;
  double y;
  double z;
  double Distance() const { return sqrt(x * x + y * y + z * z); };
  bool operator<(const Star &s) { return Distance() < s.Distance(); };
  //bool operator>(const Star &s) { return Distance() > s.Distance(); };
};

vector<Star> FindClosestKStars(int k, istringstream *stars) {
  priority_queue<Star, vector<Star>, less<>> max_heap;
  string line;
  while (getline(*stars, line)) {
    stringstream linestream(line);
    array<double, 3> data;
    for (int i = 0; i < 3; i++) {
      string buf;
      getline(linestream, buf, ',');
      data[i] = stod(buf);
    }
    max_heap.emplace(Star{data[0], data[1], data[2]});
    if ((int)max_heap.size() == k + 1) {
      max_heap.pop();
    }
  }
  vector<Star> closestStars;
  while (!max_heap.empty()) {
    closestStars.emplace_back(max_heap.top());
    max_heap.pop();
  }
  reverse(closestStars.begin(), closestStars.end());
  return closestStars;
}

void PrintStars(const vector<Star> &stars) {
  for (Star star : stars) {
    cout << star.x << star.y << star.z << endl;
  }
}
int main() {
  string s = " 1,1,1 \n 2,2,2 \n 3,3,3 \n 1,0,0 \n 3,0,0";
  istringstream ss(s);
  vector<Star> closestStars = FindClosestKStars(2, &ss);
  PrintStars(closestStars);
}
