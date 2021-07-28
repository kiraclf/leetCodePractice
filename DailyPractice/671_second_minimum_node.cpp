using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int findSecondMinimumValue(TreeNode *root) {
    int smallest = root->val;
    if (root->left == nullptr) {
      return -1;
    }
    int secondSmallest = -1;
    dfs(root, smallest, secondSmallest);
    return secondSmallest;
  }

  void dfs(TreeNode * current, int smallest, int &second) {
    if (current == nullptr) {
      return;
    }
    if (current->val == smallest) {
      dfs(current->left, smallest, second);
      dfs(current->right, smallest, second);
    } else {
      if (second == -1) {
        second = current->val;
      } else {
        second = second > current->val ? current->val : second;
      }
    }
  }
};
