#include <iostream>
using namespace std;

void towerOfHanoi(int n, char src, char des, char help) {
  if (n == 0) {
    return;
  }
  towerOfHanoi(n - 1, src, help, des);
  cout << "Move from " << src << " to " << des << endl;
  towerOfHanoi(n - 1, help, des, src);
}

int main() {

  towerOfHanoi(3, 'S', 'D', 'H');
  return 0;
}