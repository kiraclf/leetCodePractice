#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
 public:
 /**
  * 思路:
  *   首先以每个 words 为一行
  *   依次合并
  *   重新整理空格
  *   打印
 */
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<vector<string>> wordList;
    unordered_set<int> mergedIndex;
    // key index, value 对应的长度
    unordered_map<int, int> wordCountMap;
    // 初始化 wordList
    for (int i = 0; i < words.size(); i++) {
      wordCountMap[i] = words[i].size();
      wordList.push_back({words[i]});
    }
    // 从开头开始合并
    for (int i = 0; i < wordList.size(); i++) {
      if (mergedIndex.find(i) != mergedIndex.end()) {
        // 该行已经合并
        continue;
      }
      int mergeStartIndex = i + 1;
      while (mergeStartIndex < wordList.size() && (wordCountMap[i] + wordCountMap[mergeStartIndex] + 1 <= maxWidth)) {
        // 可以合并 mergeStartIndex
        wordList[i].push_back(wordList[mergeStartIndex][0]);
        mergedIndex.insert(mergeStartIndex);
        wordCountMap[i] += wordCountMap[mergeStartIndex] + 1;
        mergeStartIndex++;
      }
    }
    // 输出答案
    int addedCount = 0;
    vector<string> ans;
    for (int i = 0; i < wordList.size(); i++) {
      if (mergedIndex.find(i) != mergedIndex.end()) {
        continue;
      }
      if (addedCount + wordList[i].size() == words.size()) {
        // 最后一行
        string current = "";
        for (int j = 0; j < wordList[i].size(); j++) {
          if (j != 0) {
            current += " ";
          }
          current += wordList[i][j];
        }
        while (current.size() < maxWidth) {
          current += " ";
        }
        ans.push_back(current);
        break;
      }
      addedCount += wordList[i].size();
      // 其他行
      int totalCount = 0;
      for (auto string : wordList[i]) {
        totalCount += string.size();
      }
      int spaceCount = maxWidth - totalCount;
      vector<int> spaceCountList(wordList[i].size() - 1, 1);
      spaceCount -= wordList[i].size() - 1;
      int startIndex = 0;
      while (spaceCount > 0 && startIndex < spaceCountList.size()) {
        spaceCountList[startIndex] += 1;
        spaceCount--;
        startIndex++;
        if (startIndex >= spaceCountList.size()) {
          startIndex = 0;
        }
      }
      string current = "";
      for (int j = 0; j < wordList[i].size(); j++) {
        if (j == 0) {
          current += wordList[i][j];
        } else {
          int leadingSpaceCount = spaceCountList[j-1];
          while (leadingSpaceCount > 0) {
            current += " ";
            leadingSpaceCount--;
          }
          current += wordList[i][j];
        }
      }
      while (current.size() < maxWidth) {
        current += " ";
      }
      ans.push_back(current);
    }
    return ans;
  }
};

int main() {
  Solution solve;
  vector<string> test = {"This", "is", "an", "example", "of", "text","justification."};
    vector<string>  ans = solve.fullJustify(test, 16);
  return 0;
}