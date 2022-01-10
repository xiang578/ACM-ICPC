/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
public:
    int countArrangement(int n) {
        int a[16][1<<n];
        memset(a, 0, sizeof(a));
        a[0][0] = 1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<(1<<n);j++) {
                for(int k=1;k<=n;k++) {
                    if (k%i!=0&&i%k!=0) continue;
                    if (j & (1<<(k-1))) continue;
                    a[i][j|(1<<(k-1))] += a[i-1][j];
                }
            }
        }
        return a[n][(1<<n)-1];
    }
};
// @lc code=end

