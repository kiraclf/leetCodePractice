#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int step = 0;
    int n = arr.size();
    vector<int> vis = vector<int>(n, 0);
    unordered_map<int, set<int>> pos;

    queue<int> q;
    q.push(0);

    for (int i = 0; i < arr.size(); i++) {
      pos[arr[i]].insert(i);
    }

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int i = q.front();
        q.pop();
        vis[i] = 1;

        if (i == n - 1) return step;

        if (i > 0 && !vis[i - 1]) {
          q.push(i - 1);
        }
        if (i + 1 < n && !vis[i + 1]) {
          q.push(i + 1);
        }

        for (auto p : pos[arr[i]]) {
          if (!vis[p]) q.push(p);
          pos[arr[i]].erase(p);
        }
      }

      step++;
    }

    return step;
  }
};

int main() {
  Solution solve;
  vector<int> test = {11, 22, 7, 7, 7, 7, 7, 7, 7, 22, 13};
  int result = solve.minJumps(test);
  return 0;
}