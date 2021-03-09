/*
--- 题目描述 ---
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素
输出每个元素的下一个更大元素。
数字x的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数
这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出-1。
--- 思路 ---
单调栈的思路解决
*/
#include <vector>
using namespace std;
struct Element {
  int value;
  int index;
};

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();
    vector<int> ans(size,-1);
    vector<Element> cache;
    for (int i = 0; i < 2 * size; i++) {
      int index = i % size;
      if (cache.size() == 0) {
        // Empty cache
        Element current = {nums[index], index};
        cache.push_back(current);
      } else {
        Element top = cache.back();
        if(nums[index] <= top.value) {
          // less than top
          Element current = {nums[index], index};
          cache.push_back(current);
        } else {
          // larger than top
          while (cache.size() > 0 && nums[index] > cache.back().value) {
            if (ans[cache.back().index] == -1) {
              ans[cache.back().index] = nums[index];
            }
            cache.pop_back();
          }
          Element current = {nums[index], index};
          cache.push_back(current);
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<int> test = {1,2,1};
  Solution solve;
  vector<int> result = solve.nextGreaterElements(test);
  return 0; 
}