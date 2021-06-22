#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  int maxLength(vector<string>& arr) {
    int maxSize = 0;
    vector<int> numCache(26, 0);
    dfs(arr, 0, maxSize, numCache, "");
    return maxSize;
  }

  void dfs(vector<string>& arr, int index, int& maxSize, vector<int>& numCache,
           string current) {
    for (int i = index; i < arr.size(); i++) {
      string currentString = arr[i];
      bool canAdd = true;
      for (int j = 0; j < currentString.size(); j++) {
        numCache[(int)(currentString[j] - 'a')] += 1;
        if (numCache[(int)(currentString[j] - 'a')] > 1) {
          canAdd = false;
        }
      }
      if (canAdd) {
        current += currentString;
        maxSize = max((int)current.size(), maxSize);
        dfs(arr, i + 1, maxSize, numCache, current);
      }
      for (int i = 0; i < currentString.size(); i++) {
        if (canAdd) {
          current.pop_back();
        }
        numCache[(int)(currentString[i] - 'a')] -= 1;
      }
    }
  }
};

int main() {
  Solution slove;
  vector<string> test = {"cha", "r", "act", "ers"};
  int result = slove.maxLength(test);
  return 0;
}