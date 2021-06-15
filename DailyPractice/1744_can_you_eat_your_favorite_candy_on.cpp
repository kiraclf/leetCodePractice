#include <vector>
using namespace std;

/*
* 从第0天开始吃糖果
* 在吃完所有 i-1 类糖果之前,不允许吃第 i 类糖果
* 在吃完所有的糖果之前,每天至少吃一颗糖

* queries[i]
* [0] --- favoriteType
* [1] --- favoriteDay
* [2] --- dailyCapi

能否在每天不超过 dailyCapi 的前提下,在 favoriteDay 吃到 favoriteType 类糖果
*/
class Solution {
 private:
  using LL = long long;

 public:
  vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    int n = candiesCount.size();

    // 前缀和
    vector<LL> sum(n);
    sum[0] = candiesCount[0];
    for (int i = 1; i < n; ++i) {
      sum[i] = sum[i - 1] + candiesCount[i];
    }

    vector<bool> ans;
    for (const auto& q : queries) {
      int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2];

      LL x1 = favoriteDay + 1;
      LL y1 = (LL)(favoriteDay + 1) * dailyCap;
      LL x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
      LL y2 = sum[favoriteType];

      ans.push_back(!(x1 > y2 || y1 < x2));
    }
    return ans;
  }
};