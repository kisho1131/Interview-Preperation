#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
// Function to mark the Parent //
void Parent(Node *root, unordered_map<Node *, Node *> &parent) {
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *node = q.front();
    q.pop();
    if (node->left) {
      parent[node->left] = node;
      q.push(node->left);
    }
    if (node->right) {
      parent[node->right] = node;
      q.push(node->right);
    }
  }
}

vector<int> allNodesAtK(Node *root, Node *target, int k) {
  vectro<int> ans;
  if (root == NULL)
    return ans;
  unordered_map<Node *, Node *> parent;
  Parent(root, parent);
  unordered_map<Node *, bool> visited;
  queue<Node *> q;
  q.push(root);
  visited[root] = true;
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    if (level++ == k)
      break;
    for (int i = 0; i < size; i++) {
      Node *node = q.front();
      q.pop();
      if (node->left and !visited[node->left]) {
        q.push(node->left);
        visite[node->left] = true;
      }
      if (node->right and !visited[node->right]) {
        q.push(node->right);
        visited[node->right] = true;
      }
      if (parent[node] and !visited[parent[node]]) {
        q.push(parent[node]);
        visited[parent[node]] = true;
      }
    }
  }
  while (!q.empty()) {
    ans.push_back(q.front());
    q.pop();
  }
  return ans;
}

/* =========================== Main() =========================== */
int main() {
  Function();
  cout << endl;
  return 0;
}
