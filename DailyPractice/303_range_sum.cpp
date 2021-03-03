#include <vector>
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        numArr = vector<int>();
        sumArr = vector<int>();
        int sum = 0;
        for (auto number : nums) {
            numArr.push_back(number);
            sum += number;
            sumArr.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        // exception check
        int size = numArr.size();
        if ( i < 0 || i >= size || j < 0 || j >= size || i > j) {
            return 0;
        }
        return sumArr[j] - sumArr[i] + numArr[i];
    }
private:
    vector<int> numArr;
    vector<int> sumArr;
};