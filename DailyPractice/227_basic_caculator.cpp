#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
/*
--- 题目描述 ---
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
整数除法仅保留整数部分。
--- 思路 ---
3 + 2 * 2
1. 3 入数栈 
2. + 入操作符栈
3. 2 入数栈
4. * 入操作符栈
5. 2 入栈
查看栈顶是否为 (*或者/)
  如果是 
*/

class Solution {
 public:
  int calculate(string s) {
    int startIndex = 0;
    // 1 + , 2 -, 3 * ,4 /
    vector<int> operationCache;
    vector<int> numberSet;
    unordered_set<char> operationSet = {'+', '-', '*', '/', ' '};
    int currentValue = 0;
    while (startIndex < s.length()) {
      char current = s[startIndex];
      if (current == '+') {
        operationCache.push_back(1);
        startIndex++;
        continue;
      }
      if (current == '-') {
        operationCache.push_back(2);
        startIndex++;
        continue;
      }
      if (current == '*') {
        operationCache.push_back(3);
        startIndex++;
        continue;
      }
      if (current == '/') {
        operationCache.push_back(4);
        startIndex++;
        continue;
      }
      if (current == ' ') {
        startIndex++;
        continue;
      }
      int currentValue = 0;
      while (startIndex < s.length() && operationSet.find(s[startIndex]) == operationSet.end()) {
        int digitValue = s[startIndex] - '0';
        currentValue = currentValue * 10 + digitValue;
        startIndex++;
      }
      if (operationCache.size() == 0) {
        numberSet.push_back(currentValue);
        continue;
      }
      int operationBack = operationCache.back();
      if (operationBack <= 2) {
        numberSet.push_back(currentValue);
        continue;
      } else if (operationBack == 3) {
        // 乘
        currentValue = currentValue * numberSet.back();
        numberSet.pop_back();
        operationCache.pop_back();
        numberSet.push_back(currentValue);
      } else {
        // 除
        currentValue = numberSet.back() / currentValue;
        numberSet.pop_back();
        operationCache.pop_back();
        numberSet.push_back(currentValue);
      }
    }
    int result = 0;
    while (numberSet.size() > 0) {
      if (operationCache.size() == 0) {
        result += numberSet.back();
      } else {
        int backOperation = operationCache.back();
        if (backOperation == 1) {
          result += numberSet.back();
        } else {
          result -= numberSet.back();
        }
        operationCache.pop_back();
      }
      numberSet.pop_back();
    }
    return result;
  }
};

int main() {
  Solution solve;
  int result = solve.calculate("1-1");
  return 0;
}