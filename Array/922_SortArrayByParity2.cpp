/**
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
 * You may return any answer array that satisfies this condition.
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            int current = A[i];
            if ((A[i] % 2) == (i % 2)) {
                continue;
            } else {
                int nextIndex = i + 1;
                while ( nextIndex < A.size() && (A[nextIndex] % 2 != i % 2)) {
                    nextIndex++;
                }
                exchange(i, nextIndex, A);
            }
        }
        return A;
    }

    /**
     * 官方题解的思路
     * 维护一个 j 表示计数的下表
     * 遍历偶数下标，如果其值是奇数则从奇数下标中找出一个偶数交换位置(妙啊)
    */
    vector<int> official(vector<int>& A) {
        int n = A.size();
        int j = 1;
        for (int i = 0; i < n; i += 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }   
        return A;
    }

    void exchange(int indexA, int indexB, vector<int> &A) {
        int temp = A[indexA];
        A[indexA] = A[indexB];
        A[indexB] = temp;
    }
};

