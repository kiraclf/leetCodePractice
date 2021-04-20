class Solution {
 public:
  bool isUgly(int n) {
    if ( n == 1) {
      return true;
    }
    if ( n == 0) {
      return false;
    }
    int remain = n;
    while (remain != 1) {
      if (remain % 5 == 0) {
        remain = remain / 5;
      } else if (remain % 3 == 0) {
        remain = remain / 3;
      } else if (remain % 2 == 0){
        remain = remain / 2;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sovle;
  bool result = sovle.isUgly(8);
  return 0;
}