#include <vector>
#include <unordered_map>
using namespace std;
/*
--- 题目描述
给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
nums.length 在1到 50,000 区间范围内。
nums[i] 是一个在 0 到 49,999 范围内的整数。
--- 思路
包含度的最短连续子数组 --> 滑动窗口
--- 官方思路
记录原数组出现次数最多的数为 x
那么和原数组度相同的短数组，必定是包含了数组的全部x，且两端恰好为x第一次出现和最后一次出现的位置
使用哈希表，实现该功能，将每个数映射到一个长度为3的数组中，分别表示出现的次数，开始位置和结束位置
然后遍历哈希表，找到出现元素次数最多的
--- 核心
那么和原数组度相同的短数组，必定是包含了数组的全部x，且两端恰好为x第一次出现和最后一次出现的位置
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (mp.count(nums[i])) {
                // 存在
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            } else {
                mp[nums[i]] = {1, i, i};
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto& [_, vec] : mp) {
            if (maxNum < vec[0]) {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            } else if (maxNum == vec[0]) {
                if (minLen > vec[2] - vec[1] + 1) {
                    minLen = vec[2] - vec[1] + 1;
                }
            }
        }
        return minLen;
    }
};