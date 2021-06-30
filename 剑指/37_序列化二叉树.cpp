#include <string>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == NULL) {
      return "[]";
    }
    vector<string> resultVec;
    // bfs serialize
    vector<TreeNode*> bfs;
    bfs.push_back(root);
    while (!bfs.empty()) {
      TreeNode * top = bfs[0];
      bfs.erase(bfs.begin());
      // process
      if (top == NULL) {
        resultVec.push_back("null");
        continue;
      }
      resultVec.push_back(to_string(top->val));
      // next
      bfs.push_back(top->left);
      bfs.push_back(top->right);
    }
    while (resultVec.size() > 0 && resultVec[resultVec.size() -1] == "null") {
      resultVec.pop_back();
    }
    string resultString = "[";
    for (int i = 0; i < resultVec.size(); i++) {
      resultString += resultVec[i];
      if ( i != resultVec.size() -1) {
        resultString += ",";
      }
    }
    resultString += "]";
    return resultString;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    // format string
    vector<string> stringVec;
    string current = "";
    data.erase(data.begin());
    data.pop_back();
    if (data.size() == 0) {
      return NULL;
    }
    data += ",";
    for (int i = 0; i < data.size(); i++) {
      char currentChar = data[i];
      if (currentChar == ',') {
        stringVec.push_back(current);
        current = "";
      } else {
        current += currentChar;
      }
    }
    // generate node
    TreeNode * head = NULL;
    vector<TreeNode*> nodeVec;
    string rootString = stringVec[0];
    head = new TreeNode(atoi(rootString.c_str()));
    nodeVec.push_back(head);
    int stringVecIndex = 1;
    while (!nodeVec.empty()) {
      TreeNode * top = nodeVec[0];
      nodeVec.erase(nodeVec.begin());
      if (stringVecIndex < stringVec.size()) {
        string currentString = stringVec[stringVecIndex];
        if (currentString == "null") {
          top->left = NULL;
        } else {
          TreeNode * left = new TreeNode(atoi(currentString.c_str()));
          top->left = left;
          nodeVec.push_back(left);
        }
        if (stringVecIndex + 1 < stringVec.size()) {
          string rightString = stringVec[stringVecIndex + 1];
          if (rightString == "null") {
            top->right = NULL;
          } else {
            TreeNode * right = new TreeNode(atoi(rightString.c_str()));
            top->right = right;
            nodeVec.push_back(right);
          }
        }
        stringVecIndex += 2;
      }
    }
    return head;
  }
};

int main() {
  Codec codec;
  string test = "[1]";
  TreeNode * result = codec.deserialize(test);
  string resultString = codec.serialize(result);
  return 0;
}

