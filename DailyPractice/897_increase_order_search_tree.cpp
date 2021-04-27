/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <stdio.h>
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

// 引入 dummy head
class Solution {
 private:
  TreeNode *resNode;

 public:
  void inorder(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    inorder(node->left);

    // 在中序遍历的过程中修改节点指向
    resNode->right = node;
    node->left = nullptr;
    resNode = node;

    inorder(node->right);
  }

  TreeNode *increasingBST(TreeNode *root) {
    TreeNode *dummyNode = new TreeNode(-1);
    resNode = dummyNode;
    inorder(root);
    return dummyNode->right;
  }
};

       int
       main() {
  Solution solve;
}