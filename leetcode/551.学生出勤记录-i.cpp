/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        bool ok = true;
        int cnt = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == 'A') {
                cnt += 1;
            }
            if(s[i] == 'L' && i+2 < s.size() && s[i]==s[i+1]&&s[i+1]==s[i+2])
            {
                ok = false;
                break;
            }
        }
        if (cnt >= 2) ok = false;
        return ok;
    }
};
// @lc code=end

