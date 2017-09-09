#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    查找一个数组 nums[] 中是否存在一些数字的和等于某个值
    例如{1,5,11,5}中是否存在某个子集 和为11
    问题类似与0/1背包问题, 从背包中选择数 求和

    dp[i][j] 表明前i个数的子集中是否有和为j的子集
        1) dp[i][j] 可以由 dp[i-1][j] 得到 : 如果前i-1个数中存在子集它的和为j 则前i个数中也存在
        2) dp[i][j] 也可以由 dp[i-1][j-nums[i]] 得到 : 如果前i-1个数中存在子集它的和为 j-nums[i] 则可有前i-1个数的子集再加
           上nums[i]得到j

        所以 dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0, n=nums.size();
        for(int x:nums) sum += x;
        if(sum % 2) return false;

        sum = sum/2;
        vector<vector<int> > dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int j=1; j<=sum; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++) dp[i][0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i]) dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i]]);
            }
        }

        return dp[n][sum];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100};

    cout << s.canPartition(v);
    return 0;
}
