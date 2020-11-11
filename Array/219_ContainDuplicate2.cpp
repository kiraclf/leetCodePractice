#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Problems: Given an array of integers and an integer k
 * find out whether there are two distinct indices i and j in the array such
 * that nums[i] = nums[j] and the absolute difference between i and j is at most
 * k.
 */

/**
 * 思路:
 * 1. 暴力解法，直接遍历搜索，时间复杂为 O(n ^ 2)
 * 2. 创建一个 map，遍历整个数组 key 为 value, value 为 index
 */

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int size = nums.size();
    if (size <= 1) return false;
    unordered_map<int, int> cacheMap;
    for (int i = 0; i < size; i++) {
      int number = nums[i];
      if (cacheMap.find(number) != cacheMap.end()) {
        int length = i - cacheMap[number];
        if (length <= k) {
          return true;
        }
      }
      cacheMap[number] = i;
    }
    return false;
  }
};

int main() {
  Solution solve;
  vector<int> toSolve = {1, 2, 3, 1, 2, 3};
  bool contains = solve.containsNearbyDuplicate(toSolve, 2);
  return 0;
}