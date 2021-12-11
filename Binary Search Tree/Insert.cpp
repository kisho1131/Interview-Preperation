#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

Node *InsertIntoBST(Node *root, int value) {
  if (root == NULL)
    return newNode(value);
  if (value < root->data) {
    root->left = InsertIntoBST(root->left, value);
  } else {
    root->right = InsertIntoBST(root->right, value);
  }
  return root;
}

/* =========================== Main() =========================== */
int main() {
  Function();
  cout << endl;
  return 0;
}
