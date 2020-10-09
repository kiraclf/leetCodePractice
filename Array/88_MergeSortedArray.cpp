#include <iostream>
#include <vector>

using namespace std;

/*
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively. You may assume that nums1 has enough space (size that is equal
 * to m + n) to hold additional elements from nums2.
 */

/**
 * 暴力解法:
 *  使用另一个数组，来进行遍历，取出其中的最大值
 *  时间复杂度 O（m + n）,空间复杂度 O(m + n)
 *
 * Hint: 从前进行遍历，或许过于复杂，但是一旦从后向前遍历，则可以简单很多
 */

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int tar = m + n - 1;
    while (j >= 0) {
      if (i >= 0 && nums1[i] > nums2[j]) {
        nums1[tar] = nums1[i];
        i--;
        tar--;
      } else {
        nums1[tar] = nums2[j];
        j--;
        tar--;
      }
    }
  }
};