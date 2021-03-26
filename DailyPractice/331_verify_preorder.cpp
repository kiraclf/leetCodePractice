#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    // 特列
    if (preorder == "#") {
      return true;
    }
    int indegree = 0, outdegree = 0;
    int index = 0;
    vector<string> splitedText = splitWith(preorder, ',');
    for (int i = 0; i < splitedText.size(); i++) {
      if (i == 0) {
        if (splitedText[i] == "#") {
          return false;
        }
        outdegree += 2;
        continue;
      }
      if (splitedText[i] == "#") {
        indegree += 1;
      } else {
        indegree += 1;
        outdegree += 2;
      }
      if (i != splitedText.size() - 1 && indegree >= outdegree) {
        return false;
      }
    }
    return indegree == outdegree;
  }

  vector<string> splitWith(string text, char divider) {
    vector<string> res;
    int index = 0;
    string temp;
    while (index < text.length()) {
      if (text[index] == '#') {
        res.push_back("#");
        index += 2;
      } else if (text[index] == divider) {
        index += 1;
      } else {
        while (index < text.length() && text[index] != '#' && text[index] != divider) {
          temp += text[index];
          index++;
        }
        res.push_back(temp);
        temp = "";
        index++;
      }
    }
    return res;
  }
};