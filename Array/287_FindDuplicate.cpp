#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> location(nums.size(), 0);
        for (auto value : nums) {
            if (location[value] != 0) {
                return value;
            } else {
                location[value] = 1;
            }
        }
        return 0;
    }
};