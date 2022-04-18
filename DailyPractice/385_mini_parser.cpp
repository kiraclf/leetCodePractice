#include <stack>
#include <string>
#include <vector>
using namespace std;

class NestedInteger {
 public:
  NestedInteger();
  NestedInteger(int value);
  bool isInteger() const;
  int getInteger() const;
  void setInteger(int value);
  void add(const NestedInteger &ni);
  const vector<NestedInteger> &getList() const;
};
static const int kPlaceValue = 1000001;
class Solution {
 public:
  NestedInteger deserialize(string s) {
    stack<NestedInteger> cache;
    int index = 0;
    while (index < s.size()) {
      char character = s[index];
      if (character == '[') {
        cache.push(NestedInteger(kPlaceValue));
        index++;
      } else if (character == '-' || (character >= '0' && character <= '9')) {
        // number
        bool isNegative = false;
        if (character == '-') {
          isNegative = true;
          index++;
        }
        int value = 0;
        while (s[index] >= '0' && s[index] <= '9') {
          value = value * 10 + (s[index] - '0');
          index++;
        }
        cache.push(NestedInteger(isNegative ? -value : value));
      } else if (character == ',') {
        index++;
      } else if (character == ']') {
        vector<NestedInteger> toAdd;
        while (!cache.empty() && !(cache.top().isInteger() &&
                                   cache.top().getInteger() == kPlaceValue)) {
          NestedInteger top = cache.top();
          toAdd.push_back(top);
          cache.pop();
        }
        reverse(toAdd.begin(), toAdd.end());
        NestedInteger nested;
        for (auto toAddItem : toAdd) {
          nested.add(toAddItem);
        }
        cache.pop();
        cache.push(nested);
        index++;
      }
    }
    return cache.top();
  }
};