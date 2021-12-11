#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

bool rootToNodePath(TreeNode *root, int node) {
  if (root == NULL)
    return false;
  res.push_back(root->val);
  if (res->val == node)
    return true;
  if (rootToNodePath(root->left, node, res) ||
      rootToNodePath(root->right, node, res))
    return true;
  arr.pop_back();
  return false;
}

/* =========================== Main() =========================== */
int main() {
  Function();
  cout << endl;
  return 0;
}
