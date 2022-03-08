#include <vector>
using namespace std;
class Solution {
 private:
  vector<int> delta;
  int ans = 0, cnt = 0, zero, n;

 public:
  void dfs(vector<vector<int>> &requests, int pos) {
    if (pos == requests.size()) {
      if (zero == n) {
        ans = max(ans, cnt);
      }
      return;
    }
    // not choose request[pos]
    dfs(requests, pos + 1);
    // choose request
    // // save before zero count.
    // int z = zero;
    // cnt += 1;
    // auto &r = requests[pos];
    // // x from, y to
    // int x = r[0], y = r[1];
    // zero -= delta[x] == 0;
    // --delta[x];
    // zero += delta[x] == 0;
    // zero -= delta[y] == 0;
    // ++delta[y];
    // zero += delta[y] == 0;
    // dfs(requests, pos + 1);
    // --delta[y];
    // ++delta[x];
    // cnt -= 1;
    // zero = z;
    // 选 requests[pos]
    int z = zero;
    ++cnt;
    auto &r = requests[pos];
    int x = r[0], y = r[1];
    zero -= delta[x] == 0;
    --delta[x];
    zero += delta[x] == 0;
    zero -= delta[y] == 0;
    ++delta[y];
    zero += delta[y] == 0;
    dfs(requests, pos + 1);
    --delta[y];
    ++delta[x];
    --cnt;
    zero = z;
  }
  int maximumRequests(int n, vector<vector<int>> &requests) {
    delta.resize(n);
    zero = n;
    this->n = n;
    dfs(requests, 0);
    return ans;
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};
  int res = solve.maximumRequests(5, test);
  return 0;
}