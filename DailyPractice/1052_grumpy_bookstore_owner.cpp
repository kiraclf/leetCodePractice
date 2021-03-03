#include <vector>
using namespace std;
/*
今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。

在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] =
1，否则 grumpy[i] = 0。
当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X
分钟不生气，但却只能使用一次。

请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
*/
/*
--- 思路
  1. 设计一个数组,保存每个时刻满意的个数(直接统计最大值)
  2. 连续区间滑动,计算不同区间满意的最大值
  3. 返回最大值
*/

class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    if ( customers.size() != grumpy.size()) {
      // illegal input
      return -1;
    }
    int totalSatisCount = 0;
    for (int i = 0; i < customers.size(); i++) {
      totalSatisCount += customers[i] * (grumpy[i] == 1 ? 0 : 1);
    }
    // sliding window
    int maxCount = totalSatisCount;
    for (int i = 0; i <= customers.size() - X; i++) {
      if (i == 0) {
        // first iteration
        for (int j = i; j < i + X; j++) {
          if (grumpy[j] == 1) {
            totalSatisCount += customers[j];
          }
        }
      } else {
        // normal iteration
        if (grumpy[i-1] == 1) {
          totalSatisCount -= customers[i - 1];
        }
        if (grumpy[i + X - 1] == 1) {
          totalSatisCount += customers[i + X - 1];
        }
      }
      maxCount = max(maxCount, totalSatisCount);
    }
    return maxCount;
  }
};

int main() {
  Solution test;
  vector<int> customers = {1,0,1,2,1,1,7,5};
  vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
  int result = test.maxSatisfied(customers,grumpy, 3);
  return 0;
}