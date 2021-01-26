#include <unordered_map>
#include <vector>

using namespace std;

/**
给你一个由一些多米诺骨牌组成的列表 dominoes。
如果其中某一张多米诺骨牌可以通过旋转 0 度或 180
度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c,
d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i]
和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

1 <= dominoes[i][j] <= 9
*/

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> cache;
    int pairs = 0;
    for (int i = 0; i < dominoes.size(); i++) {
      int currentValue = getValueOfVector(dominoes[i]);
      if (cache.find(currentValue) == cache.end()) {
        cache[currentValue] = 1;
      } else {
        pairs += cache[currentValue];
        cache[currentValue] += 1;
      }
    }
    return pairs;
  }

  int getValueOfVector(vector<int>& item) {
    if (item[0] < item[1]) {
      return (item[0] << 4) + item[1];
    } else {
      return (item[1] << 4) + item[0];
    }
  }
};