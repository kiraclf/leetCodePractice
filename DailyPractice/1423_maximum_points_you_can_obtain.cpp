#include <vector>
using namespace std;
/*
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
你的点数就是你拿到手中的所有卡牌的点数之和。
给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。
---
思路: 因为只可以从开头或者末尾拿一张卡片,因此剩余的一定是连续的 --> (连续长度为 size - h)的最小点数
 */
class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int size = cardPoints.size();
    if (size == 0) {
      return 0;
    }
    int totalSum = 0;
    int windowSum = 0;
    int minimumSum = INT_MAX;
    int start = 0;
    int end = 0;
    int windowSize = size - k;
    // init window
    while (end < windowSize) {
      windowSum += cardPoints[end];
      totalSum += cardPoints[end];
      end++;
    }
    end--;
    // slide window
    while (end < size) {
      // slide window
        if (end != windowSize - 1) {
          windowSum += cardPoints[end];
          // caculate total
          totalSum += cardPoints[end];
        }
        minimumSum = min(windowSum, minimumSum);
        windowSum -= cardPoints[start];
        start++;
        end++;
    }
    return totalSum - minimumSum;
  }
};

int main() {
  vector<int> test = {1,79,80, 1, 1, 1, 200, 1};
  Solution solve;
  int result = solve.maxScore(test, 3);
  return result;
}