using namespace std;
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
 private:
  int xNodeHeight = -1;
  int yNodeHeight = -1;
  TreeNode *xParentNode = nullptr;
  TreeNode *yParentNode = nullptr;

 public:
  bool isCousins(TreeNode *root, int x, int y) {
    // recursive treeNode find target element x, element y
    dfs(root, nullptr, 0, x, y);
    // return
    return xNodeHeight == yNodeHeight && xParentNode != yParentNode;
  }

  void dfs(TreeNode *current, TreeNode *before, int level, int x, int y) {
    // terminator
    if (current == nullptr) {
      return;
    }
    if (xNodeHeight != -1 && yNodeHeight != -1) {
      return;
    }
    // process
    if (current->val == x) {
      xNodeHeight = level + 1;
      xParentNode = before;
    } else if (current->val == y) {
      yNodeHeight = level + 1;
      yParentNode = before;
    }
    // down
    dfs(current->left, current, level + 1, x, y);
    dfs(current->right, current, level + 1, x, y);
  }
};