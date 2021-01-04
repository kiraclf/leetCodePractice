#include "vector"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        vector<char> cache;
        for (int i = 0; i < s.length(); i++) {
            char current = s[i];
            if (current == '(' || current == '[' || current == '{') {
                cache.push_back(current);
            } else {
                char target = pairs[current];
                if (cache.size() > 0 && cache[cache.size() - 1] == target ) {
                    cache.pop_back();
                } else {
                    return false;
                }
            }
        }
        if (cache.size() != 0) {
            return false;
        }
        return true;
    }
};