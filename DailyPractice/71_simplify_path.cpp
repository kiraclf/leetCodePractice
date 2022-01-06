#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> paths;
    // process path
    int pathIndex = 0;
    string component = "";
    while (pathIndex < path.size()) {
      if (path[pathIndex] == '/') {
        if (component != "") {
          addComponent(component, paths);
          component = "";
        }
      } else {
        component += path[pathIndex];
      }
      pathIndex++;
    }
    if (component != "") {
      addComponent(component, paths);
    }
    // generate ans
    string ans = "/";
    for (int i = 0; i < paths.size(); i++) {
      ans += paths[i];
      if (i != paths.size() - 1) {
        ans += "/";
      }
    }
    return ans;
  }
  void addComponent(string component, vector<string>& paths) {
    if (component == "..") {
      // pop current paths
      if (paths.size() != 0) {
        paths.pop_back();
      }
      return;
    }
    if (component == ".") {
      // current path
      return;
    }
    paths.push_back(component);
  }
};

int main() {
  Solution solve;
  string path = "/a//b////c/d//././/..";
  string formatted = solve.simplifyPath(path);
  return 0;
}