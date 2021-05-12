#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Solution {
 public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> rootALeaf;
    vector<int> rootBLeaf;
    // dfs out put
    dfsGenerateLeaf(root1, rootALeaf);
    dfsGenerateLeaf(root2, rootBLeaf);
    // compare
    if (rootALeaf.size() != rootBLeaf.size()) {
      return false;
    }
    for (int i = 0; i < rootALeaf.size(); i++) {
      if (rootALeaf[i] != rootBLeaf[i]) {
        return false;
      }
    }
    return true;
  }

  void dfsGenerateLeaf(TreeNode* current, vector<int>& output) {
    // terminator
    if (current == nullptr) {
      return;
    }
    // left
    dfsGenerateLeaf(current->left, output);
    // current
    // process
    if (current->left == nullptr && current->right == nullptr) {
      // leaft
      output.push_back(current->val);
    }
    // right
    dfsGenerateLeaf(current->right, output);
  }
};