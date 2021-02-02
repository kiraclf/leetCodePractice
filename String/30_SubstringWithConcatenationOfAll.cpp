/* 题目描述
给定一个字符串 s 和一些长度相同的单词 words。
找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
注意子串要与 words 中的单词完全匹配，中间不能有其他字符，
但不需要考虑 words 中单词串联的顺序。
*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordCount = words.size();
        if (wordCount == 0) {
            return result;
        }
        int wordLength = words[0].length();
        // generate allowMaps
        unordered_map<string, int> allowMaps;
        for (auto word : words) {
            if (allowMaps.find(word) == allowMaps.end()) {
                allowMaps[word] = 1;
            } else {
                allowMaps[word] += 1;
            }
        }
        // recursive substring
        for (int i = 0; i < s.length() - wordCount * wordLength + 1; i++) {
            // current word hashmap
            unordered_map<string, int> currentMap;
            int num = 0;
            while ( num < wordCount) {
                string word = s.substr(i + num * wordLength, i + (num + 1) * wordLength);
                if (allowMaps.find(word) != allowMaps.end()) {
                    // allow map contains word
                    if (currentMap.find(word) == currentMap.end()) {
                        currentMap[word] = 1;
                    } else {
                        currentMap[word] += 1;
                    }
                    // compare word count
                    if (allowMaps[word] < currentMap[word]) {
                        break;
                    }
                } else {
                    break;
                }
                num++;
            }
            if (num == wordCount) {
                result.push_back(i);
            }
        }
        return result;
    }
};