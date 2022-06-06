#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  // 保存边
  unordered_map<char, vector<char>> edges;
  // 入度
  unordered_map<char, int> indegress;
  bool valid = true;
  string alienOrder(vector<string>& words) {
    int length = words.size();
    for (auto word : words) {
      int wordLength = word.size();
      for (int j = 0; j < wordLength; j++) {
        char c = word[j];
        edges[c] = vector<char>();
      }
    }
    for (int i = 1; i < length && valid; i++) {
    }
    if (!valid) {
      return "";
    }
    queue<char> qu;
    // 将 入度 为 0 的放入 queue 中
    for (auto pair : edges) {
      if (!indegress.count(pair.first)) {
        qu.emplace(pair.first);
      }
    }
    string order;
    while (!qu.empty()) {
      char u = qu.front();
      qu.pop();
      order.push_back(u);
      for (char v : edges[u]) {
        indegress[v]--;
        if (indegress[v] == 0) {
          qu.emplace(v);
        }
      }
    }
    return order.size() == edges.size() ? order : "";
  }

  void addEdge(string before, string after) {
    int length1 = before.size(), length2 = after.size();
    int length = min(length1, length2);
    int index = 0;
    while (index < length) {
      char c1 = before[index], c2 = after[index];
      if (c1 != c2) {
        edges[c1].emplace_back(c2);
        indegress[c2] += 1;
        break;
      }
      index++;
    }
    if (index == length && length1 > length2) {
      valid = false;
    }
  }
};