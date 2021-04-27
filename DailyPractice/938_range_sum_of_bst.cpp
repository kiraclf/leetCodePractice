struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
 public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    int sum = 0;
    recursiveTreeNode(root, low, high, sum);
    return sum;
  }

  void recursiveTreeNode(TreeNode *current, int low, int high, int &sum) {
    // terminator
    if (current == nullptr) {
      return;
    }
    // process
    int currentValue = current->val;
    if (currentValue >= low && currentValue <= high) {
      // In middle
      sum += currentValue;
      recursiveTreeNode(current->left, low, high, sum);
      recursiveTreeNode(current->right, low, high, sum);
    } else if (currentValue < low) {
      // Less than least, only the right tree
      recursiveTreeNode(current->right, low, high, sum);
    } else {
      // More than largest, only the left tree
      recursiveTreeNode(current->left, low, high, sum);
    }
  }
};