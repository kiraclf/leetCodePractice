#include <vector>
using namespace std;
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  int maxDepth(Node* root) { return recursiveMaxDepth(root); }

  int recursiveMaxDepth(Node* node) {
    if (node == nullptr) {
      return 0;
    }
    int maxDepth = 0;
    for (auto child : node->children) {
      maxDepth = max(maxDepth, recursiveMaxDepth(child));
    }
    return maxDepth + 1;
  }
};