#include <iostream>
using namespace std;

int *stack;
int stack_size, stack_indx = 0;

void push(int x) {
  if (stack_indx == stack_size) {
    cout << "Overflow!!!" << endl;
  } else {
    stack[stack_indx++] = x;
  }
}
void pop() {
  if (stack_indx == 0) {
    cout << "Underflow!!!" << endl;
  } else {
    cout << stack[--stack_indx] << " Deleted!" << endl;
  }
}

void show() {
  for (int i = 0; i <= stack_indx - 1; i++) {
    cout << stack[i] << " ";
  }
}

int main() {
  cout << "Enter the stack size: ";
  cin >> stack_size;
  stack = new int[stack_size];
  int ch;

  do {
    cout << endl
         << "1.push" << endl
         << "2.pop" << endl
         << "3.show" << endl
         << "4.Exit" << endl;
    cout << "Enter the choice:";
    cin >> ch;
    switch (ch) {
    case 1:
      int ele;
      cout << endl << "Insert Element:";
      cin >> ele;
      push(ele);
      break;
    case 2:
      pop();
      break;
    case 3:
      show();
      break;
    default:
      cout << "Invalid Choice!!";
      break;
    }
  } while (ch != 4);
  return 0;
}
