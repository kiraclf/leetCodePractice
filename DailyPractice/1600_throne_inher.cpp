#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
struct Governer {
  string name;
  vector<Governer*> children;
  bool alive;
};
class ThroneInheritance {
 public:
  /// 初始化一个国王
  ThroneInheritance(string kingName) {
    firstKing = new Governer{kingName, vector<Governer*>(), true};
    allMember = unordered_map<string,Governer*>();
    allMember[kingName] = firstKing;
  }

  /// 新拥有一个名为 childName 的孩子
  void birth(string parentName, string childName) {
    Governer * newChild = new Governer{childName, vector<Governer*>(), true};
    allMember[parentName]->children.push_back(newChild);
    allMember[childName] = newChild;
  }

  // 名称为name的角色死亡
  void death(string name) {
    allMember[name]->alive = false;
  }

  vector<string> getInheritanceOrder() {
    vector<string> result;
    dfs(result, firstKing);
    return result;
  }
  private:
  Governer* firstKing;
  unordered_map<string,Governer*> allMember;
  void dfs(vector<string> &result, Governer* current) {
    // self
    if (current->alive) {
      result.push_back(current->name);
    }
    // child
    for (auto child : current->children) {
      dfs(result, child);
    }
  } 
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main() {
  ThroneInheritance test = ThroneInheritance("king");
  test.birth("king", "andy");
  test.birth("king", "bob");
  test.birth("king", "catherine");
  test.birth("andy", "matthew");
  test.birth("bob", "alex");
  test.birth("bob", "asha");
  vector<string> result = test.getInheritanceOrder();
  test.death("bob");
  vector<string> result2 = test.getInheritanceOrder();
  return 0;
}