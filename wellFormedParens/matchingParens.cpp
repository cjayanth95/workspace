#include <ctype.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool ValidParens(const string &parens) {
  stack<char> left_chars;
  for (size_t i = 0; i < parens.length(); i++) {
    if (parens[i] == '(' || parens[i] == '{' || parens[i] == '[') {
      left_chars.emplace(parens[i]);
    } else {
      if (left_chars.empty())
        return false;
      char top = left_chars.top();
      if ((top != '(' && parens[i] == ')') ||
          (top != '(' && parens[i] == ')') ||
          (top != '(' && parens[i] == ')')) {
        return false;
      }
      left_chars.pop();
    }
  }
  return left_chars.empty();
}

int main() {
  const string stringparens = "[()[]]";
  bool isValid = ValidParens(stringparens);
  cout << isValid << endl;
  return 0;
}
