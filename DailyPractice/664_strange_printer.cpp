#include <string>
#include <vector>
using namespace std;
/*
有台奇怪的打印机有以下两个特殊要求：

打印机每次只能打印由 同一个字符 组成的序列。
每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
给你一个字符串 s ，你的任务是计算这个打印机打印它需要的最少打印次数。
*/
class Solution {
 public:
  int strangePrinter(string s) {
    // Store index
    int beforeIndex = -1;
    int beforeBeforeIndex = -1;
    vector<int> lastBefore(s.size(), -1);
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i-1]) {
        if (beforeIndex == -1 && beforeBeforeIndex == -1) {
          beforeIndex = i-1;
        } else {
          beforeBeforeIndex = beforeIndex;
          beforeIndex = i-1;
          lastBefore[i] = beforeBeforeIndex;
        }
      } else {
        lastBefore[i] = lastBefore[i-1];
      }
    }
    // Dp array
    vector<int> dpArr(s.size() + 1, 0);
    dpArr[1] = 1; 
    for (int i = 2; i < dpArr.size(); i++) {
      if (s[i-1] == s[i-2]) {
        // same character
        dpArr[i] = dpArr[i-1];
      } else {
        int changeIndex = lastBefore[i-1];
        if (changeIndex == -1) {
          dpArr[i] = dpArr[i-1] + 1;
        } else {
          if (s[i - 1] == s[changeIndex]) {
            dpArr[i] = min(dpArr[i - 1] + 1, dpArr[changeIndex + 1] + 1);
          } else {
            dpArr[i] = dpArr[i - 1] + 1;
          }
        }
      }
    }
    return dpArr[s.size()];
  }
};

int main() {
  Solution solve;
  int result = solve.strangePrinter("aaabbb");
  return 0;
}