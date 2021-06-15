/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
extern int guess(int num);
class Solution {
 public:
  int guessNumber(int n) {
    int start = 1;
    int end = n;
    while (start < end) {
      int mid = start + (end - start) / 2;
      int result = guess(mid);
      if (result == 0) {
        return result;
      } else if (result == 1) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return start;
  }
};