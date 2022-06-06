struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int sumRootToLeaf(TreeNode *root) { return dfsSum(root, 0); }

  int dfsSum(TreeNode *current, int value) {
    if (current->left == nullptr && current->right == nullptr) {
      // leaf node
      return value + current->val;
    }
    // tree node
    int res = 0;
    if (current->left != nullptr) {
      res += dfsSum(current->left, (value + current->val) << 1);
    }
    if (current->right != nullptr) {
      res += dfsSum(current->right, (value + current->val) << 1);
    }
    return res;
  }
};