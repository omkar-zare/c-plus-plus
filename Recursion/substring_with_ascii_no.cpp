#include <iostream>
#include <string>
using namespace std;

void subseq(string s, string ans) {
  if (s.length() == 0) {
    cout << "{" << ans << "}";
    return;
  }

  char ch = s[0];
  int code = ch;
  string res = s.substr(1);
  subseq(res, ans);
  subseq(res, ans + ch);
  subseq(res, ans + to_string(code));
}

int main() {
  string s = "AB";
  string a = "";
  subseq(s, a);
  return 0;
}