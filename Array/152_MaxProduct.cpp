#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int ans = nums[0];
        int maxV = nums[0];
        int minV = nums[0];
        for (int i = 1; i < size; i++) {
            int currentMax = maxV;
            maxV = max(max(maxV * nums[i], nums[i]), minV * nums[i]);
            minV = min(min(currentMax * nums[i], nums[i]), minV * nums[i]);
            ans = max(maxV, ans);
        }
        return ans;
    }

    int maxBrutalProduct(vector<int>& nums) {
        int maxValue = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums.size() - i; j++) {
                maxValue = max(maxValue, multiple(i, j, nums));
            }
        }
        return maxValue;
    }

    int multiple(int fromIndex, int length, vector<int>& nums) {
        int ans = 1;
        for (int i = fromIndex; i < fromIndex + length - 1; i++) {
            ans *= nums[i];
        }
        return ans;
    }
};