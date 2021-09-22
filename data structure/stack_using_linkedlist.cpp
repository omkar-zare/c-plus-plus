#include <iostream>

struct node {
  int val;
  node *next;
};
node *head;

void push(int x) {
  node *n = new node();
  n->val = x;
  n->next = head;
  head = n;
}

void pop() {
  if (head == NULL) {
    std::cout << "Underflow!!" << std::endl;
  } else {
    node *t = new node();
    t = head;
    std::cout << "Element " << t->val << " deleted!!!" << std::endl;
    head = head->next;
    delete t;
  }
}

void show() {
  node *t = new node();
  t = head;
  while (t != NULL) {
    std::cout << t->val << " ";
    t = t->next;
  }
}
int main() {
  int ch, x;
  do {
    std::cout << std::endl
              << "1.push" << std::endl
              << "2.pop" << std::endl
              << "3.show" << std::endl
              << "4.exit" << std::endl;
    std::cout << "Enter the choice:";
    std::cin >> ch;
    switch (ch) {
    case 1:
      std::cout << std::endl << "Enter the element:";
      std::cin >> x;
      push(x);
      break;
    case 2:
      pop();
      break;
    case 3:
      show();
      break;
    case 4:
      exit(0);
    default:
      std::cout << "Enter the valid choice!!!" << std::endl;
      break;
    }
  } while (ch != 4);
  return 0;
}
