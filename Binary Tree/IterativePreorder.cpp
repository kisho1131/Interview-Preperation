#include <bits/stdc++.h>
using namespace std;
/* =========================== Function() ======================= */
class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};
vector<int> IrerativePreOrder(TreeNode *root) {
  vector<int> preorder;
  if (root == NULL)
    return preorder;
  stack<TreeNode *> st;
  st.push(root);
  while (!st.empty()) {
    TreeNode *node = st.top();
    st.pop();
    if (node->right)
      st.push(node->right);
    if (node->left)
      st.push(node->left);
    preorder.push_back(node->data);
  }
  return preorder;
}

vector<int> IrerativeInorder(TreeNode *root) {
  vector<int> inorder;
  if (root == NULL)
    return inorder;
  stack<TreeNode *> st;
  TreeNode *node = root;
  while (node != NULL || st.empty() == false) {
    while (node != NULL) { // move towards the left most node
      st.push(node);
      node = node->left;
    }
    node = st.top();
    st.pop();
    inorder.push_back(node->data);
    node = node->right;
  }
  return inorder;
}

vector<int> IrerativePostOrder(TreeNode *root) {
  vector<int> postOrder;
  if (root == NULL)
    return postOrder;
  stack<TreeNode *> s1;
  stack<TreeNode *> s2;
  s1.push(root);
  while (!s1.empty()) {
    TreeNode *node = s1.top();
    s1.pop();
    if (node->left)
      s1.push(node->left);
    if (node->right)
      s1.push(node->right);
    s2.push(node);
  }
  while (!s2.empty()) {
    postOrder.push_back(s2.top()->data);
    s2.pop();
  }
  return postOrder;
}

void Traversal(TreeNode *root) {
  vector<int> pre, post, in;
  if (root == NULL)
    return;
  stack<pair<TreeNode *, int>> s;
  s.push({root, 1});
  while (!s.empty()) {
    auto node = s.top();
    s.pop();
    if (node.second == 1) {
      pre.push_back(node.first->data);
      node.second++;
      s.push(node);
      if (node.first->left)
        s.push({node.first->left, 1});
    }
    if (node.second == 2) {
      in.push_back(node.first->data);
      node.second++;
      s.push(node);
      if (node.first->right)
        s.push({node.first->right, 1});
    }
    if (node.second == 3) {
      post.push_back(node.first->data);
    }
  }
}

/* =========================== Main() =========================== */
int main() {
  TreeNode *root = new TreeNode(30);
  root->left = new TreeNode(45);
  root->right = new TreeNode(67);
  root->left->left = new TreeNode(23);
  root->left->left->right = new TreeNode(57);
  vector<int> pre = IrerativePreOrder(root);
  for (auto ele : pre)
    cout << ele << " ";
  cout << endl;
  vector<int> in = IrerativeInorder(root);
  for (auto ele : in)
    cout << ele << " ";
  cout << endl;
  vector<int> post = IrerativePostOrder(root);
  for (auto ele : post)
    cout << ele << " ";
  cout << endl;
  return 0;
}
