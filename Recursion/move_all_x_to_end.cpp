#include <iostream>
#include <string>
using namespace std;

string moveXToEnd(string s) {
  if (s.length() == 0) {
    return "";
  }
  char ch = s[0];
  string ans = moveXToEnd(s.substr(1));

  if (ch == 'x') {
    return ans + ch;
  } else {
    return ch + ans;
  }
}

int main() {
  string s = "abxxcxdyzxloxmxnox";
  cout << moveXToEnd(s) << endl;
  return 0;
}