#include <iostream>
#include <list>

struct node {
  int val;
  node *left;
  node *right;
};

void createTree(node *curr, node *n, int x, char p) {
  if (n != NULL) {
    char ch;
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
    std::cout << "\nInserted!";
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

void Pre(node *n) {
  if (n != NULL) {
    std::cout << n->val << " ";
    Pre(n->left);
    Pre(n->right);
  }
}

void in(node *n) {
  if (n != NULL) {
    Pre(n->left);
    std::cout << n->val << " ";
    Pre(n->right);
  }
}

void Post(node *n) {
  if (n != NULL) {
    Pre(n->left);
    Pre(n->right);
    std::cout << n->val << " ";
  }
}
int main() {
  int value;
  int ch;
  std::cout << "Enter the Root node Value: ";
  std::cin >> value;
  node *root = new node();
  root->val = value;
  root->left = NULL;
  root->right = NULL;
  do {
    std::cout << "\n1.Insert"
              << "\n2.Breadth First Traverse"
              << "\n3.Pre-Order"
              << "\n4.In-Order"
              << "\n5.Post-Order"
              << "\n6.Exit"
              << "\nEnter the Choice: ";
    std::cin >> ch;

    switch (ch) {
    case 1:
      int x;
      char p;
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
      std::cout << "\n Pre-Order Traversal:";
      Pre(root);
      break;
    case 4:
      std::cout << "\n In-Order Traversal:";
      in(root);
      break;
    case 5:
      std::cout << "\n Post-Order Traversal:";
      Post(root);
      break;
    case 6:
      exit(0);
    default:
      std::cout << "\nInvalid Choice!!";
    }
  } while (ch != 6);
  return 0;
}
