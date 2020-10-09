#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

auto cmp = [](string &left, string &right) {
  return left.size() >= right.size();
};
vector<string> TopK(int K, istringstream *stream) {
  priority_queue<string, vector<string>, decltype(cmp)> min_heap(cmp);
  string next_string;
  while (*stream >> next_string) {
    min_heap.emplace(next_string);
    if ((int)min_heap.size() > K)
      min_heap.pop();
  }
  vector<string> result;
  while (!min_heap.empty()) {
    result.emplace_back(min_heap.top());
    min_heap.pop();
  }
  return result;
}
void printVector(const vector<string> &str) {
  int size = (int)str.size();
  for (int i = 0; i < size; i++) {
    cout << str[i] << endl;
  }
};
int main() {
  int K = 7;
  string str("Happy emplace Hello world sdfasd a  sdfasdf  asdf "
             "asdfasdfjasldjkf alsjdflaksjdl fkjas ld kjfal;sdkjf "
             "la;skdjfl;aksjdlfkasjdlfkjalsdkjfalk;sdjfasdf asdf asdfljaslkdjf "
             "asdfa sdf asdf asdf asdfasdf asdfasdfasdf adf");
  istringstream s(str);
  vector<string> res = TopK(K, &s);
  printVector(res);
  return 0;
}
