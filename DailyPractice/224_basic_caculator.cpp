#include <string>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;
/*
--- 题目描述 ---
实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。
"1 + 1"
"2 - 1 + 1"
"(1 + (4 + 5 + 2) - 3)+(6+8)"
--- 思路 ---
1. 字符串扫描成数组
2. 使用栈进行运算
--- 官方题解 ---
使用栈来记录当前的操作符,然后进行计算
先直接展开再进行计算
*/
class Solution {
 public:
  int calculate(string s) {
    vector<string> characterList;
    generateStringList(s, characterList);
    return caculateStringList(characterList);
  }

  void generateStringList(string s, vector<string>& list) {
    string temp = "";
    unordered_set<char> operationSet = {'+', '-', '(', ')'};
    for (int i = 0; i < s.length(); i++) {
      char current = s[i];
      if (operationSet.find(current) != operationSet.end()) {
        // operation
        if (temp.length() > 0) {
          list.push_back(temp);
          temp = "";
        }
        list.push_back(string(1, current));
      } else if (current == ' ') {
        // white space
        if (temp.length() > 0) {
          list.push_back(temp);
          temp = "";
        }
      } else {
        // number
        temp += current;
      }
    }
    if (temp.length() > 0) {
      list.push_back(temp);
    }
  }

  int caculateStringList(vector<string>& list) {
    vector<string> stack;
    int result = 0;
    for (auto value : list) {
      if (value == "(" || value == "+" || value == "-") {
        stack.push_back(value);
      } else if (value == ")") {
        // caculate current
        int currentResult =  caculateParentheis(stack);
        stack.push_back(to_string(currentResult));
      } else {
        // number
        stack.push_back(value);
      }
    }
    // empty stack
    result += caculateParentheis(stack);
    return result;
  }

  int caculateParentheis(vector<string>& list) {
    int result = 0;
    int lastValue = 0;
    while (list.size() > 0 && list.back() != "(") {
      string current = list.back();
      if (current == "+") {
        result += lastValue;
        lastValue = 0;
      } else if (current == "-") {
        result -= lastValue;
        lastValue = 0;
      } else {
        int currentValue = atoi(current.c_str());
        lastValue = currentValue;
      }
      list.pop_back();
    }
    if (list.size() > 0 && list.back() == "(") {
      list.pop_back();
    }
    result += lastValue;
    return result;
  }

  int caculate(string s) {
    stack<int> sign;
    sign.push(1);
    int ans = 0, num = 0, op = 1;
    for (char c : s) {
      if (c == ' ') continue;
      if ('0' <= c && c <= '9') {
        num = num * 10 + (c - '0');
        continue;
      }
      ans += op * num;
      num = 0;
      if (c == '+') {
        op = sign.top();
      } else if (c == '-') {
        op = -sign.top();
      } else if (c == '(') {
        sign.push(op);
      } else if (c == ')') {
        sign.pop();
      }
    }
    ans += op * num;
    return ans;
  } 
};

int main() {
  Solution solve;
  int result = solve.calculate("1 + 1");
  return 0;
}