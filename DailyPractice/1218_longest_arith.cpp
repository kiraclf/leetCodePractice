#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    if (arr.size() == 0) {
      return 0;
    }
    int totalSize = arr.size();
    vector<int> dp(totalSize, 1);
    unordered_map<int, vector<int>> arrNumbers;
    for (int i = 0; i < arr.size(); i++) {
      arrNumbers[arr[i]].push_back(i);
    }
    for (int i = 1; i < dp.size(); i++) {
      int targetNumber = arr[i] - difference;
      if (arrNumbers.find(targetNumber) != arrNumbers.end()) {
        vector<int> indeList = arrNumbers[targetNumber];
        int lastTargetIndex = -1;
        for (int j = indeList.size() - 1; j >= 0; j--) {
          if (indeList[j] < i) {
            lastTargetIndex = indeList[j];
            break;
          }
        }
        if (lastTargetIndex != -1) {
          dp[i] = max(dp[i], dp[lastTargetIndex] + 1);
        }
      }
    }
    int res = 0;
    for (auto dpValue : dp) {
      res = max(res, dpValue);
    }
    return res;
  }
};

int main() {
  vector<int> test = {6, -2, 0, 3, -7, 6, -5, -8};
  Solution solve;
  int res = solve.longestSubsequence(test, -5);
  return 0;
}