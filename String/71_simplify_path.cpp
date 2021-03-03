#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> splited = splitPath(path);
    vector<string> file;
    for (int i = 0; i < splited.size(); i++) {
      if (splited[i] == ".") {
        // current directory
        continue;
      } else if (splited[i] == "..") {
        // up directory
        if (file.size() != 0) {
          file.pop_back();
        }
      } else {
        file.push_back(splited[i]);
      }
    }
    string result;
    result += "/";
    for (int i = 0; i < file.size(); i++) {
      result += file[i];
      if (i != file.size() - 1) {
        result += "/";
      }
    }
    return result;
  }

  vector<string> splitPath(string path) {
    vector<string> result;
    string temp;
    for (int i = 0; i < path.size(); i++) {
      if (path[i] == '/') {
        if (temp.size() != 0) {
          result.push_back(temp);
          temp = "";
        }
      } else {
        temp += path[i];
      }
    }
    if (temp.size() != 0) {
      result.push_back(temp);
    }
    return result;
  }
};

int main() {
  Solution solve;
  string result = solve.simplifyPath("/a//b////c/d//././/..");
  return 0;
}