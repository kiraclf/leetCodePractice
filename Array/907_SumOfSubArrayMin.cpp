#include <vector>
using namespace std;

/**
 * 思路：
 *  首先还是需要数组排序(从大到小)
 *  关键在于推导出 dp 方程，以 dp(n) 数组长度为 n 时的最小值
 *  dp(n) = dp(n - 1) + arr(n) * (2 ^ (n - 1))
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int size = arr.size();
        if (size < 1) {
            return 0;
        } 
        sort(arr.begin(), arr.end());
        arr.reserve(arr.size());
        int temp = mod(arr[0]);
        int multiper = 1;
        for (int i = 1; i < size; i++) {
            temp = mod(temp + mod(arr[i]) * multiper);
            multiper = multiper << 1;
        }
        return temp;
    }

    int mod(int number) {
        return number % 1000000007;
    }
};