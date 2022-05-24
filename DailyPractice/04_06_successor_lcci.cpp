#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    vector<TreeNode*> nodesList;
    int targetIndex;
    dfs(root, nodesList, targetIndex, p->val);
    if (targetIndex + 1 >= nodesList.size()) {
      return nullptr;
    }
    return nodesList[targetIndex + 1];
  }

  void dfs(TreeNode* node, vector<TreeNode*>& list, int& targetIndex,
           int target) {
    if (node == nullptr) {
      return;
    }
    // left
    dfs(node->left, list, targetIndex, target);
    // mid
    list.push_back(node);
    if (node->val == target) {
      targetIndex = list.size() - 1;
    }
    // right
    dfs(node->right, list, targetIndex, target);
  }
};