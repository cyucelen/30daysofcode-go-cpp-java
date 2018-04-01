#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
class Node {
public:
  int data;
  Node *left, *right;
  Node(int d) {
    data = d;
    left = right = NULL;
  }
};
class Solution {
public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }
      return root;
    }
  }
  void levelOrder(Node *root) {
    queue<Node *> q;
    if (root != NULL) {
      q.push(root);
      while (q.size() > 0) {
        Node *n = q.front();
        cout << n->data << " ";
        q.pop();
        if (n->left != NULL)
          q.push(n->left);
        if (n->right != NULL)
          q.push(n->right);
      }
    }
  }
}; // End of Solution
int main() {
  Solution myTree;
  Node *root = NULL;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }
  myTree.levelOrder(root);
  return 0;
}
