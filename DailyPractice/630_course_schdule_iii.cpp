#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    // 按照课程的结束时间,从小到大排序
    sort(courses.begin(), courses.end(),
         [](const vector<int>& c0, const vector<int>& c1) {
           return c0[1] < c1[1];
         });
    priority_queue<int> queue;
    int time = 0;
    for (auto course : courses) {
      // 可以选择当前时间
      if (time + course[0] <= course[1]) {
        time += course[0];
        queue.push(course[0]);
      } else if (!queue.empty() && queue.top() > course[0]) {
        time -= queue.top() - course[0];
        queue.pop();
        queue.push(course[0]);
      }
    }
    return queue.size();
  }
};

int main() {
  Solution solve;
  vector<vector<int>> test = {
      {100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
  int maxCount = solve.scheduleCourse(test);
  return 0;
}