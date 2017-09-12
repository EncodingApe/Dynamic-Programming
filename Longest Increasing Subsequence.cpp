#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

/*
    dp[i] 代表nums[0...i]中 以nums[i]为结尾的序列最长为多少
    dp[i] 就等于 MAX{dp[j]+1} 0<=j<n && nums[j] < nums[i]
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if(n == 0) return 0;

        vector<int> dp(n, 1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(v);
    return 0;
}
