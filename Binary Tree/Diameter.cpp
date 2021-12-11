#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
int Diameter(TreeNode *root, int &diameter) {
  if (root == NULL)
    return 0;
  int left = Diameter(root->left, diameter);
  int Right = Diameter(root->right, diameter);
  diameter = max(diameter, left + right);
  return 1 + max(left, right);
}

/* =========================== Main() =========================== */
int main() {
  Function();
  cout << endl;
  return 0;
}
