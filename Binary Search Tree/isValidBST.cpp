int isBSTUtil(node *node, int min, int max) {
  /* an empty tree is BST */
  if (node == NULL)
    return 1;

  /* false if this node violates
  the min/max constraint */
  if (node->data < min || node->data > max)
    return 0;

  /* otherwise check the subtrees recursively,
  tightening the min or max constraint */
  return isBSTUtil(node->left, min,
                   node->data - 1) && // Allow only distinct values
         isBSTUtil(node->right, node->data + 1,
                   max); // Allow only distinct values
}
