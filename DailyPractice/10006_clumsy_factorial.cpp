class Solution {
 public:
  int clumsy(int N) {
    int pairCount = N / 4;
    int remain = N - 4 * pairCount;
    if (pairCount == 0) {
      return caculateRemain(remain);
    }
    int result = 0;
    for (int pair = 0; pair < pairCount; pair++) {
      if (pair == 0) {
        result += caculatePair(N - pair * 4, N);
      } else {
        result -= caculatePair(N - pair * 4, N);
      }
    }
    return result - caculateRemain(remain);
  }

  int caculateRemain(int start) {
    if (start == 1) {
      return 1;
    }
    int result = 0;
    int index = 0;
    while (start - 1 >= 1) {
      if (index == 0) {
        result += start * (start-1);
      } else if (index == 1) {
        result = result / (start - 1);
      }
      start--;
      index++;
    }
    return result;
  }

  int caculatePair(int start, int origin) {
    if (start == origin) {
      return start * (start - 1) / (start - 2) + (start - 3);
    }
    return start * (start - 1) / (start - 2) - (start - 3);
  }
};

int main() {
  Solution solution;
  int result = solution.clumsy(10);
  return 0;
}