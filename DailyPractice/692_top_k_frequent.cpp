#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
struct Word {
  int count;
  string content;
  Word(int count, string content): count(count), content(content){}
  bool operator <(Word a) const {
    if (count == a.count) {
      for (int i = 0; i < content.size(); i++) {
        if (i >= a.content.size()) {
          return true;
        } else {
          if (content[i] != a.content[i]) {
            return content[i] < a.content[i];
          }
        }
      }
    } else {
      return count < a.count;
    }
    return true;
  };
  bool operator >(Word a) const {
    return !operator<(a);
  };

};

struct WordB {
  int count;
  string content;
  WordB(int count, string content) : count(count), content(content) {}
  bool operator<(WordB a) const {
    if (count == a.count) {
      for (int i = 0; i < content.size(); i++) {
        if (i >= a.content.size()) {
          return false;
        } else {
          if (content[i] != a.content[i]) {
            return content[i] > a.content[i];
          }
        }
      }
    } else {
      return count < a.count;
    }
    return true;
  };
  bool operator>(WordB a) const { return !operator<(a); };
};

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    // generate cache map
    unordered_map<string,int> cacheWords;
    for (auto word : words) {
      cacheWords[word] += 1;
    }
    // 小顶堆
    priority_queue<Word, vector<Word>, greater<Word>> queue;
    for (auto pair : cacheWords) {
      Word current(pair.second, pair.first);
      if (queue.size() < k) {
        queue.push(current);
      } else {
        if (current > queue.top()) {
          queue.pop();
          queue.push(current);
        }
      }
    }
    // 大顶堆
    priority_queue<WordB, vector<WordB>, less<WordB>> bigQueue;
    int size = queue.size();
    for (int i = 0; i < size; i++) {
      bigQueue.push(WordB(queue.top().count, queue.top().content));
      queue.pop();
    }
    // return
    vector<string> result(bigQueue.size(), "");
    int resultSize = bigQueue.size();
    for (int i = 0; i < resultSize; i++) {
      result[i] = bigQueue.top().content;
      bigQueue.pop();
    }
    return result;
  }
};

int main() {
  vector<string> test = {"i", "love", "leetcode", "i", "love", "coding"};
  Solution solve;
  vector<string> result = solve.topKFrequent(test, 2);
  return 0;
}