#include <vector>
using namespace std;
class Solution {
public:
    /***
     * 使用滑动窗口的思路进行解答
     * 首先固定右侧，然后不断变动左侧，使得其乘积 < k
     * 每次右侧的推入都会增加 j - k - 1 个答案
    */
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if ( k <= 1) return 0;
        int product = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while ( product >= k) {
                product /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};