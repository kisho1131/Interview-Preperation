/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };3.

 */
vector<vector<int>> verticalTraversal(TreeNode *root) {
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;
  pair<TreeNode *, int> pr;
  queue<pair<TreeNode *, int>> q;
  map<int, vector<int>> mp;
  // map<int, int>mp; // for the top and the bottom view
  int maxhl = 0, minhl = 0;
  q.push({root, 0});
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      pair<TreeNode *, int> node = q.front();
      q.pop();
      maxhl = max(maxhl, node.second);
      minhl = min(minhl, node.second);
      mp[node.second].push_back(node.first->val);
      // if(mp.find(node.second) == mp.end()){  /* for the top view */
      //   mp[node.second] = node.first->val;
      // }

      if (node.first->left)
        q.push({node.first->left, node.second - 1});
      if (node.first->right)
        q.push({node.first->right, node.second + 1});
    }
  }
  for (int i = minhl; i <= maxhl; i++) {
    ans.push_back(mp[i]);
  }
  return ans;
}

vector<vector<int>> verticalTraversal(TreeNode *root) {
  vector<vector<int>> ans;
  if (root == NULL)
    return ans;
  queue<pair<TreeNode *, int>> q;
  map<int, vector<int>> mp;
  q.push({root, 0});
  int maxh = 0;
  int minh = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; < size(); i++) {
      pair<TreeNode *, int> node = q.front();
      q.pop();
      minh = min(minh, node.second);
      maxh = max(maxh, node.second);
      mp[node.second].push_back(node.first->val);
      if (node.first->left)
        q.push(node.first->left);
      if (node.first->right)
        q.push(node.first->right);
    }
  }
  for (int i = minh; i <= maxh; i++) {
    ans.push_back(mp[i]);
  }
  return ans;
}
