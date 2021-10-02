#include <iostream>
using namespace std;

int first_occ(int arr[], int n, int i, int key) {
  if (i == n) {
    return -1;
  }
  if (arr[i] == key) {
    return i;
  }
  return first_occ(arr, n, i + 1, key);
}
int last_occ(int arr[], int n, int i, int key) {
  if (i == 0) {
    return -1;
  }
  if (arr[i] == key) {
    return i;
  }
  return last_occ(arr, n, i - 1, key);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 1;
  int f = first_occ(arr, n, 0, key);
  if (f != -1) {
    cout << key << "'s first occurence is at position: " << f << endl;
  } else {
    cout << key << "no occrence found!!" << endl;
  }
  int l = last_occ(arr, n, n - 1, key);
  if (l != -1) {
    cout << key << "'s Last occurence is at position: " << l << endl;
  } else {
    cout << key << "no occurence found!!" << endl;
  }
}
