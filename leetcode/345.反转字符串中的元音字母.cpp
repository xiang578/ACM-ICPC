/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    int f(char c) {
        if (c == 'a' || c == 'A') return 1;
        if (c == 'e' || c == 'E') return 1;
        if (c == 'i' || c == 'I') return 1;
        if (c == 'o' || c == 'O') return 1;
        if (c == 'u' || c == 'U') return 1;
        return 0;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i<j) {
            while(i<j && f(s[i]) == 0) i++;
            if (i>=j) break;
            while(j>i && f(s[j]) == 0) j--;
            if(i>=j) break;
            // cout<<i<<" "<<j<<endl;
            swap(s[i], s[j]);
            i++;j--;
        }
        return s;
    }
};
// @lc code=end

