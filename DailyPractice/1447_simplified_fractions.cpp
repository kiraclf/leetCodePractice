#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> simplifiedFractions(int n) {
    vector<string> ans;
    vector<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                          43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int bottom = n;
    while (bottom > 1) {
      auto bottomFractions = fractions(bottom, primes);
      int top = 1;
      while (top < bottom) {
        bool canDivide = false;
        for (auto bottomFraction : bottomFractions) {
          if (top < bottomFraction) {
            continue;
          } else if (top % bottomFraction == 0) {
            canDivide = true;
            break;
          }
        }
        if (!canDivide) {
          string current = to_string(top) + "/" + to_string(bottom);
          ans.push_back(current);
        }
        top++;
      }
      bottom--;
    }
    return ans;
  }

  unordered_set<int> fractions(int n, vector<int>& primes) {
    unordered_set<int> ans;
    for (int i = 0; i < primes.size(); i++) {
      int prime = primes[i];
      if (prime >= n) {
        break;
      } else if (n % prime == 0) {
        ans.insert(prime);
      }
    }
    return ans;
  }
};

int main() {
  Solution solve;
  auto res = solve.simplifiedFractions(4);
  return 0;
}