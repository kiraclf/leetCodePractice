#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int size = nums.size();
    if (size < 3) {
      return 0;
    }
    // 数组 map
    unordered_map<long long, vector<int>> numberMap;
    for (int i = 0; i < nums.size(); i++) {
      numberMap[(long long)nums[i]].push_back(i);
    }
    // cache 表示每个 nums 的子序列个数, map --> key 差值 value 个数
    vector<unordered_map<long long, long long>> cache(
        size, unordered_map<long long, long long>());
    // 初始化第一个
    long long firstDiff = (long long)nums[2] - (long long)nums[1];
    long long secondDiff = (long long)nums[1] - (long long)nums[0];
    if (firstDiff == secondDiff) {
      long long diff = (long long)nums[2] - (long long)nums[1];
      cache[2][diff] = 1;
    }
    // 遍历
    for (int i = 3; i < size; i++) {
      for (int j = i - 1; j > 0; j--) {
        int currentCount = 0;
        long long diff = (long long)nums[i] - (long long)nums[j];
        if (cache[j].find(diff) != cache[j].end()) {
          currentCount += cache[j][diff];
        }
        // 判断3个的特殊情况是否存在
        long long first = (long long)nums[j] - diff;
        if (numberMap.find(first) != numberMap.end()) {
          vector<int> indexList = numberMap[first];
          for (auto index : indexList) {
            if (index < j) {
              currentCount++;
            }
          }
        }
        // for (int z = 0; z < j; z++) {
        //   if (nums[z] == first) {
        //     currentCount++;
        //   }
        // }
        cache[i][diff] += currentCount;
      }
    }
    // 答案
    int totalCount = 0;
    for (auto map : cache) {
      for (auto pari : map) {
        totalCount += pari.second;
      }
    }
    return totalCount;
  }
};

int main() {
  Solution solve;
  vector<int> test = {
    2147483638,  2147483639,  2147483640,  2147483641,  2147483642,
    2147483643,  2147483644,  2147483645,  2147483646,  2147483647,
    -2147483648, -2147483647, -2147483646, -2147483645, -2147483644,
    -2147483643, -2147483642, -2147483641, -2147483640, -2147483639};
    int count = solve.numberOfArithmeticSlices(test);
  return 0;
}