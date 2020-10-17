#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int evaluateRPN(const string &RPN_expression) {
  stack<int> intermediate_result;
  stringstream ss(RPN_expression);
  string token;
  const char delimiter = ',';
  while (getline(ss, token, delimiter)) {
    if (token == "+" || token == "-" || token == "/" || token == "x") {
      int y = intermediate_result.top();
      intermediate_result.pop();
      int x = intermediate_result.top();
      intermediate_result.pop();
      if (token == "+") {
        intermediate_result.emplace(x + y);
      } else if (token == "-") {
        intermediate_result.emplace(x - y);
      } else if (token == "/") {
        intermediate_result.emplace(x / y);
      } else if (token == "x") {
        intermediate_result.emplace(x * y);
      }
    } else {
      intermediate_result.emplace(stoi(token));
    }
  }
  return intermediate_result.top();
}

int main() {
  const string rpn = "3,4,+,2,x,1,+";
  int eval = evaluateRPN(rpn);
  cout << eval << endl;
}
