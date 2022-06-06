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
  TreeNode *deleteNode(TreeNode *root, int key) {
    // create dummy head.
    TreeNode *dummyHead = new TreeNode(-1);
    dummyHead->left = root;
    // search node
    auto searchRes = findNode(root, dummyHead, key);
    auto searchedNode = searchRes.first;
    auto searhedParent = searchRes.second;
    if (searchedNode != nullptr) {
      // single child update
      if (searchedNode->left == nullptr && searchedNode->right != nullptr) {
        // single right child
        if (searhedParent->left == searchedNode) {
          searhedParent->left = searchedNode->right;
        } else {
          searhedParent->right = searchedNode->right;
        }
      } else if (searchedNode->left != nullptr &&
                 searchedNode->right == nullptr) {
        // single left child
        if (searhedParent->left == searchedNode) {
          searhedParent->left = searchedNode->left;
        } else {
          searhedParent->right = searchedNode->left;
        }
      } else if (searchedNode->left == nullptr &&
                 searchedNode->right == nullptr) {
        if (searhedParent->left == searchedNode) {
          searhedParent->left = nullptr;
        } else {
          searhedParent->right = nullptr;
        }
      } else {
        // two way child
        auto rightSmallestNode =
            rightNodeSmallest(searchedNode->right, searchedNode);
        searchedNode->val = rightSmallestNode.first->val;
        if (rightSmallestNode.second->left == rightSmallestNode.first) {
          rightSmallestNode.second->left = rightSmallestNode.first->right;
        } else {
          rightSmallestNode.second->right = rightSmallestNode.first->right;
        }
      }
    }
    return dummyHead->left;
  }

  pair<TreeNode *, TreeNode *> rightNodeSmallest(TreeNode *node,
                                                 TreeNode *parent) {
    if (node->left == nullptr) {
      return {node, parent};
    } else {
      return rightNodeSmallest(node->left, node);
    }
  }

  // pair<searchNode, parentNode>
  pair<TreeNode *, TreeNode *> findNode(TreeNode *node, TreeNode *parent,
                                        int key) {
    if (node == nullptr) {
      return {nullptr, nullptr};
    }
    if (node->val == key) {
      return {node, parent};
    } else if (node->val < key) {
      return findNode(node->right, node, key);
    } else {
      return findNode(node->left, node, key);
    }
  }
};

int main() {
  Solution solve;
  TreeNode node(0);
  auto res = solve.deleteNode(&node, 0);
  return 0;
}