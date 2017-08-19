#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

// 解法一: 使用动态规划
// A sequence of number is called arithmetic(等差数列) if it consists of at least three elements and if the difference between any two consecutive elements is the same.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), res=0;
        vector<int> dp(n, 0);   // dp[i] 表示了以A[i]结尾的数组中有多少是等差的
        for(int i=2; i<n; i++) {    // 因为等差数列大于等于3 所以A[2]开始判断
            // 如果 A[i]-A[i-1] == A[i-1]-A[i-2] 则以A[i]结尾的数组中等差数列的个数的算法为
            //                                              1) 因为A[i]-A[i-1]和之前所有以A[i]结尾的等差数列的差相等, 所以那些以A[i-1]为等差数列的数列 也同样是以A[i]为结尾的等差数列 所以dp[i] = dp[i-1];
            //                                              2) 又 A[i-2], A[i-1] 之前不被算入dp[i-1]中, 出现了A[i]之后, A[i-2], A[i-1], A[i]也是一个新的等差数列, 所以dp[i] = dp[i-1]+1;
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                dp[i] = dp[i-1]+1;
            res += dp[i];   // 把以每个数字结尾的等差数组的个数相加 则为总个数;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> A{1,2,3,4};

    cout << s.numberOfArithmeticSlices(A);
    return 0;
}
