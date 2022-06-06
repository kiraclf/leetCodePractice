#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int findClosest(vector<string>& words, string word1, string word2) {
    unordered_map<string, vector<int>> cache;
    for (int i = 0; i < words.size(); i++) {
      cache[words[i]].push_back(i);
    }
    auto list1 = cache[word1];
    auto list2 = cache[word2];
    int ans = INT_MAX;
    for (int i = 0; i < list1.size(); i++) {
      int searchValue = list1[i];
      int left = 0;
      int right = list2.size() - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (list2[mid] <= searchValue) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      if (left == list2.size()) {
        ans = min(ans, searchValue - list2[list2.size() - 1]);
      } else if (right == -1) {
        ans = min(ans, list2[0] - searchValue);
      } else {
        int temp = min(abs(list2[left] - searchValue),
                       abs(list2[left - 1] - searchValue));
        ans = min(ans, temp);
      }
    }
    return ans;
  }
};

int main() {
  vector<string> test = {"I", "am",         "a",  "student", "from",
                         "a", "university", "in", "a",       "city"};
  Solution solve;
  int ans = solve.findClosest(test, "a", "in");
  return 0;
}