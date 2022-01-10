/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 *
 * https://leetcode-cn.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (37.41%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    34K
 * Total Submissions: 91K
 * Testcase Example:  '"112358"'
 *
 * 累加数 是一个字符串，组成它的数字可以形成累加序列。
 * 
 * 一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。
 * 
 * 给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。
 * 
 * 说明：累加序列里的数，除数字 0 之外，不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入："112358"
 * 输出：true 
 * 解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入："199100199"
 * 输出：true 
 * 解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 35
 * num 仅由数字（0 - 9）组成
 * 
 * 
 * 
 * 
 * 进阶：你计划如何处理由过大的整数输入导致的溢出?
 * 
 */

// @lc code=start
class Solution {
public:
    long long s[40][40];
    bool dfs(long long p, long long q, int st, string& a) {
        // cout<<p<<" "<<q<<" "<<st<<endl;
        int n = a.size();
        if(st+1==n) return true;
        bool ret = false;
        long long sum = p + q;
        for (int i=1;i<=n/2&&(st+i)<n;i++) {
            if(a[st+1]=='0'&&i!=1) return false;
            // cout<<p<<" "<<q<<" sum="<<sum<<", "<<st<<" "<<s[st+1][st+i]<<", n/2="<<n/2<<endl;
            if(s[st+1][st+i]==sum) {
                ret = dfs(q, s[st+1][st+i], st+i, a);
                if(ret) return true;
            } else if(s[st+1][st+i]>sum) {
                return false;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string a) {
        int n = a.size();
        if(n<3) return false;
        memset(s, 0, sizeof(s));
        for(int i=0;i<n;i++) {
            long long p=0;
            s[i][i]=a[i]-'0';
            for(int j=1;j<=n/2&&i+j<n;j++) {
                s[i][i+j] = s[i][i+j-1]*10+a[i+j]-'0';
                // cout<<i<<" "<<i+j<<" "<<s[i][i+j]<<endl;
            }
        }
        bool ret=false;
        
        for(int i=0;i<=n/2;i++) {
            if(a[0]=='0'&&i!=0) break;
            for(int j=1;j<=n/2&&(i+j)<n;j++) {
                if(a[i+1]=='0'&&j!=1) break;
                if(i+j==n-1) continue;
                ret = dfs(s[0][i], s[i+1][i+j], i+j, a);
                if(ret) return true;
            }
        }
        return ret;
    }
};
// @lc code=end

