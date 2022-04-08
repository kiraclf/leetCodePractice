#include <queue>
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
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    queue<Node*> cache;
    cache.push(root);
    while (!cache.empty()) {
      vector<int> levelResult;
      int size = cache.size();
      for (int i = 0; i < size; i++) {
        Node* currentNode = cache.front();
        levelResult.push_back(currentNode->val);
        cache.pop();
        for (auto child : currentNode->children) {
          cache.push(child);
        }
      }
      result.push_back(levelResult);
    }
    return result;
  }
};