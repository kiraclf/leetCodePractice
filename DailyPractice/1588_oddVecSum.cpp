#include <vector>
using namespace std;
class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    // 创建前缀和数组
    for (int i = 1; i < arr.size(); i++) {
        arr[i] = arr[i-1] + arr[i];
    }
    // 计算以i开头,长度为count的数组的和
    int totalSum = 0;
    for (int i = 0; i < arr.size(); i++) {
      for (int count = 1; i + count - 1 < arr.size(); count += 2) {
        int endIndex = i + count - 1;
        int currentTotal = i == 0 ? arr[endIndex] : arr[endIndex] - arr[i-1];
        totalSum += currentTotal;
      }
    }
    return totalSum;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1,4,2,5,3};
  int oddSum = solve.sumOddLengthSubarrays(test);
  return 0;
}