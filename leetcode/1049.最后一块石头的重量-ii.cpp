/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int dp[40][3123];
        memset(dp, 0, sizeof(dp));
        int sum = 0;
        for(auto aa:a) {
            sum += aa;
        }
        int ans = sum;
        dp[0][0] = 1;
        for(int i=0;i<a.size();i++) {
            for(int j=0;j<=sum;j++) {
                if(!dp[i][j]) continue;
                ans = min(ans, abs(sum - j - j));
                ans = min(ans, abs(sum - (j + a[i]) - (j + a[i])));
                dp[i+1][j] = 1;
                dp[i+1][j + a[i]] = 1;
            }
        } 
        return ans;
    }
};
// @lc code=end

