#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *left, *right;
  Node(int data) {
    this->val = data;
    left = right = NULL;
  }
};

/* =========================== Function() ======================= */

// |H(left) - H(right)| <= 1 -> Balance Tree
bool isBalanced(Node *root) {
  if (root == NULL)
    return true;
  int left = Height(root->left);
  int right = Height(root->right);
  return abs(left - right) <= 1 && isBalanced(root->left) &&
         isBalanced(root->right);
}

/* Find the left Height, Find the right height check |left - right| <= 1
   && Recurvisely Check for the Left and the Right SubTree if all Return True
   then Return true else return false;
   # Time: O(N^2)
   # Space: O(N)
*/

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

/* =========================== Main() =========================== */
int main() {
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
