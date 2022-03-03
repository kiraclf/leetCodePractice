#include <vector>
using namespace std;

/*
使用 vector 直接展开 TreeNode
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
       current = root;
    }
    
    int next() {
       while (current != nullptr) {
           cache.push_back(current);
           current = current->left;
       }
       current = cache.back();
       cache.pop_back();
       int ret = current->val;
       current = current->right;
       return ret;
    }
    
    bool hasNext() {
        return current != nullptr || !cache.empty();
    }
private:
    vector<TreeNode*> cache;
    TreeNode* current;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */