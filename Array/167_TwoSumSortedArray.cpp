#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int startIndex = 0;
        int endIndex = numbers.size() - 1;
        while ( startIndex < endIndex ) {
            int current = numbers[startIndex] + numbers[endIndex];
            if (current == target) {
                return { startIndex, endIndex};
            } else if ( current > target) {
                endIndex--;
            } else {
                startIndex++;
            }
        }
        return {startIndex, endIndex};
    }
};