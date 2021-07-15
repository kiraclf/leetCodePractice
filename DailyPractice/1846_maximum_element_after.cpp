#include <vector>
using namespace std;
class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    vector<int> elements(arr);
    // sort
    sort(elements.begin(), elements.end());
    // init
    if (elements.size() == 0) {
      return 0;
    }
    elements[0] = 1;
    int maxValue = 1;
    for (int i = 1; i < elements.size(); i++) {
      int equal = elements[i-1];
      int larger = elements[i-1] + 1;
      int lesser = elements[i-1] - 1;
      int current = elements[i];
      if (current >= larger) {
        elements[i] = larger;
        maxValue = max(maxValue, larger);
      } else {
        elements[i] = equal;
      }
    }
    return maxValue;
  }

  int betterSolution(vector<int>& array) {
    int n = array.size();
    vector<int> cnt(n + 1);
    // 统计每个数出现的次数, 大于 n 的按照 n 算
    for (int v : array) {
      cnt[min(v, n)]++;
    }
    // 统计缺失的个数
    int miss = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 0) {
        miss++;
      } else {
        miss -= min(cnt[i]-1, miss);
      }
    }
    return n - miss;
  }
};

int main() {
  Solution solve;
  vector<int> test = {1,2,3,4,5};
  int result = solve.maximumElementAfterDecrementingAndRearranging(test);
  return 0;
}