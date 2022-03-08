#include <vector>
#include <queue>
using namespace std;
/*
设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
请实现 KthLargest 类：
KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
*/

class KthOfficialLargets {
    public:
        priority_queue<int, vector<int>, greater<int>> q;
        int k;
        KthOfficialLargets(int k, vector<int>& nums) {
            this->k = k;
            for (auto& x : nums) {
                add(x);
            }
        }

        int add(int val) {
            q.push(val);
            if (q.size() > k) {
                q.pop();
            }
            return q.top();
        }
};

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->maxNumber = k;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        int size = largetstVector.size();
        if ( size < maxNumber) {
            // insert
            largetstVector.push_back(val);
            reshapeCache();
        } else {
            // compare
            if (val <= largetstVector[size - 1]) {
                return largetstVector[size -1];
            } else {
                largetstVector[size - 1] = val;
                reshapeCache();
                }
            }
        return largetstVector[size - 1];
        }

    void reshapeCache() {
        int before = largetstVector.size() - 2;
        int current = largetstVector.size() - 1;
        while ( before >= 0 && largetstVector[current] > largetstVector[before]) {
            int temp = largetstVector[before];
            largetstVector[before] = largetstVector[current];
            largetstVector[current] = temp;
            current--;
            before--;
        }
    }
private:
    vector<int> largetstVector; 
    int maxNumber;
};

int main() {
    vector<int> test = {4,5,8,2,5,6,7};
    KthLargest larget(4, test);
    vector<int> toAdd = {3, 5, 10, 9, 4};
    for (int i = 0; i < toAdd.size(); i++) {
        int result = larget.add(toAdd[i]);
        printf("result: %i \n", result);
    }
    return 0;
}