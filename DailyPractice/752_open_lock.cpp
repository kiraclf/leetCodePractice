#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 private:
  string targetString;
  string startString;
  unordered_set<string> deadStrings;

 public:
  int openLock(vector<string>& deadends, string target) {
    // init
    targetString = target;
    startString = "0000";
    // dead strings init
    unordered_set<string> deadCache;
    for (auto dead : deadends) {
      deadCache.insert(dead);
    }
    deadStrings = deadCache;
    // exception
    if (startString == targetString) {
      return 0;
    }
    if (deadCache.find(startString) != deadCache.end()) {
      return -1;
    }
    // Bfs
    int ans = bfs();
    return ans;
  }

  int bfs() {
    // 从前面开始的 DFS 参数准备
    vector<string> startQueue;
    // 记录从前开始到s的转换次数
    unordered_map<string, int> startRoundMap;
    // 从后面的 DFS 参数准备
    vector<string> backQueue;
    // 记录从后开始到s的转换次数
    unordered_map<string ,int> backRoundMap;

    // 将开头和结尾分别放入对应的queue中
    startQueue.push_back(startString);
    startRoundMap[startString] = 0;
    backQueue.push_back(targetString);
    backRoundMap[targetString] = 0;

    // 只有两个队列都不空,才有必要继续搜索,否则无法搜索到
    while (!startQueue.empty() && !backQueue.empty()) {
      int round = -1;
      if (startQueue.size() < backQueue.size()) {
        round = update(startQueue, startRoundMap, backRoundMap);
      } else {
        round = update(backQueue, backRoundMap, startRoundMap);
      }
      if (round != -1) return round;
    }
    return -1;
  }

  int update(
    vector<string> &queue, 
    unordered_map<string ,int> &currentRoundMap, 
    unordered_map<string, int> &otherRoundMap
    ) {
      string firstString = queue.front();
      queue.erase(queue.begin());
      int step = currentRoundMap[firstString];
      for (int i = 0; i < 4; i++) {
        // 每次只能转动一个,因此为 +1 或者 -1
        for (int j = -1; j <= 1; j++) {
          // 产生变化的string
          if (j == 0) continue;
          int originValue = firstString[i] - '0';
          int nextValue = (originValue + j) % 10;
          if (nextValue == -1) { nextValue = 9; }
          char nextChar = (char)(nextValue + '0');
          firstString[i] = nextChar;
          // 判断合法性
          if (deadStrings.find(firstString) != deadStrings.end()) {
            firstString[i] = (char)(originValue + '0');
            continue; // 非法字符
          }
          if (currentRoundMap.find(firstString) != currentRoundMap.end()) {
            firstString[i] = (char)(originValue + '0');
            continue; // 重复字符
          }
          // 寻找另一端
          if (otherRoundMap.find(firstString) != otherRoundMap.end()) {
            return step + 1 + otherRoundMap[firstString];
          } else {
            queue.push_back(firstString);
            currentRoundMap[firstString] = step + 1;
            firstString[i] = (char)(originValue + '0');
          }
        }
      }
      return -1;
    }
};

int main() {
  vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
  Solution solve;
  int result = solve.openLock(deadends, "0202");
  return 0;
}