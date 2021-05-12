#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> decode(vector<int>& encoded, int first) {
    int size = encoded.size() + 1;
    vector<int> result(size, 0);
    for (int i = 0; i < size; i++) {
      if (i == 0) {
        result[i] = first;
      } else {
        result[i] = result[i-1] ^ encoded[i-1];
      }
    }
    return result;
  }
};