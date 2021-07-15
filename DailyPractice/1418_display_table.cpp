#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    // [customerName, tableNumber, foodItem]
    // create dish list
    unordered_set<string> dishSet;
    for (auto order : orders) {
      dishSet.insert(order[2]);
    }
    vector<string> dishVec;
    for (auto dish : dishSet) {
      dishVec.push_back(dish);
    }
    sort(dishVec.begin(), dishVec.end());
    unordered_map<string, int> dishIndexMap;
    for (int i = 0; i < dishVec.size(); i++) {
      dishIndexMap[dishVec[i]] = i;
    }
    // create table number map, key -- dishNumber, value -- dishCount
    map<int, vector<int>> tableMap;
    for (auto order : orders) {
      string orderNumber = order[1];
      int tableNumber = atoi(orderNumber.c_str());
      if (tableMap.find(tableNumber) == tableMap.end()) {
        vector<int> dishCount(dishVec.size(), 0);
        tableMap[tableNumber] = dishCount;
      }
      int dishIndex = dishIndexMap[order[2]];
      tableMap[tableNumber][dishIndex] += 1;
    }
    // create table
    vector<vector<string>> resultVec;
    dishVec.insert(dishVec.begin(), "Table");
    resultVec.push_back(dishVec);
    for (auto table : tableMap) {
      vector<string> tableVec;
      tableVec.push_back(to_string(table.first));
      for (auto dishCount : table.second) {
        tableVec.push_back(to_string(dishCount));
      }
      resultVec.push_back(tableVec);
    }
    return resultVec;
  }
};

int main() {
  Solution solve;
  vector<vector<string>> test = {{"James", "12", "Fried Chicken"},
                                 {"Ratesh", "12", "Fried Chicken"},
                                 {"Amadeus", "12", "Fried Chicken"},
                                 {"Adam", "1", "Canadian Waffles"},
                                 {"Brianna", "1", "Canadian Waffles"}};
  vector<vector<string>> result = solve.displayTable(test);
  return 0;
}