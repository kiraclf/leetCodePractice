#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> ans;
    unordered_map<string, int> list1Map;
    for (int i = 0; i < list1.size(); i++) {
      list1Map[list1[i]] = i;
    }
    int minSum = INT_MAX;
    for (int i = 0; i < list2.size(); i++) {
      if (list1Map.find(list2[i]) == list1Map.end()) {
        continue;
      }
      int totalSum = list1Map[list2[i]] + i;
      if (totalSum == minSum) {
        ans.push_back(list2[i]);
      } else if (totalSum < minSum) {
        ans.clear();
        ans.push_back(list2[i]);
        minSum = totalSum;
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  vector<string> test1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  vector<string> test2 = {"KFC", "Shogun", "Burger King"};
  auto res = solve.findRestaurant(test1, test2);
  return 0;
}