/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> leftBound(Node *root) {
  Node *curr = root->left;
  vector<int> left;
  while (curr) {
    if (!isLeaves(curr))
      left.push_back(curr->val);
    if (curr->left)
      curr = curr->left;
    else
      curr = curr->right;
  }
  return left;
}
vector<int> rightBound(Node *root) {
  vector<int> right;
  Node *curr = root->right;
  while (curr) {
    if (!isLeaves(curr))
      right.push_back(curr->val);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }
  return right;
}

void leavesNode(Node *root, vector<int> &leaves) {
  if (root == NULL)
    return;
  leavesNode(root->left, leaves);
  if (isLeaves(root))
    leaves.push_back(root->val);
  leavesNode(root->right, leaves);
}
bool isLeaves(Node *root) {
  if (root->left == NULL && root->right == NULL)
    return true;
  return false;
}
vector<int> traverseBoundary(TreeNode<int> *root) {
  // Write your code here.
  vector<int> ans;
  if (root == NULL)
    return ans;
  vector<int> left = leftBound(root);
  vector<int> right = rightBound(root);
  vector<int> leaves = leavesNode(root);
}
