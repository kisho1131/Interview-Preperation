// Given a binary tree and a node called target. Find the minimum time required
// to burn the complete binary tree if the target is set on fire. It is known
// that in 1 second all nodes connected to a given node get burned. That is its
// left child, right child, and parent.
class Solution {
public:
  Node *Parent(Node *root, unordered_map<Node *, Node *> &parent, int target) {
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty()) {
      Node *node = q.front();
      if (node->data == target)
        res = node;
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
    return res;
  }
  int minTime(Node *root, int target) {
    int time = 0;
    if (root == NULL)
      return time;
    unordered_map<Node *, Node *> parent;
    Node *targetNode = Parent(root, parent, target);
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    //   Node *targetNode;
    //   getTargetNode(root, target, targetNode);

    q.push(targetNode);
    visited[targetNode] = true;
    while (!q.empty()) {
      int size = q.size();
      bool flag = false;
      for (int i = 0; i < size; i++) {
        Node *node = q.front();
        q.pop();
        if (node->left and !visited[node->left]) {
          q.push(node->left);
          visited[node->left] = true;
          flag = true;
        }
        if (node->right and !visited[node->right]) {
          q.push(node->right);
          visited[node->right] = true;
          flag = true;
        }
        if (parent[node] and !visited[parent[node]]) {
          q.push(parent[node]);
          visited[parent[node]] = true;
          flag = true;
        }
      }
      if (flag)
        time++;
    }
    return time;
  }
};
