#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<vector<string>>> hashCache;
        for (auto string : strs) {
            int hashValue = stringHash(string);
            if (hashCache.find(hashValue) == hashCache.end()) {
                hashCache[hashValue] = {{string}};
            } else {
                bool added = false;
                for (int i = 0; i < hashCache[hashValue].size(); i++) {
                    if (sameCount(hashCache[hashValue][i][0], string)) {
                        hashCache[hashValue][i].push_back(string);
                        added = true;
                        break;
                    }
                }
                if (!added) {
                    hashCache[hashValue].push_back({string});
                }
            }
        }
        vector<vector<string>> result;
        for (auto stringHashList:hashCache) {
            for (auto stringList:stringHashList.second) {
                result.push_back(stringList);
            }
        }
        return result;
    }

    int stringHash(string s) {
        int result = 0;
        for (auto character : s) {
            int characterIndex = character - 'a';
            int charaterMask = 1 << characterIndex;
            result = result | characterIndex;
        }
        return result;
    }

    bool sameCount(string a, string b) {
        if (a.size() != b.size()) {
            return false;
        }
        vector<int> stringCount(26, 0);
        for (auto chararcter:a) {
            int index = chararcter - 'a';
            stringCount[index]++;
        }
        for (auto character:b) {
            int index = character - 'a';
            stringCount[index]--;
        }
        for (auto value:stringCount) {
            if (value != 0) {
                return false;
            }
        }
        return true;
    }

    // 很遗憾上述超时，主要在于重复字符的判断
    vector<vector<string>> officialGroupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> cache;
        for (auto cString:strs) {
            string original(cString);
            sort(cString.begin(), cString.end());
            if (cache.find(cString) == cache.end()) {
                cache[cString] = {original};
            } else {
                cache[cString].push_back(original);
            }
        }
        vector<vector<string>> result;
        for (auto stringList:cache) {
            result.push_back(stringList.second);
        }
        return result;
    }
};

int main() {
    vector<string> test = {"eat", "tea", "tan", "ate", "nat", "bat", "bbaatt"};
    Solution solove;
    vector<vector<string>> result = solove.officialGroupAnagrams(test);
    return 0;
}