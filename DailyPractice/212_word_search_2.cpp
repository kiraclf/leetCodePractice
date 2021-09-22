#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// trie 树
class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // 创建 boardMap
    unordered_map<char, vector<pair<int, int>>> boradMap;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        boradMap[board[i][j]].push_back(pair<int, int>(i,j));
      }
    }
    // 创建 Trie 树
  }
};

class TrieTree {
  
}