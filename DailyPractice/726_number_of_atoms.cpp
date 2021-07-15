#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
class Solution {
 public:
  string countOfAtoms(string formula) {
    vector<string> atomis;
    int startIndex = 0;
    while (startIndex < formula.size()) {
      char currentChar = formula[startIndex];
      if (isAtomic(currentChar)) {
        // Atomic content
        if (isAtmoicStart(currentChar)) {
          string atomic = {currentChar};
          atomis.push_back(atomic);
          startIndex++;
        } else if (isAtomicContent(currentChar)) {
          atomis[atomis.size() -1] += currentChar;
          startIndex++;
        }
      } else if (isLeftParthensis(currentChar)) {
        // Left parthensis
        atomis.push_back("(");
        startIndex++;
      } else if (isRightParthensis(currentChar)) {
        // Right parthensis
        int repeatCount = 0;
        while (startIndex + 1 < formula.size() && isDigit(formula[startIndex + 1])) {
          repeatCount = (repeatCount * 10) + (formula[startIndex + 1] - '0');
          startIndex ++;
        }
        startIndex++;
        repeatCount = repeatCount == 0 ? 1 : repeatCount;
        vector<string> toRepeatString;
        while (!atomis.empty() && atomis[atomis.size() -1] != "(") {
          string backString = atomis[atomis.size() -1];
          atomis.pop_back();
          toRepeatString.push_back(backString);
        }
        atomis.pop_back();
        for (auto repeat : toRepeatString) {
          for (int i = 0; i < repeatCount; i++) {
            atomis.push_back(repeat);
          }
        } 
      } else if (isDigit(currentChar)) {
        // Digit
        int count = 0;
        while (startIndex < formula.size() && isDigit(formula[startIndex])) {
          count = (count) * 10 + (formula[startIndex] - '0');
          startIndex++;
        }
        string backString = atomis[atomis.size() -1];
        for (int i = 0; i < count -1; i++) {
          atomis.push_back(backString);
        }
      }
    }
    unordered_map<string ,int> formulaMap;
    for (auto atom : atomis) {
      formulaMap[atom] += 1;
    }
    // Generate formula.
    vector<string> toSortString;
    for (auto formual : formulaMap) {
      string result = "";
      result += formual.first;
      if (formual.second != 1) {
        result += to_string(formual.second);
      }
      toSortString.push_back(result);
    }
    sort(toSortString.begin(), toSortString.end());
    string result = "";
    for (auto srotedString : toSortString) {
      result += srotedString;
    }
    return result;
  }
  bool isAtomic(char character) {
    return isAtmoicStart(character) || isAtomicContent(character);
  }

  bool isAtmoicStart(char character) {
    return character >= 'A' && character <= 'Z';
  }

  bool isAtomicContent(char character) {
    return character >= 'a' && character <= 'z';
  }

  bool isDigit(char character) { 
    return character >= '0' && character <= '9'; 
    }

  bool isLeftParthensis(char character) { return character == '('; }

  bool isRightParthensis(char character) { return character == ')'; }


  // offical solution
  class Test {
   public:
    string countOfAtoms(string formula) {
      int i = 0, n = formula.length();

      auto parseAtom = [&]() -> string {
        string atom;
        atom += formula[i++];  // 扫描首字母
        while (i < n && islower(formula[i])) {
          atom += formula[i++];  // 扫描首字母后的小写字母
        }
        return atom;
      };

      auto parseNum = [&]() -> int {
        if (i == n || !isdigit(formula[i])) {
          return 1;  // 不是数字，视作 1
        }
        int num = 0;
        while (i < n && isdigit(formula[i])) {
          num = num * 10 + int(formula[i++] - '0');  // 扫描数字
        }
        return num;
      };

      stack<unordered_map<string, int>> stk;
      stk.push({});
      while (i < n) {
        char ch = formula[i];
        if (ch == '(') {
          i++;
          stk.push({});  // 将一个空的哈希表压入栈中，准备统计括号内的原子数量
        } else if (ch == ')') {
          i++;
          int num = parseNum();  // 括号右侧数字
          auto atomNum = stk.top();
          stk.pop();  // 弹出括号内的原子数量
          for (auto &[atom, v] : atomNum) {
            stk.top()[atom] +=
                v * num;  // 将括号内的原子数量乘上 num，加到上一层的原子数量中
          }
        } else {
          string atom = parseAtom();
          int num = parseNum();
          stk.top()[atom] += num;  // 统计原子数量
        }
      }

      auto &atomNum = stk.top();
      vector<pair<string, int>> pairs;
      for (auto &[atom, v] : atomNum) {
        pairs.emplace_back(atom, v);
      }
      sort(pairs.begin(), pairs.end());

      string ans;
      for (auto &p : pairs) {
        ans += p.first;
        if (p.second > 1) {
          ans += to_string(p.second);
        }
      }
      return ans;
    }
  };
};

int main() {
  Solution solve;
  string result =
      solve.countOfAtoms("(((U42Se42Fe10Mc31Rh49Pu49Sb49)49V39Tm50Zr44Og6)33((W2Ga48Tm14Eu46Mt12)23(RuRnMn11)7(Yb15Lu34Ra19CuTb2)47(Md38BhCu48Db15Hf12Ir40)7CdNi21(Db40Zr24Tc27SrBk46Es41DsI37Np9Lu16)46(Zn49Ho19RhClF9Tb30SiCuYb16)15)37(Cr48(Ni31) 25(La8Ti17Rn6Ce35)36(Sg42Ts32Ca)37Tl6Nb47Rh32NdGa18Cm10Pt49(Ar37RuSb30Cm32Rf28B39Re7F36In19Zn50)46)38(Rh19Md23No22PoTl35Pd35Hg)41)50");
  return 0;
}