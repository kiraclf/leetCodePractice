#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    unordered_set<int> haveTrusted;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> trust = {{1, 3}, {2, 3}, {3, 1}};
  int n = 3;
  int judge = solve.findJudge(n, trust);
  return 0;
}