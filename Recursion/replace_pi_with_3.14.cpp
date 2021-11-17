// replace pi with 3.14
// eg: pipppiiipppiiiipi
//    3.14pp3.14iipp3.14iii3.14
#include <iostream>
#include <string>
using namespace std;

void replacePi(string s) {
  if (s.length() == 0) {
    return;
  }
  if (s[0] == 'p' && s[1] == 'i') {
    cout << "3.14";
    replacePi(s.substr(2));
  } else {
    cout << s[0];
    replacePi(s.substr(1));
  }
}

int main() {
  string str = "pipppiiipppiiiipi";
  replacePi(str);

  return 0;
}