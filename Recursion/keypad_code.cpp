// possible words from phone digits eg: 1='./' 2='abc' 3='def'...etc
// eg: input :2 3
//    output:ad,ae,af,bd,be,bf,cd,ce,cf
#include <iostream>
#include <string>
using namespace std;

string arr[] = {"",    "./",  "abc",  "def", "ghi",
                "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans) {
  if (s.length() == 0) {
    cout << "{" << ans << "}";
    return;
  }
  char ch = s[0];
  string code = arr[ch - '0'];
  string ros = s.substr(1);
  for (int i = 0; i < code.length(); i++) {
    keypad(ros, ans + code[i]);
  }
}

int main() {

  keypad("123", "");
  return 0;
}