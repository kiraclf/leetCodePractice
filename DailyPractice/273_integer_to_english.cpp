#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  string numberToWords(int num) {
    string res = "";
    vector<int> numberList;
    int currentStep = 0;
    if (num == 0) {
      return "Zero";
    }
    while (num != 0) {
      int current = num % 10;
      num = num / 10;
      numberList.push_back(current);
      if (numberList.size() == 3) {
        // process
        processThreePairs(numberList, currentStep, res);
      }
      currentStep += 1;
    }
    if (numberList.size() != 0) {
      // process
      currentStep -= 1;
      processThreePairs(numberList, currentStep, res);
    }
    res.pop_back();
    return res;
  }

  void processThreePairs(vector<int>& digit, int weight, string& res) {
    unordered_map<int, string> singleEngMap = {
        {0, ""}, {1, "One "}, {2, "Two "},   {3, "Three "}, {4, "Four "},
        {5, "Five "}, {6, "Six "}, {7, "Seven "}, {8, "Eight "}, {9, "Nine "},
    };
    unordered_map<int, string> secondEngMap = {
        {0, ""},
        {10, "Ten "},      {11, "Eleven "},   {12, "Twelve "},  {13, "Thirteen "},
        {14, "Fourteen "}, {15, "Fifteen "},  {16, "Sixteen "}, {17, "Seventeen "},
        {18, "Eighteen "}, {19, "Nineteen "}, {20, "Twenty "},  {30, "Thirty "},
        {40, "Forty "},    {50, "Fifty "},    {60, "Sixty "},   {70, "Seventy "},
        {80, "Eighty "},   {90, "ninety "},
    };
    unordered_map<int, string> holderMap = {{0, ""},        {1, ""},
                                            {2, "Hundard "}, {3, "Thousand "},
                                            {6, "Million "}, {9, "Billion "}};
    // 确定进位
    int value = 0;
    for (int i = 0; i < digit.size(); i++) {
      if (i == 0) {
        value = value + digit[i];
      } else if ( i == 1 ) {
        value = value + digit[i] * 10;
      } else {
        value = value + digit[i] * 100;
      }
    }
    if (value == 0) {
      digit.clear();
      return;
    }
    if (weight >= 3 && weight < 6) {
      res.insert(0, holderMap[3]);
    } else if (weight >= 6 && weight < 9) {
      res.insert(0, holderMap[6]);
    } else if (weight >= 9) {
      res.insert(0, holderMap[9]);
    }
    // 解析数字
    if (digit.size() == 1) {
      res.insert(0, singleEngMap[digit[0]]);
    } else if (digit.size() == 2) {
      if (digit[1] == 1) {
        int twoNumber = digit[1] * 10 + digit[0];
        res.insert(0, secondEngMap[twoNumber]);
      } else {
        res.insert(0, secondEngMap[digit[1] * 10] + singleEngMap[digit[0]]);
      }
    } else {
      if (digit[1] == 1) {
        int twoNumber = digit[1] * 10 + digit[0];
        res.insert(0, secondEngMap[twoNumber]);
      } else {
        res.insert(0, secondEngMap[digit[1] * 10] + singleEngMap[digit[0]]);
      }
      if (digit[2] != 0) {
        res.insert(0, singleEngMap[digit[2]] + "Hundard ");
      }
    }
    digit.clear();
  }
};

int main() {
  Solution solve;
  string res = solve.numberToWords(1234567891);
  return 0;
}