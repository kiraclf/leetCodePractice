#include <string>
#include <vector>
using namespace std;
/*
--- 启发 ---
string 类型自带了栈的算法,因此可以直接操作
*/
class Solution {
 public:
  string removeDuplicates(string S) {
    vector<char> cache;
    int start = 0;
    while (start < S.length()) {
      int size = cache.size();
      if (size == 0) {
        cache.push_back(S[start]);
        start++;
        continue;
      }
      int topChar = cache.back();
      if (topChar == S[start]) {
        // duplicate
        cache.pop_back();
      } else {
        // push to cache
        cache.push_back(S[start]);
      }
      start++;
    }
    string temp = "";
    for (auto character : cache) {
      temp += character;
    }
    return temp;
  }

  string officialRemoveDuplicate(string S) {
    string stk;
    for (char ch : S) {
      if (!stk.empty() && stk.back() == ch) {
        stk.pop_back();
      } else {
        stk.push_back(ch);
      }
    }
    return stk;
  }
};

int main() {
  Solution solve;
  string result = solve.removeDuplicates("abbaca");
  return 0;
}