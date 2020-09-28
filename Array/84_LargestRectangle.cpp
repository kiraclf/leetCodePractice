// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1 find the area of largest rectangle in the
// histogram.
#include <iostream>
#include <vector>

using namespace std;
/**
 * 暴力解法:
 *  遍历每个柱子，分别查看左边的宽度和右边的宽度(左侧和右侧的值==当前)，然后计算其值
 */

class Solution {
 public:
  int alargestRectangleArea(vector<int>& heights) {
    int size = 0;
    for (int i = 0; i < heights.size(); i++) {
      int left = i - 1;
      while (left >= 0 && heights[left] == heights[i]) {
        left--;
      }
      int right = i + 1;
      while (right < heights.size() && heights[right] == heights[i]) {
        right++;
      }
      int currentSize = heights[i] * (right - left + 1);
      cout << currentSize << "\n" << endl;
      size = max(size, currentSize);
    }
    return size;
  }

  // 时间复杂度 O(N ^ 2) 不会通过。。。。
  int brutalLargestRectangleArea(vector<int>& heights) {
    int size = 0;
    for (int i = 0; i < heights.size(); i++) {
      int left = i - 1;
      while (left >= 0 && heights[left] >= heights[i]) {
        left--;
      }
      left++;
      cout << "left " << left << endl;
      int right = i + 1;
      while (right < heights.size() && heights[right] >= heights[i]) {
        right++;
      }
      right--;
      cout << "right " << right << endl;
      int currentSize = heights[i] * (right - left + 1);
      size = max(size, currentSize);
    }
    return size;
  }
};

int main() {
  vector<int> toTest = {2, 1, 5, 6, 2, 3};
  Solution solve;
  int max = solve.largestRectangleArea(toTest);
  cout << "Area: " << max << endl;
  return 0;
}