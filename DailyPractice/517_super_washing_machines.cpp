#include <vector>
using namespace std;
class Solution {
 public:
  int findMinMoves(vector<int>& machines) {
    int size = machines.size();
    int sum = 0;
    for (auto clothCount : machines) {
      sum += clothCount;
    }
    if (sum % size != 0) {
      // 无法均分
      return -1;
    }
    int averageCount = sum / size;
    if (equallySpaced(machines, averageCount)) {
      return 0;
    }
    int requiredStep = 0;
    vector<int> frontMissIndex;
    int needContinue = true;
    while (needContinue) {
      int frontNeed = 0;
      for (int i = 0; i < size; i++) {
        int count = machines[i];
        if (count < averageCount) {
          // 小于
          frontNeed += averageCount - count;
          frontMissIndex.push_back(i);
        } else if (count > averageCount) {
          if (frontNeed > 0) {
            // 向左移动
            machines[i] -= 1;
            machines[frontMissIndex[frontMissIndex.size() - 1]] += 1;
            frontNeed -= 1;
            if (machines[frontMissIndex[frontMissIndex.size() - 1]] == averageCount) {
              frontMissIndex.pop_back();
            } 
            } else {
            // 向右移动
            machines[i] -= 1;
            machines[i+1] += 1;
          }
        }
        
      }
      requiredStep++;
      if (frontMissIndex.size() == 0) {
        needContinue = false;
      }
      frontMissIndex.clear();
    }
    return requiredStep;
  }

  bool equallySpaced(vector<int>& machines, int average) {
    for (auto machine : machines) {
      if (machine != average) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solve;
  vector<int> machines = {1,0,5};
  int count = solve.findMinMoves(machines);
  return 0;
}