#include <vector>
using namespace std;
/*
N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 
计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 
一次交换可选择任意两人，让他们站起来交换座位。
人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2, 2N-1)。
这些情侣的初始座位  row[i] 是由最初始坐在第 i 个座位上的人决定的。
--- 例子
[0,2,1,3]
输出1
*/
/*
思路: ---- 没有思路
*/
class UnionSet {
    private:
        int* parent;
        int* size;
        int* cnt;
        int n;
    public:
        UnionSet(int n) : n(n) {
            parent = new int[n];
            size = new int[n];
            cnt = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
                cnt[i] = 0;
            }
        }

        int Find(int x) {
            if ( parent[x] != x) {
                parent[x] = Find(parent[x]);
            }
            return parent[x];
        }

        void Merge(int x, int y) {
            x = Find(x);
            y = Find(y);
            if ( x != y ) {
                if ( size[x] < size[y] ) {
                    swap(x, y);
                }
                parent[y] = x;
                size[x] += size[y];
            }
        }

        int GetCnt() {
            memset(cnt, 0, sizeof(int) * n);
            for (int i = 0; i < n; i++) {
                ++cnt[Find(i)];
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += max(cnt[i] - 1, 0);
            }
            return res;
        }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        UnionSet us(n/2);
        for (int i = 0; i < n; i+=2) {
            us.Merge(row[i] / 2, row[i+1]/2);
        }
        return us.GetCnt();
    }
};