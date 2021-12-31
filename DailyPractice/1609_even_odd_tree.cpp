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
  bool isEvenOddTree(TreeNode *root) {
    bool isOdd = true;
    vector<TreeNode *> levelVec;
    levelVec.push_back(root);
    while (levelVec.size() != 0) {
      int before = 0;
      for (int i = 0; i < levelVec.size(); i++) {
        int value = levelVec[i]->val;
        // odd and even check
        if (isOdd && value % 2 == 0) {
          return false;
        } else if (!isOdd && value % 2 != 0) {
          return false;
        }
        // compare check
        if (i == 0) {
          before = value;
        } else {
          // odd increase
          if (isOdd && value <= before) {
            return false;
          }
          // even decrease
          if (!isOdd && value >= before) {
            return false;
          }
          before = value;
        }
      }
      // next level
      isOdd = !isOdd;
      int currentSize = levelVec.size();
      for (int i = 0; i < currentSize; i++) {
        if (levelVec[i]->left != nullptr) {
          levelVec.push_back(levelVec[i]->left);
        }
        if (levelVec[i]->right != nullptr) {
          levelVec.push_back(levelVec[i]->right);
        }
      }
      levelVec.erase(levelVec.begin(), levelVec.begin() + currentSize);
    }
    return true;
  }
};

int main() {
  vector<TreeNode *> nodes;
  for (int i = 0; i <= 12; i++) {
    TreeNode *node = new TreeNode(i);
    nodes.push_back(node);
  }
  nodes[1]->left = nodes[10];
  nodes[1]->right = nodes[4];
  nodes[10]->left = nodes[3];
  nodes[4]->left = nodes[7];
  nodes[4]->right = nodes[9];
  nodes[3]->left = nodes[12];
  nodes[3]->right = nodes[8];
  nodes[7]->left = nodes[6];
  nodes[9]->right = nodes[2];
  TreeNode *root = nodes[1];
  Solution solve;
  bool res = solve.isEvenOddTree(root);
  return 0;
}