#include <vector>
using namespace std;

class Solution {
public:
     public int maximumProduct(int[] nums) {
        // 根据题目判断当有负数时，最多能取两个负数且是排序后的第一、二个元素；
        // 当nums[0]*nums[1]>=nums[len-1]*nums[len-2]存在两种情况：
        //     第一种：nums[len-3]为负数，则返回nums[0]*nums[1]*nums[len-1]
        //     第二种：nums[len-3]为正数，则返回nums[0]*nums[1]*nums[len-1]
        // 当nums[0]*nums[1]<nums[len-1]*nums[len-2],直接返回数组后三个元素的乘积
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return max((nums[len - 1] * nums[len - 2] * nums[len - 3]), (nums[0] * nums[1] * nums[len-1]));
    }
};