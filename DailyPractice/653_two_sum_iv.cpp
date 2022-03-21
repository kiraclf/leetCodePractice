#include <unordered_set>
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
 public:
  bool findTarget(TreeNode *root, int k) {
    bool res = false;
    unordered_set<int> cache;
    dfs(root, k, cache, res);
    return res;
  }

  void dfs(TreeNode *node, int k, unordered_set<int> &cache, bool &result) {
    if (result || node == nullptr) {
      return;
    }
    dfs(node->left, k, cache, result);
    int target = k - node->val;
    if (cache.find(target) != cache.end()) {
      result = true;
    }
    cache.insert(node->val);
    dfs(node->right, k, cache, result);
  }
};