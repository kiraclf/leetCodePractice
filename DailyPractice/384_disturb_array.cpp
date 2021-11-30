#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 private:
  vector<int> orderedArray;
  vector<int> randomArray;

 public:
  /// Init.
  Solution(vector<int>& nums) {
    orderedArray = nums;
    randomArray = nums;
  }

  /// Return the ordered array.
  vector<int> reset() { return orderedArray; }

  /// Random array.
  vector<int> shuffle() {
    for (int i = 0; i < randomArray.size(); i++) {
      int randomIndex = rand() % (randomArray.size() - i);
      int temp = randomArray[randomIndex];
      randomArray[randomIndex] = randomArray[i];
      randomArray[i] = temp;
    }
    return randomArray;
  }
};

int main() {
  vector<int> test = {1, 2, 3};
  Solution solve(test);
  vector<int> res1 = solve.shuffle();
  vector<int> res2 = solve.reset();
  vector<int> res3 = solve.shuffle();
  return 0;
}