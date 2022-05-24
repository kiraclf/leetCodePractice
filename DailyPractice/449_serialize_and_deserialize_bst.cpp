#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) {
      return "";
    }
    string ans;
    dfs(root, ans);
    return ans;
  }

  void dfs(TreeNode* current, string& ans) {
    // current, left, right 中序遍历
    if (current == nullptr) {
      return;
    }
    ans += to_string(current->val);
    ans += ',';
    dfs(current->left, ans);
    dfs(current->right, ans);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.size() == 0) {
      return nullptr;
    }
    string current = "";
    vector<int> cache;
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == ',') {
        int currentValue = atoi(current.c_str());
        cache.push_back(currentValue);
        current = "";
      } else {
        current += data[i];
      }
    }
    return generate(0, cache.size() - 1, cache);
  }

  TreeNode* generate(int left, int right, vector<int>& numbers) {
    if (left > right) {
      return nullptr;
    }
    TreeNode* current = new TreeNode(numbers[left]);
    int newRight = -1;
    int newLeft = -1;
    for (int i = left + 1; i <= right; i++) {
      if (numbers[i] > numbers[left]) {
        newRight = i;
        break;
      }
    }
    if (newRight != -1) {
      current->right = generate(newRight, right, numbers);
      current->left = generate(left + 1, newRight - 1, numbers);
    } else {
      current->left = generate(left + 1, right, numbers);
    }
    return current;
  }
};

int main() {
  TreeNode* two = new TreeNode(2);
  TreeNode* one = new TreeNode(1);
  TreeNode* three = new TreeNode(3);
  two->left = one;
  two->right = three;

  Codec test;
  string ans = test.serialize(two);
  TreeNode* antPoinster = test.deserialize(ans);
  return 0;
}