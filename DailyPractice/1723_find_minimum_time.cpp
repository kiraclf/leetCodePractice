#include <vector>
using namespace std;
/*
将一个整数数组分成k份,使每份的和最小
*/
class Solution {
 private:
  int maxValue;
  vector<int> jobs;
  int workerNumber;
 public:
  int minimumTimeRequired(vector<int>& jobs, int k) {
    // initialize
    workerNumber = k;
    this->jobs = jobs;
    maxValue = INT_MAX;
    vector<int> workerCost(k, 0);
    // dfs
    smallestDfs(0, workerCost, 0, 0);
    // return
    return maxValue;
  }

  void smallestDfs(int jobIndex, vector<int> &jobCost, int currentMax, int usedCount) {
    // terminator
    if (currentMax >= maxValue) {
      // current larger than before smallest.
      return;
    }
    if (jobIndex == jobs.size()) {
      maxValue = min(currentMax, maxValue);
      return;
    }
    // 此处剪枝只是为了优先生成一个小的值,从而进行剪枝
    if (usedCount < jobCost.size()) {
      // 有空闲的直接使用
      jobCost[usedCount] += jobs[jobIndex];
      int costMax = 0;
      for (auto job : jobCost) {
        costMax = max(job, costMax);
      }
      smallestDfs(jobIndex + 1, jobCost, costMax, usedCount+1);
      jobCost[usedCount] -= jobs[jobIndex];
    }
    // 此处进行另一次剪枝
      for (int i = 0; i < usedCount; i++) {
        // process
        jobCost[i] += jobs[jobIndex];
        // drill down
        int costMax = 0;
        for (auto job : jobCost) {
          costMax = max(job, costMax);
        }
        smallestDfs(jobIndex + 1, jobCost, costMax, usedCount);
        // clean
        jobCost[i] -= jobs[jobIndex];
      }
  }
};