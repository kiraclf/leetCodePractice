#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  int checkWays(vector<vector<int>>& pairs) {
    unordered_map<int, unordered_set<int>> adj;
    for (auto& p : pairs) {
      adj[p[0]].emplace(p[1]);
      adj[p[1]].emplace(p[0]);
    }
    // check root node exist
    int root = -1;
    for (auto& nodes : adj) {
      int node = nodes.first;
      unordered_set<int> nighbours = nodes.second;
      if (nighbours.size() == adj.size() - 1) {
        root = node;
        break;
      }
    }
    if (root == -1) {
      return 0;
    }
    int res = 1;
    for (auto& nodes : adj) {
      int node = nodes.first;
      unordered_set<int> neighbours = nodes.second;
      if (node == root) {
        continue;
      }
      int currentDegree = neighbours.size();
      int parent = -1;
      int parentDegree = INT_MAX;
      // based on degree to find node's parent
      for (auto& neighbour : neighbours) {
        if (adj[neighbour].size() < parentDegree &&
            adj[neighbour].size() >= currentDegree) {
          parent = neighbour;
          parentDegree = adj[neighbour].size();
        }
      }
      if (parent == -1) {
        return 0;
      }
      // check neighbours if sibling of adj[parent]
      for (auto& neighbour : neighbours) {
        if (neighbour == parent) {
          continue;
        }
        if (!adj[parent].count(neighbour)) {
          return 0;
        }
      }
      // check if can substitute
      if (parentDegree == currentDegree) {
        res = 2;
      }
    }
    return res;
  }
};