#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> rightLargest;
    for (int i = 0; i < nums2.size(); i++) {
      int current = nums2[i];
      for (int j = i + 1; j < nums2.size(); j++) {
        int right = nums2[j];
        if (right > current) {
          rightLargest[current] = right;
          break;
        }
      }
      rightLargest[current] = -1;
    }
    vector<int> res(nums1.size(), 0);
    for (int i = 0; i < res.size(); i++) {
      res[i] = rightLargest[nums1[i]];
    }
    return res;
  }

  vector<int> nextGreaterElementOfficial(vector<int>& nums1,
                                         vector<int>& nums2) {
    unordered_map<int, int> hashmap(nums1.size());
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; i--) {
      int num = nums2[i];
      while (!st.empty() && num >= st.top()) {
        st.pop();
      }
      hashmap[num] = st.empty() ? -1 : st.top();
      st.push(num);
    }
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
      res[i] = hashmap[nums1[i]];
    }
    return res;
  }
};