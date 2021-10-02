#include <iostream>
#include <list>

struct node {
  int val;
  node *left;
  node *right;
};

void createTree(node *curr, node *n, int x, char p) {
  if (n != NULL) {
    char ch = 0;
    std::cout << "\nl(left) or r(right) of " << n->val << " :";
    std::cin >> ch;
    if (ch == 'l') {
      createTree(n, n->left, x, ch);
    } else if (ch == 'r') {
      createTree(n, n->right, x, ch);
    }
  } else {
    node *n1 = new node();
    n1->val = x;
    n1->left = NULL;
    n1->right = NULL;
    if (p == 'l') {
      curr->left = n1;
    } else if (p == 'r') {
      curr->right = n1;
    }
    std::cout << "\ninserted!";
  }
}

void BFT(node *n) {
  std::list<node *> queue;
  queue.push_back(n);
  while (!queue.empty()) {
    n = queue.front();
    std::cout << n->val << " ";
    queue.pop_front();

    if (n->left != NULL) {
      queue.push_back(n->left);
    }
    if (n->right != NULL) {
      queue.push_back(n->right);
    }
  }
}

void pre(node *n) {
  if (n != NULL) {
    std::cout << n->val << " ";
    pre(n->left);
    pre(n->right);
  }
}

void in(node *n) {
  if (n != NULL) {
    pre(n->left);
    std::cout << n->val << " ";
    pre(n->right);
  }
}

void post(node *n) {
  if (n != NULL) {
    pre(n->left);
    pre(n->right);
    std::cout << n->val << " ";
  }
}

int main() {
  int value = 0;
  int ch = 0;
  std::cout << "Enter the Root node Value: ";
  std::cin >> value;
  node *root = new node();
  root->val = value;
  root->left = NULL;
  root->right = NULL;
  do {
    std::cout << "\n1.insert"
              << "\n2.Breadth First Traverse"
              << "\n3.pre-Order"
              << "\n4.in-Order"
              << "\n5.post-Order"
              << "\n0.Exit"
              << "\nEnter the Choice: ";
    std::cin >> ch;

    switch (ch) {
    case 1:
      int x = 0;
      char p = 0;
      std::cout << "\nEnter the value:";
      std::cin >> x;
      std::cout << "\nl(left) or r(right) of the root:";
      std::cin >> p;
      if (p == 'l') {
        createTree(root, root->left, x, p);
      } else {
        createTree(root, root->right, x, p);
      }
      break;
    case 2:
      std::cout << "\n Breadth First Traverse:";
      BFT(root);
      break;
    case 3:
      std::cout << "\n pre-Order Traversal:";
      pre(root);
      break;
    case 4:
      std::cout << "\n in-Order Traversal:";
      in(root);
      break;
    case 5:
      std::cout << "\n post-Order Traversal:";
      post(root);
      break;
    case 0:
      exit(0);
    default:
      std::cout << "\ninvalid Choice!!";
    }
  } while (ch != 0);
  return 0;
}
