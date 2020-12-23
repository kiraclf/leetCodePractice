#include <vector>
using namespace std;

// 思路： 使用双指针，负数指针以及正数指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        if (size <= 0) {
            return nums;
        }
        vector<int> ans(size, 0);
        // 寻找负数和正数的交叉点
        int biggestNegativeIndex = -1;
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                continue;
            } else {
                if (nums[i] >= 0 && nums[i - 1] < 0) {
                    biggestNegativeIndex = i - 1;
                    break;
                }
            }
        }
        if (biggestNegativeIndex == -1) {
            // 都是同一符号
            if (nums[0] >= 0) {
                for (int i = 0; i < size; i++) {
                    ans[i] = nums[i] * nums[i];
                }
                return ans;
            } else {
                for (int i = 0; i < size; i++) {
                    ans[i] = nums[size - 1 - i] * nums[size - 1 - i];
                }
                return ans;
            }
        }
        // 双指针
        int positveIndex = biggestNegativeIndex + 1;
        int negativeIndex = biggestNegativeIndex;
        int currentIndex = 0;
        while (positveIndex < size && negativeIndex >= 0) {
            if (abs(nums[positveIndex] > abs(nums[negativeIndex]))) {
                ans[currentIndex] = nums[negativeIndex] * nums[negativeIndex];
                currentIndex++;
                negativeIndex--;
            } else {
                ans[currentIndex] = nums[positveIndex] * nums[positveIndex];
                currentIndex++;
                positveIndex++;
            }
        }
        if (currentIndex != size) {
            if (positveIndex < size ) {
                while (positveIndex < size) {
                    ans[currentIndex] = nums[positveIndex] * nums[positveIndex];
                    currentIndex++;
                    positveIndex++;
                }
            } else {
                while (negativeIndex >= 0) {
                    ans[currentIndex] = nums[negativeIndex] * nums[negativeIndex];
                    negativeIndex--;
                    currentIndex++;
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution solve;
    vector<int> test = {-5, -3, -2, -1};
    vector<int> ans = solve.sortedSquares(test);
    return 0;
}