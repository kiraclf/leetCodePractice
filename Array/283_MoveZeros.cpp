#include <vector>
#include <iostream>

using namespace std;
/*
* Given an array nums, 
* write a function to move all 0's to the end of it 
* while maintaining the relative order of the non-zero elements.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;
        int startIndex = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[startIndex] = nums[i];
                startIndex++;
            }
        }
        for (int i = startIndex; i < size; i++) {
            nums[i] = 0;
        }
    }
};