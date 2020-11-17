#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
 * A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] - nums[j]| == k
 * Notice that |val| denotes the absolute value of val
*/


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // Assert
        int size = nums.size();
        if ( size <= 1) return -1;
        // Sort
        sort(nums.begin(), nums.end());
        // Cache set
        unordered_set<int> cache;
        // Loop
        int pairSize = 0;
        int startIndex = 0;
        while ( startIndex < nums.size()) {
            int currentValue = nums[startIndex];
            // Jump Duplicate
            if ( startIndex > 0 && currentValue == nums[startIndex - 1]) {
                // k = 0 handling.
                if ( k == 0 ) {
                    if ( startIndex - 2 < 0 || (startIndex - 2 >= 0 && nums[startIndex - 2] != currentValue)) {
                        pairSize++;
                    }
                }
                startIndex++;
                continue;
            }
            int targetValue = currentValue - k;
            if (cache.find(targetValue) != cache.end()) {
                pairSize++;
            }
            cache.insert(currentValue);
            startIndex++;
        }
        return pairSize;
    }
};