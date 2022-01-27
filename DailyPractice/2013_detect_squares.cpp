#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class DetectSquares {
 private:
  unordered_map<int, unordered_set<int>> sameXMap;
  unordered_map<int, int> countMap;

 public:
  DetectSquares() {
    sameXMap = {};
    countMap = {};
  }

  /// y * 1000 + x
  void add(vector<int> point) {
    int pointHash = point[0] + point[1] * 10000;
    sameXMap[point[0]].insert(pointHash);
    countMap[pointHash] += 1;
  }

  int count(vector<int> point) {
    int totalCount = 0;
    int pointHash = point[0] + point[1] * 10000;
    unordered_set<int> sameX = sameXMap[point[0]];
    for (auto sameXPoint : sameX) {
      if (sameXPoint == pointHash) {
        continue;
      }
      int space = abs(sameXPoint / 10000 - point[1]);
      // line in top
      int bottomLeftHash = pointHash - space;
      int bottomRightHash = sameXPoint - space;
      // line in bottom
      int topLeftHash = pointHash + space;
      int topRightHash = sameXPoint + space;
      totalCount +=
          getCount(pointHash, sameXPoint, bottomLeftHash, bottomRightHash);
      totalCount += getCount(pointHash, sameXPoint, topLeftHash, topRightHash);
    }
    return totalCount;
  }

  int getCount(int point, int sameX, int left, int right) {
    int leftCount = countMap[left];
    int rightCount = countMap[right];
    int sameCount = countMap[sameX];
    return leftCount * rightCount * sameCount;
  }
};

int main() {
  DetectSquares* obj = new DetectSquares();
  obj->add({3, 10});
  obj->add({11, 2});
  obj->add({3, 2});
  obj->count({11, 10});  // 返回 1 。你可以选择：                 //   -
                         // 第一个，第二个，和第三个点
  obj->count({14, 8});  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
  obj->add({11, 2});  // 允许添加重复的点。
  obj->count({11, 10});
}