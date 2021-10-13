#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; i++) {
      res.push_back(stringReprespent(i));
    }
    return res;
  }

  string stringReprespent(int number) {
    if (number % 3 == 0 && number % 5 == 0) {
      return "FizzBuzz";
    }
    if (number % 3 == 0) {
      return "Fizz";
    }
    if (number % 5 == 0) {
      return "Buzz";
    }
    string ans = "";
    while (number != 0) {
      int current = number % 10;
      ans.push_back('0' + current);
      number /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  vector<string> res = Solution().fizzBuzz(15);
  return 0;
}