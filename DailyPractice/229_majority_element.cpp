#include "unordered_map"
#include "vector"
using namespace std;
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    // key is the nums, value is count.
    unordered_map<int, int> cache;
    for (auto num : nums) {
      cache[num] += 1;
    }
    vector<int> result;
    int totalSize = nums.size();
    for (auto pair : cache) {
      if (pair.second * 3 > totalSize) {
        result.push_back(pair.first);
      }
    }
    return result;
  }

  vector<int> majorityElementVote(vector<int>& nums) {
    // As described above, the vector's size can't be larger than 2.
    int voteNum1 = 0;
    int voteCount1 = 0;
    int voteNum2 = 0;
    int voteCount2 = 0;
    for (auto num : nums) {
      if (num == voteNum1 && voteCount1 > 0) {
        voteCount1++;
      } else if (num == voteNum2 && voteCount2 > 0) {
        voteCount2++;
      } else if (voteCount2 > 0 && voteCount1 > 0) {
        voteCount1--;
        voteCount2--;
      } else if (voteCount1 == 0) {
        voteNum1 = num;
        voteCount1++;
      } else if (voteCount2 == 0) {
        voteNum2 = num;
        voteCount2++;
      }
    }
    int numberACount = 0;
    int numberBCoount = 0;
    for (auto num : nums) {
      if (num == voteNum1) {
        numberACount++;
      } else if (num == voteNum2) {
        numberBCoount++;
      }
    }
    vector<int> res;
    if (numberACount * 3 > nums.size()) {
      res.push_back(voteNum1);
    }
    if (numberBCoount * 3 > nums.size()) {
      res.push_back(voteNum2);
    }
    return res;
  }
};