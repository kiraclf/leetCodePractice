#include <vector>
using namespace std;

class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 0) {
        moveOne(arr, i);
      }
    }
  }

  void moveOne(vector<int>& arr, int index) {
    if (index + 1 >= arr.size()) {
      return;
    }
    int before = arr[index + 1];
    arr[index + 1] = 0;
    for (int i = index + 2; i < arr.size(); i++) {
      int temp = arr[i];
      arr[i] = before;
      before = temp;
    }
  }
};