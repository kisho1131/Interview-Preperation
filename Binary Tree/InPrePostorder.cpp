#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

struct Node {
  int val;
  Node *left, *right;
  Node(int data) {
    this->val = data;
    left = right = NULL;
  }
};

/*
void Traversal(Node *root) {
  vector<int> inorder;
  vector<int> preorder;
  vector<int> postorder;
  if (root == NULL)
    return;
  stack<pair<Node *, int>> s;
  s.push({root, 1});
  while (!s.empty()) {
    pair<Node *, int> node = s.top();
    if (node.second == 1) {
      preorder.push_back(node.first->val);
      node.second += 1;
      if (node.first->left) {
        s.push({node.first->left, 1});
      }
    } else if (node.second == 2) {
      inorder.push_back(node.first->val);
      node.second += 1;
      if (node.first->right) {
        s.push({node.first->right, 1});
      }
    } else {
      postorder.push_back(node.first->val);
      s.pop();
    }
  }
  for (auto ele : preorder) {
    cout << ele << " ";
  }
  cout << endl;
  for (auto ele : inorder) {
    cout << ele << " ";
  }
  cout << endl;
  for (auto ele : postorder) {
    cout << ele << " ";
  }
}
*/

int Height(Node *root) {
  if (root == NULL)
    return 0;
  int left = Height(root->left);
  int right = Height(root->right);
  return max(left, right) + 1;
}

int HeightBalance(Node *root) {
  if (root == NULL)
    return 0;
  int left = HeightBalance(root->left);
  if (left == -1)
    return -1;
  int right = HeightBalance(root->right);
  if (right == -1)
    return -1;
  if (abs(left - right) > 1)
    return -1;
  return max(left, right) + 1;
}

// |H(left) - H(right)| <= 1 -> Balance Tree
bool isBalanced(Node *root) {
  if (root == NULL)
    return true;
  int left = Height(root->left);
  int right = Height(root->right);
  return abs(left - right) <= 1 && isBalanced(root->left) &&
         isBalanced(root->right);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  cout << Height(root);
  cout << endl;
  cout << isBalanced(root);
  cout << endl;
  return 0;
}
