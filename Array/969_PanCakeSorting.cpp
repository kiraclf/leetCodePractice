#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        if (arr.size() <= 1) {
            return ans;
        }
        // 1. 找到最小的元素，移动到最前面
        int smallestIndex = 0;
        for (int i = 0; i < arr.size(); i++) {
            smallestIndex = arr[i] < arr[smallestIndex] ? i : smallestIndex;
        }
        pancakeFlip(arr, smallestIndex, ans);
        // 2. 遍历将最大的元素移动到最后
        for (int i = arr.size() - 1; i > 0; i--) {
            moveTheMaxToEnd(arr, i, ans);
        }
        return ans;
    }

    void pancakeFlip(vector<int>& arr, int index, vector<int>& ans) {
        if (arr.size() == 0) return;
        ans.push_back(index + 1);
        int start = 0;
        int end = index;
        while (start < end) {
            int temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
            start++;
            end--;
        }
    }

    void moveTheMaxToEnd(vector<int>& arr, int endIndex, vector<int>& ans) {
        int maxIndex = 0;
        for (int i = 0; i <= endIndex; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        pancakeFlip(arr, maxIndex, ans);
        pancakeFlip(arr, endIndex, ans);
        pancakeFlip(arr, endIndex - maxIndex, ans);
    }
};

int main() {
    vector<int> test = {3,2,4,1};
    Solution solve;
    vector<int> sorted = solve.pancakeSort(test);
    return 0;
}