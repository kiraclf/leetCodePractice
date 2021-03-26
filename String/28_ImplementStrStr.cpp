#include <string>
#include <vector>
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

    int strStrKMP(string haystack, string needle) {
        int textSize = haystack.length();
        int patternSize = needle.length();
        if (patternSize == 0) {
            return 0;
        }
        vector<int> prefix(patternSize, 0);
        cratePrefrx(needle, prefix);
        int textIndex = 0;
        int patternIndex = 0;
        while (textIndex < textSize) {
            if (haystack[textIndex] == needle[patternIndex]) {
                textIndex++;
                patternIndex++;
            } else {
                if (patternIndex == 0) {
                    textIndex++;
                } else {
                    patternIndex = prefix[patternIndex-1];
                }
            }
            if (patternIndex == patternSize) {
                return textIndex - patternSize;
            }
        }
        return -1;
    }

    void cratePrefrx(string pattern, vector<int> &prefixArray) {
        int length = 0;
        int index = 1;
        prefixArray[0] = 0;
        while (index < pattern.size()) {
            if (pattern[index] == pattern[length]) {
                prefixArray[index] = length + 1;
                index++;
                length++;
            } else {
                if (length == 0) {
                    prefixArray[index] = 0;
                    index++;
                } else {
                  length = prefixArray[length - 1];
                }
            }
        }
    }
};

/*
"mississippi"
"issip"*/
int main() {
    Solution solve;
    int result = solve.strStrKMP("mississippi", "issip");
    return 0;
}