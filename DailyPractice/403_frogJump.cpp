#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
 private:
  unordered_set<long> lakeStones;
  vector<int> stones;
 public:
  bool canCross(vector<int>& stones) {
    bool result = false;
    if (stones.size() == 0) {
      return false;
    }
    // Create space
    unordered_set<long> lakeSpace;
    for (auto &stone : stones) {
      lakeSpace.insert(stone);
    }
    this->lakeStones = lakeSpace;
    this->stones = stones;
    // dfs
    return dfs(stones[0], 0, stones[stones.size() - 1]);
  }

  bool dfs(int currentIndex, int step, int largest) {
    if (currentIndex == largest) {
      return true;
    } else if (currentIndex > largest) {
      return false;;
    }
    // step - 1
    bool step1 = false;
    if (step - 1 > 0) {
      int nextIndex = currentIndex + step - 1;
      if (nextIndex <= largest && lakeStones.find(nextIndex) != lakeStones.end()) {
        step1 = dfs(nextIndex, step - 1, largest);
      }
    }
    if (step1) {
      return true;
    }
    // step
    bool step2 = false;
    if (step > 0) {
      int nextIndex = currentIndex + step;
      if (nextIndex <= largest &&
          lakeStones.find(nextIndex) != lakeStones.end()) {
        step2 = dfs(nextIndex, step, largest);
      }
    }
    if (step2) { return true;}
    // step + 1
    bool step3 = false;
    int nextIndex = currentIndex + step + 1;
    if (nextIndex <= largest && lakeStones.find(nextIndex) != lakeStones.end()) {
      step3 = dfs(nextIndex, step - 1, largest);
    }
    if (step3) { return true;}
    return false;
  }
};

int main() {
  Solution solve;
  vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
  bool resulut = solve.canCross(stones);
  return 0;
}