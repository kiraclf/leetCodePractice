#include <iostream>
#include <vector>

using namespace std;
/**
 * 因为容器总是由最低的那边决定的，因此每次都是移动最低的那边
 * 创建一个头index和一个尾index，然后向中间逼近
 * if - else 可以使用三元运行来简化
 */

class Solution {
 public:
  int maxArea(vector<int>& height) {
    // Safe test
    if (height.size() == 0) {
      return 0;
    }
    int startIndex = 0;
    int endIndex = height.size() - 1;
    int size = 0;
    while (startIndex < endIndex) {
      size = max(
          min(height[startIndex], height[endIndex]) * (endIndex - startIndex),
          size);
      //   if (height[startIndex] < height[endIndex]) {
      //     startIndex++;
      //   } else {
      //     endIndex--;
      //   }
      // 使用 3元运算，来代替此处的 if else 用来提高运行效率
      height[startIndex] < height[endIndex] ? startIndex++ : endIndex--;
    }
    return size;
  }

  int maxAreaSimpleCode(vector<int>& height) {
    int size = 0;
    for (int i = 0, j = height.size() - 1; i < j;) {
      size = max(size, (j - i) * min(height[i], height[j]));
      height[i] < height[j] ? i++ : j--;
    }
    return size;
  }
};

int main() {
  vector<int> test = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution solve = Solution();
  int result = solve.maxArea(test);
  cout << "result=" << result << endl;
  return result == 49 ? 0 : 1;
}