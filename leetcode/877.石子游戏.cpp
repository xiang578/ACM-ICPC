/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int dp[512][512];
        int n=p.size();
        for(int i=0;i<n;++i) dp[i][i] = -p[i];
        for(int i=1;i<n;++i) {
            for(int j=0;j+i<n;j++) {
                if(i%2) {
                    dp[j][j+i] = max(dp[j+1][j+i]+p[j],dp[j][j+i-1]+p[j+i]);
                }else {
                    dp[j][j+i] = min(dp[j+1][j+i]-p[j],dp[j][j+i-1]-p[j+i]);
                }
            }
        } 
        if(dp[0][p.size()-1]>0) return true;
        else return false; 
    }
};
// @lc code=end

