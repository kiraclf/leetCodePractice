#include <vector>
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
  int findBottomLeftValue(TreeNode *root) {
    return findValue(root, 0).first;
  }
  // value, depth
  pair<int,int> findValue(TreeNode * node, int depth) {
    if (node->left == nullptr && node->right == nullptr) {
      return {node->val, depth};
    }
    pair<int, int> res = {0, 0};
    if (node->left) {
      auto leftAns = findValue(node->left, depth+ 1);
      if (res.second < leftAns.second) {
        res = leftAns;
      }
    }
    if (node->right) {
      auto rightAns = findValue(node->right, depth + 1);
      if (res.second < rightAns.second) {
        res = rightAns;
      }
    }
    return res;
  }
};