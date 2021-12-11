#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */

vector<vector<int>> spiralOrder(TreeNode *root) {
  vector<vetor<int>> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);
  bool leftToRight = true;
  while (!q.empty()) {
    int size = q.size();
    vetor<int> level;
    for (int i = 0; i < size(); i++) {
      TreeNode *node = q.front();
      q.pop();
      if (node->left)
        q.push(root->left);
      if (node->right)
        q.push(root->right);
      level.push_back(node->data);
    }
    if (!leftToRight) {
      reverse(level.begin(), level.end());
      ans.push_back(level);
    } else {

      ans.push_back(level);
    }
    leftToRight = !leftToRight;
  }
  return ans;
}

/* =========================== Main() =========================== */
int main() {
  Function();
  cout << endl;
  return 0;
}
