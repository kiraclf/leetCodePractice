#include <vector>
using namespace std;
const int moduleValue = 1000000007;
class Solution {
 private:
 vector<vector<int>> cache;
 int arrLen;
 int totalStep;
 public:
  int numWays(int steps, int arrLen) {
    int maxPos = min(arrLen - 1, steps / 2);
    vector<int> stepCache(steps + 1, -1);
    vector<vector<int>> cache(arrLen, stepCache);
    this->cache = cache;
    this->arrLen = maxPos;
    this->totalStep = steps;
    int count = dfs(0, 0);
    return count;
  }

  // step 当前的步数, posistion 当前的位置, arrLen 总共的长度, count 个数
  int dfs(int step, int posistion) {
    // terminator
    if (step > totalStep - 1) {
      printf("end\n");
      if (posistion == 0) {
        printf("result\n");
        return 1;
      }
      return 0;
    }
    // process
    int result = 0;
    // left 
    if (posistion > 0) {
      printf("left\n");
      result = getValue(step + 1, posistion - 1, result);
    }
    // right
    if (posistion < arrLen - 1) {
      printf("right\n");
      result = getValue(step + 1, posistion + 1, result);
    }
    // not move
    printf("not move\n");
    result = getValue(step + 1, posistion, result);
    return result;
  }

  int getValue(int step, int posistion, int result) {
    int value = cache[posistion][step];
    if (value == -1) {
      cache[posistion][step] = dfs(step, posistion) % moduleValue;
      return (result + cache[posistion][step]) % moduleValue;
    } else {
      return (result + value) % moduleValue;
    }
  }
};

int main() {
  Solution solve;
  int result = solve.numWays(27,7);
  return 0;
}