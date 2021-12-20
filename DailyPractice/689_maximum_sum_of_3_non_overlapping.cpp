#include <queue>
#include <vector>
using namespace std;

struct Node {
  int value;
  int index;
  Node(int x, int y) {
    value = x;
    index = y;
  }
};

bool operator<(Node x, Node y) {
  if (x.value < y.value) {
    return true;
  } else if (x.value > y.value) {
    return false;
  } else if (x.index > y.index) {
    return true;
  } else {
    return false;
  }
}

class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    // 以 i 开头的 k 子串的大小
    vector<int> subNums(nums.size() - k + 1, 0);
    int before = 0;
    for (int i = 0; i < subNums.size(); i++) {
      if (i == 0) {
        for (int j = 0; j < k; j++) {
          subNums[i] += nums[i + j];
        }
        before = subNums[i];
      } else {
        subNums[i] = before - nums[i - 1] + nums[i + k - 1];
        before = subNums[i];
      }
    }
    // 在 index i 之后不重叠的最大值的index
    vector<int> largerIndex(subNums.size() - k - 1, 0);
    priority_queue<Node, vector<Node>, less<Node>> compareQueue;
    int currentIndex = subNums.size() - 1;
    while (currentIndex >= 0) {
      compareQueue.push(Node(subNums[currentIndex], currentIndex));
      int compareIndex = currentIndex - k;
      if (compareIndex >= 0) {
        Node topNode = compareQueue.top();
        largerIndex[compareIndex] = topNode.index;
      }
      currentIndex--;
    }
    // process
    int biggest = INT_MIN;
    vector<int> res;
    for (int i = 0; i < subNums.size(); i++) {
      for (int j = i + k; j < largerIndex.size(); j++) {
        int nextIndex = largerIndex[j];
        int current = subNums[i] + subNums[j] + subNums[nextIndex];
        if (current > biggest) {
          biggest = current;
          res = {i, j, largerIndex[j]};
        }
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> test = {1, 2, 1, 2, 1, 2, 1, 2, 1};
  vector<int> res = solution.maxSumOfThreeSubarrays(test, 2);
  return 0;
}