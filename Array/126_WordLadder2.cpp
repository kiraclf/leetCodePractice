#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * 题目描述：
 *  Given two words (beginWord and endWord), and a dictionary's word list, 
 *  find all shortest transformation sequence(s) from beginWord to endWord, such that:
 *  * Only one letter can be changed at a time
 *  * Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * 
 * 思路：
 *  1. 如果 wordList 中不包含 endWord 则返回空
 *  2. 如果 startWord 中变幻一个后，始终不会在 wordList 中，则返回空
 *  3. 遍历改变的位置，进行 DFS
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        vector<string> temp;
        unordered_set<string> wordSet;
        for (auto text : wordList) {
            wordSet.insert(text);
        }
        temp.push_back(beginWord);
        // temp 用来保存当前的路径
        findLadderHelper(beginWord, endWord, temp, ans, wordSet);
        return ans;   
    }

    void findLadderHelper(string beginWord, string endWord, vector<string> &temp, vector<vector<string>> &ans, unordered_set<string> &wordSet) {
        cout << beginWord << endl;
        if (beginWord == endWord) {
            if (min > temp.size()) {
                ans.clear();
                min = temp.size();
                cout << "push" << endl;
                ans.push_back(temp);
            } else if (min == temp.size()) {
                cout << "push" << endl;
                ans.push_back(temp);
            }
            return;
        }
        if (temp.size() >= min) {
            return;
        }
        vector<string> neighbrs = getNeighbors(beginWord, wordSet);
        for (auto text : neighbrs) {
            if (hasValue(text, temp)) {
                continue;
            }
            temp.push_back(text);
            findLadderHelper(text, endWord, temp, ans, wordSet);
            temp.pop_back();
        }
    }

    bool hasValue(string current, vector<string>& list) {
        for (auto listText : list) {
            if (current == listText) {
                return true;
            }
        }
        return false;
    }

    vector<string> getNeighbors(string current, unordered_set<string> &wordSet) {
        vector<string> ansList;
        for (int i = 0; i < current.size(); i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                if (current[i] == j) {
                    continue;
                }
                char old = current[i];
                current[i] = j;
                if (wordSet.find(current) != wordSet.end()) {
                    ansList.push_back(current);
                }
                current[i] = old;
            }
        }
        return ansList;
    }
private:
    int min = INT_MAX;
};

class Soution2 {
    public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        if (!containsWord(endWord, wordList)) {
            return ans;
        }
        unordered_set<string> wordSet;
        for (auto text : wordList) {
            wordSet.insert(text);
        }
        bfs(beginWord, endWord, wordList, ans, wordSet);
        return ans;
    }

    void bfs(string beginWord, string endWord, vector<string> &wordList, vector<vector<string>> &ans, unordered_set<string> &wordSet) {
        vector<vector<string>> queue;
        vector<string> path;
        path.push_back(beginWord);
        queue.push_back(path);
        bool isFound = false;
        unordered_set<string> visited;
        visited.insert(beginWord);
        while (!queue.size() == 0) {
            int size = queue.size();
            unordered_set<string> subVisited;
            for (int i = 0; i < size; i++) {
                
            }
        }
    }

    bool containsWord(string current, vector<string> &list) {
        for (auto text : list) {
            if (text == current) {
                return true;
            }
        }
        return false;
    }

        vector<string> getNeighbors(string current, unordered_set<string> &wordSet) {
        vector<string> ansList;
        for (int i = 0; i < current.size(); i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                if (current[i] == j) {
                    continue;
                }
                char old = current[i];
                current[i] = j;
                if (wordSet.find(current) != wordSet.end()) {
                    ansList.push_back(current);
                }
                current[i] = old;
            }
        }
        return ansList;
    }
};

int main() {
    Solution toTest;
    string begin = "hit";
    string end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    toTest.findLadders(begin, end, wordList);
    return 0;
}