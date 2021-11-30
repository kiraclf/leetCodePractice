#include <vector>
using namespace std;
bool compare(vector<int> s1, vector<int> s2) {
  assert(s1.size() == 4 && s2.size() == 4);
  if (s1[0] != s2[0]) {
    return s1[0] - s2[0];
  }
  return s1[1] - s2[1];
}

class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int size = rectangles.size();
    vector<int> line{4, 0};
    //创建各个矩形的边的数组
    //一共有 2 * size 条竖边
    vector<vector<int>> lines(2 * size, line);
    for (int i = 0, idx = 0; i < size; i++) {
      vector<int> rect = rectangles[i];
      vector<int> leftLine = {rect[0], rect[1], rect[3], 1};
      vector<int> rightLine = {rect[2], rect[1], rect[3], -1};
      lines[idx] = leftLine;
      idx++;
      lines[idx] = rightLine;
      idx++;
    }
    // 排序竖边 从左到右,从下到上
    sort(lines.begin(), lines.end(), compare);
    // 存储左侧的边
    vector<vector<int>> leftLines;
    // 存储右侧的边
    vector<vector<int>> rightLines;
    size *= 2;
    for (int left = 0; left < size;) {
      int right = left;
      leftLines.clear();
      rightLines.clear();
      // 找到横坐标相同的部分
      while (right < size && lines[right][0] == lines[left][0]) {
        right++;
      }
      // 这里面的横坐标都相同
      for (int i = left; i < right; i++) {
        vector<int> current = {lines[i][1], lines[i][2]};
        vector<vector<int>> targetList =
            lines[i][3] == 1 ? leftLines : rightLines;
        if (targetList.size() == 0) {
          targetList.push_back(current);
        } else {
          vector<int> prev = targetList[targetList.size() - 1];
          if (current[0] < prev[1]) {
            // 存在重叠
            return false;
          } else if (current[0] == prev[1]) {
            // 首尾相连
            prev[1] = current[1];
          } else {
            targetList.push_back(current);
          }
        }
      }
      if (left > 0 && right < size) {
        // 不是完美矩形的边缘竖边,检查是否成对出现
        if (leftLines.size() != rightLines.size()) {
          return false;
        }
        for (int i = 0; i < leftLines.size(); i++) {
          if (leftLines[i][0] == rightLines[i][0] &&
              leftLines[i][1] == rightLines[i][1]) {
            continue;
          }
          return false;
        }
      } else {
        // 完美矩形的边缘竖边,检查是否完整一段
        if (leftLines.size() + rightLines.size() != 1) {
          return false;
        }
        left = right;
      }
    }
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test;
  bool result = solve.isRectangleCover(test);
  return 0;
}