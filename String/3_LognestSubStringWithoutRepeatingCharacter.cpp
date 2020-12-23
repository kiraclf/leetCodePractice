#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

/**
 * 思路: 双指针
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 异常处理
        int length = s.length();
        if (length <= 1) {
            return length;
        }
        // 双指针
        int maxLength = 1;
        int startIndex = 0;
        int endIndex = 1;
        unordered_set<int> cache;
        cache.insert(s[0]);
        while (endIndex < length) {
            if (cache.find(s[endIndex]) != cache.end()) {
                maxLength = max((int)cache.size(), maxLength);
                // 存在重复
                removeDuplicate(cache, s, startIndex, s[endIndex]);
            }
            cache.insert(s[endIndex]);
            endIndex++;
        }
        maxLength = maxLength == length ? length - 1 : maxLength;
        return maxLength;
    }

    void removeDuplicate(unordered_set<int> &cache, string s, int &startIndex, char target) {
        for (int i = startIndex; i < s.length(); i++) {
            cache.erase(s[i]);
            if (s[i] == target) {
                startIndex = i + 1;
                return;
            }
        }
    }
};