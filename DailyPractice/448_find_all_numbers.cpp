#include <vector>
using namespace std;
/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
找到所有在 [1, n] 范围之间没有出现在数组中的数字。
您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int max = nums.size();
        int min = 1;
        // 1 <= number <= max
        vector<int> cache(max, 0);
        for (int i = 0; i < nums.size(); i++) {
            cache[nums[i] - 1] += 1;
        }
        vector<int> ans;
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i] == 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }

    vector<int> findInPlaceDisappearedNumbers(vector<int>& nums) {
        int min = 1;
        int max = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int absValue = abs(nums[i]);
            if ( nums[absValue - 1] < 0) {
                continue;
            } else {
                nums[absValue - 1] *= -1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if ( nums[i] > 0 ) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> test = {4,3,2,7,8,2,3,1};
    Solution solve;
    vector<int> result = solve.findInPlaceDisappearedNumbers(test);
    return 0;
}