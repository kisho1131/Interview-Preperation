#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
void markParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent) {
  if (root == NULL)
    return;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *currentNode = q.front();
    q.pop();
    if (currentNode->left) {
      mp[currentNode->left] = currentNode;
      q.push(currentNode->left);
    }
    if (currentNode->right) {
      mp[currentNode->right] = currentNode;
      q.push(currentNode->right);
    }
  }
}

int TimetoBurnTree(TreeNode *root, TreeNode *target) {
  if (root == NULL)
    return 0;
  urordered_map<TreeNode *, bool> visited;
  queue<TreeNode *> q;
  q.push(target);
  visite[target] = true;
  unordered_map<TreeNode *, TreeNode *> parent;
  markParent(root, parent);
  int time = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int f1 = 0;
      TreeNode *node = q.front();
      // for the left side
      if (node->left and !visited[node->left]) {
        f1 = 1;
        visited[node->left] = true;
        q.push(node->left);
      }
      // for the right side
      if (node->right and !visited[node->right]) {
        f1 = 1;
        visited[node->right] = true;
        q.push(node->right);
      }
      // for the parent or upward side
      if (parent[node] and !visited[parent[node]]) {
        f1 = 1;
        visited[parent[node]] = true;
        q.push(parent[node]);
      }
    }
    if (fl)
      time++;
  }
  return time;
}

/* =========================== Main() =========================== */
int main() {
  Function();
  cout << endl;
  return 0;
}
