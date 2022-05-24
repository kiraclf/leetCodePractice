struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    if (root == nullptr) {
      return false;
    }
    return isUnivalNode(root->val, root);
  }

  bool isUnivalNode(int value, TreeNode* current) {
    if (current == nullptr) {
      return true;
    }
    if (value != current->val) {
      return false;
    }
    return isUnivalNode(value, current->left) &&
           isUnivalNode(value, current->right);
  }
};