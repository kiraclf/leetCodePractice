/*
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j]
是鲍勃拥有的第 j 根糖果棒的大小。
因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）
返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob
必须交换的糖果棒的大小。
如果有多个答案，你可以返回其中任何一个。保证答案存在。
*/

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sum = 0;
    int sumA = 0;
    unordered_set<int> cacheSet;
    // Caculate Sum
    for (auto aValue : A) {
      sum += aValue;
      sumA += aValue;
    }
    for (auto bValue: B) {
      // Add to cache
      cacheSet.insert(bValue);
      sum += bValue;
    }
    int target = sum / 2;
    for (auto aValue: A) {
      int targetBValue = target - sumA + aValue;
      if (cacheSet.find(targetBValue) != cacheSet.end()) {
        return {aValue, targetBValue};
      } 
    }
    return {0, 0};
  }
};