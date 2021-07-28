#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    // 剔除所有的干扰元素
    vector<int> filteredArr;
    unordered_map<int, int> validteMap;
    // 生成 filterArr 的位置Map
    unordered_map<int, vector<int>> filterMap;
    for (int i = 0; i < target.size(); i++) {
      validteMap[target[i]] = i;
    }
    for (int i = 0; i < arr.size(); i++) {
      int number = arr[i];
      if (validteMap.find(number) != validteMap.end()) {
        filteredArr.push_back(number);
        filterMap[number].push_back(i);
      }
    }
    // 遍历
    int maxCount = target.size();
    for (int i = 0; i < filteredArr.size(); i++) {
      maxCount = min(maxCount, moveCount(target, filteredArr, i, validteMap, filterMap));
    }
    return maxCount;
  }

  // 遍历以对应的节点为值的需要移动的步数
  int moveCount(
    vector<int>& target,
    vector<int>& filtered, 
    int index, 
    unordered_map<int, int>& validateMap,
    unordered_map<int, vector<int>>& filteredMap) {
      int count = 0;
      int targetIndex = validateMap[filtered[index]];
      for (int i = targetIndex - 1; i >= 0; i--) {

      }
      for (int i = targetIndex + 1; i < target.size(); i++) {

      }
      return count;
  }
};

int main() {
  Solution solve;
  vector<int> target = {5,1,3};
  vector<int> arr = {9,4,2,3,4};
  int count = solve.minOperations(target, arr);
  return 0;
}