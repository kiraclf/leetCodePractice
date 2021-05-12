#include <vector>
#include <string>
using namespace std;
class Solution {
 public:
  vector<int> decode(vector<int>& encoded) {
    // find the first number
    int size = encoded.size() + 1;
    int totalXor = 0;
    for (int i = 1; i <= size; i++) {
      totalXor = totalXor ^ i;
    }
    int xorExceptFirst = 0;
    for (int i = 1; i < size - 1; i += 2) {
      xorExceptFirst = xorExceptFirst ^ encoded[i];
    }
    int first = totalXor ^ xorExceptFirst;
    // caculate list number
    vector<int> result(size, 0);
    int nextValue = 0;
    for (int i = 0; i < size; i++) {
      if (i == 0) {
        result[i] = first;
        nextValue = first ^ encoded[i];
      } else {
        result[i] = nextValue;
        if (i != size - 1) {
          nextValue = nextValue ^ encoded[i];
        }
      }
    }
    return result;
  }
};

int main() {
  Solution solve;
  vector<int> test = {3,1};
  vector<int> result = solve.decode(test);
  return 0;
}