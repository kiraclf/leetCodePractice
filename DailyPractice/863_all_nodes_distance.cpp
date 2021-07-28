#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  unordered_map<int, TreeNode*> parents;
  vector<int> ans;

  void findParents(TreeNode* node) {
    if (node->left != nullptr) {
      parents[node->left->val] = node;
      findParents(node->left);
    }
    if (node->right != nullptr) {
      parents[node->right->val] = node;
      findParents(node->right);
    }
  }

  void findAns(TreeNode* node, TreeNode* from, int depth, int k) {
    if (node == nullptr) {
      return;
    }
    if (depth == k) {
      ans.push_back(node->val);
      return;
    }
    if (node->left != from) {
      findAns(node->left, node, depth + 1, k);
    }
    if (node->right != from) {
      findAns(node->right, node, depth + 1, k);
    }
    if (parents[node->val] != from) {
      findAns(parents[node->val], node, depth + 1, k);
    }
  }

 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    // 从 root 出发 DFS，记录每个结点的父结点
    findParents(root);

    // 从 target 出发 DFS，寻找所有深度为 k 的结点
    findAns(target, nullptr, 0, k);

    return ans;
  }
};

int main() {
  Solution solve;
  TreeNode* root = new TreeNode(3);
  TreeNode* next1 = new TreeNode(5);
  TreeNode* next2 = new TreeNode(1);
  TreeNode* next3 = new TreeNode(6);
  TreeNode* next4 = new TreeNode(2);
  TreeNode* next5 = new TreeNode(0);
  TreeNode* next6 = new TreeNode(8);
  TreeNode* next7 = new TreeNode(7);
  TreeNode* next8 = new TreeNode(4);
  root->left = next1;
  root->right = next2;
  next1->left = next3;
  next1->right = next4;
  next2->left = next5;
  next2->right = next6;
  next4->left = next7;
  next4->right = next8;
  vector<int> res = solve.distanceK(root, next1, 2);  
  return 0;
}