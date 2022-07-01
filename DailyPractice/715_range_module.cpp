#include <map>
#include <vector>
using namespace std;
class RangeModule {
 private:
  // 也可以用 set<pair<int,int>>，但显然 map 更简洁一些
  // 注意 key 为 right，value 为 left，为了方便后面查找
  map<int, int> mp;

 public:
  RangeModule() {}

  void addRange(int left, int right) {
    // l r 记录新区间的左右端点
    int l = left, r = right;
    // 找到第一个右端点大于等于 left
    // 的区间，即第一个可能与要添加区间重合的的区间 注意 key 为 right，value 为
    // left，也是为了这里方便查找
    auto p = mp.lower_bound(left);
    // 注意上面查找只保证找到的区间 右端点 大于目标区间左端点 left
    // 同时需要该区间 左端点 小于目标区间右端点 right，才能保证有重合，即
    // p->second <= right 同时要时刻注意 map 的 key 即 first 是右端点，second
    // 是左端点
    while (p != mp.end() && p->second <= right) {
      // 维护 [l, r] 为合并后的区间
      l = min(l, p->second);
      r = max(r, p->first);
      // 删除旧区间
      mp.erase(p++);
    }
    mp[r] = l;
    // 经过上面的操作，已经把有重合的区间合并为一个大区间
    // 注意，[1,2) 和 [2,3) 也能够被合并为 [1,3)，可以在纸上画一画
  }

  bool queryRange(int left, int right) {
    // 同上，找到第一个右端点大于等于 left
    // 的区间，即第一个可能与要添加区间重合的的区间
    auto p = mp.lower_bound(left);
    // 没找到，false
    if (p == mp.end()) return false;
    // 找到了，因为我们的 addRange 方法保证了连续的区间都能被合并为一个大区间
    // 所以我们只要判断找到的区间是否大于等于目标区间即可，包含则 true，否则
    // false
    if (p->second <= left && p->first >= right) return true;
    return false;
  }

  void removeRange(int left, int right) {
    // 同上，找到第一个右端点大于等于 left+1
    // 的区间，即第一个可能与要添加区间重合的的区间 注意，移除 [2,3) 时，[1,2)
    // 和其无交集，所以要找右端点大于等于 left+1 的区间
    auto p = mp.lower_bound(left + 1);
    // 同上
    while (p != mp.end() && p->second <= right) {
      // 如果找到的区间左侧有不用删除的部分，则加入到 map 中
      if (p->second < left) {
        mp[left] = p->second;
      }
      // 注意不包括等于
      if (p->first > right) {
        // 如果右端点大于 right，直接添加右边不用删除的部分即可
        // 注意由于 map 的 key 是右端点，所以这里是修改右端点对应的左端点
        mp[p->first] = right;
        // 由于我们保证连续的区间一定能合并为一个大区间，所以可以直接 break
        // 了，不 break 后面也会调出循环
        break;
      } else {
        // 如果右端点小于 right，区间完全要被删除，map 移除该区间，往下查找
        mp.erase(p++);
      }
    }
  }
};

struct Node {
  bool lazy;
  // 0 表示混合, 1 表示 全部存在, 2 表示全不存在
  int value;
  int left;
  int right;
  Node* leftPtr;
  Node* rightPtr;
};

class MyRangeModule {
 public:
  void addRange(int left, int right) { update(root, left, right, 1); }

  void removeRange(int left, int right) { update(root, left, right, 2); }

  bool queryRange(int left, int right) { return query(root, left, right); }

 private:
  Node* root = new Node{true, 2, 1, 1000000000, nullptr, nullptr};
  bool query(Node* node, int left, int right) {
    int nLeft = node->left;
    int nRight = node->right;
    int mid = nLeft + (nRight - nLeft) / 2;
    if (nLeft == left && nRight == right) {
      return node->value == 1;
    }
    checkNodeLR(node);
    if (left > mid) {
      return query(node->rightPtr, left, right);
    } else if (right <= mid) {
      return query(node->leftPtr, left, right);
    } else {
      return query(node->leftPtr, left, mid) &&
             query(node->rightPtr, mid + 1, right);
    }
  }
  void update(Node* node, int left, int right, int value) {
    int nLeft = node->left;
    int nRight = node->right;
    if (nLeft == left && nRight == right) {
      node->value = value;
      pushDown(node, value);
      return;
    }
    checkNodeLR(node);
    int mid = nLeft + (nRight - nLeft) / 2;
    if (left > mid) {
      update(node->rightPtr, left, right, value);
    } else if (right <= mid) {
      update(node->leftPtr, left, right, value);
    } else {
      update(node->leftPtr, left, mid, value);
      update(node->rightPtr, mid + 1, right, value);
    }
    if (node->leftPtr->value == 1 && node->rightPtr->value == 1) {
      node->value = 1;
    } else if (node->leftPtr->value == 2 && node->rightPtr->value == 2) {
      node->value = 2;
    } else {
      node->value = 0;
    }
  }
  void pushDown(Node* node, int value) {
    if (node->leftPtr != nullptr) {
      node->leftPtr->value = value;
      pushDown(node->leftPtr, value);
    }
    if (node->rightPtr != nullptr) {
      node->rightPtr->value = value;
      pushDown(node->rightPtr, value);
    }
  }
  void checkNodeLR(Node* node) {
    if (!node->lazy) {
      return;
    }
    int left = node->left;
    int right = node->right;
    int mid = left + (right - left) / 2;
    Node* leftNode = new Node{true, node->value, left, mid, nullptr, nullptr};
    if (left == mid) {
      leftNode->lazy = false;
    }
    Node* rightNode =
        new Node{true, node->value, mid + 1, right, nullptr, nullptr};
    if (right == mid + 1) {
      rightNode->lazy = false;
    }
    node->leftPtr = leftNode;
    node->rightPtr = rightNode;
    node->lazy = false;
  }
};

int main() {
  MyRangeModule solve;
  solve.addRange(1,2);
  bool res = solve.queryRange(100, 1000);
  return 0;
}