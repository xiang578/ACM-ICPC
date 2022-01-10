/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

// @lc code=start
class Solution {
public:
    int checkRecord(int n) {
        long long dp[123456][2][3];
        int mod = 1e9+7;
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1; 
        for (int i=1;i<=n;i++) {
            // no A
            dp[i][0][0] = (dp[i][0][0] + dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2])%mod;

            dp[i][0][1] = (dp[i][0][1] + dp[i-1][0][0])%mod;

            dp[i][0][2] = (dp[i][0][2] + dp[i-1][0][1])%mod;

            // A 
            dp[i][1][0] = (dp[i][1][0] + dp[i-1][1][0] + dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]+ dp[i-1][1][1] + dp[i-1][1][2])%mod;

            dp[i][1][1] = (dp[i][1][1] + dp[i-1][1][0])%mod;

            dp[i][1][2] = (dp[i][1][2] + dp[i-1][1][1])%mod;


        }
        long long ans = 0;
        for (int i=0;i<2;i++) {
            for(int j=0;j<3;j++) {
                ans = (ans + dp[n][i][j]) % mod;
            }
        }
        return ans % mod;
    }
};
// @lc code=end

