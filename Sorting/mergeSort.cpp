#include <iostream>
using namespace std;

void merge(int arr[], int const l, int const m, int const r) {
  auto const lArr = m - l + 1;
  auto const rArr = r - m;

  auto tempLeft = new int[lArr], tempRight = new int[rArr];

  for (auto i = 0; i < lArr; i++) {
    tempLeft[i] = arr[l + i];
  }
  for (auto j = 0; j < rArr; j++) {
    tempRight[j] = arr[m + 1 + j];
  }

  auto indexL = 0, indexR = 0;
  int indexMerge = l;

  while (indexL < lArr && indexR < rArr) {
    if (tempLeft[indexL] <= tempRight[indexR]) {
      arr[indexMerge] = tempLeft[indexL];
      indexL++;
    } else {
      arr[indexMerge] = tempRight[indexR];
      indexR++;
    }
    indexMerge++;
  }
  while (indexL < lArr) {
    arr[indexMerge] = tempLeft[indexL];
    indexL++;
    indexMerge++;
  }
  while (indexR < rArr) {
    arr[indexMerge] = tempRight[indexR];
    indexR++;
    indexMerge++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l >= r)
    return;
  auto mid = l + (r - l) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, l, mid, r);
}

void printArray(int arr[], int size) {
  for (auto i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {30, 10, 40, 90, 50, 80, 60, 70};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Before Merge Sort:" << endl;
  printArray(arr, n);
  mergeSort(arr, 0, n - 1);
  cout << "After Merge Sort:" << endl;
  printArray(arr, n);
  return 0;
}
