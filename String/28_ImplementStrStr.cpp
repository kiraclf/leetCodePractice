#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 空字符的处理
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() == 0) {
            return -1;
        }
        for (int i = 0; i < haystack.size(); i++) {
            for (int j = i; j < haystack.size() && j < needle.size() + i; j++) {
                if (haystack[j] != needle[j - i]) {
                    break;
                }
                if ((j - i) == needle.size() - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};