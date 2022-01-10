/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        columnNumber -= 1;
        whlie(columnNumber) {
            int t = columnNumber % 26;
            ans += 'a' + t;
            columnNumber/=26;
        }
        return ans;
    }
};
// @lc code=end

