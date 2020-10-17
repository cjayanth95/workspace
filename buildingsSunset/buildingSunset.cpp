#include <sstream>
#include <stack>
#include <vector>
using namespace std;

struct BuildingHeight {
  int height;
  int index;
};
vector<int> FindBuildings(istringstream *sin) {
  stack<BuildingHeight> candidates;
  int height;
  int index = 0;
  while (*sin >> height) {
    while (!candidates.empty() && candidates.top().height <= height) {
      candidates.pop();
    }
    candidates.emplace(BuildingHeight{height, index++});
  }
  vector<int> heights;
  while (!candidates.empty()) {
    heights.emplace_back(candidates.top().index);
    candidates.pop();
  }
  return heights;
}
