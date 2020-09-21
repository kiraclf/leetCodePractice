/*
 * Given an array nums with n objects colored red, white, or blue,
 * sort them in-place so that objects of the same color are adjacent,
 * with the colors in the order red, white, and blue.
 * 0 red, 1 while, 2 blue
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int redCount = 0;
    int whiteCount = 0;
    int blueCount = 0;
    for (auto value : nums) {
      if (value == 0) {
        redCount++;
      } else if (value == 1) {
        whiteCount++;
      } else if (value == 2) {
        blueCount++;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i < redCount) {
        nums[i] = 0;
      } else if (i < whiteCount + redCount) {
        nums[i] = 1;
      } else {
        nums[i] = 2;
      }
    }
  }

  void sortColors(vector<int> colors) {
    int j = 0, k = colors.size() - 1;
    for (int i = 0; i <= k; i++) {
      if (colors[i] == 0) {
        swap(i, j, colors);
        j++;
      } else if (colors[i] == 2) {
        swap(i, k, colors);
        i--;
        k--;
      }
    }
  }

  void swap(int i, int j, vector<int>& list) {
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
  }
};