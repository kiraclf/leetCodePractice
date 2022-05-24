#include <vector>
using namespace std;
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }
};

class Solution {
 public:
  Node* construct(vector<vector<int>>& grid) {
    vector<pair<Node*, int>> cache;
    int x = 0;
    int y = 0;
    while (y >= 0 && y < grid.size() && x >= 0 && x < grid[0].size()) {
      Node* currentNode = new Node();
      currentNode->isLeaf = true;
      currentNode->val = grid[y][x];
      cache.push_back({currentNode, 1});
    }
    if (cache.size() != 0) {
      return cache[0].first;
    }
    // will not enter
    return nullptr;
  }
};