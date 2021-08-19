/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    int f(char c) {
        if (c == 'a') return 1;
        if (c == 'e') return 1;
        if (c == 'i') return 1;
        if (c == 'o') return 1;
        if (c == 'u') return 1;
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
            swap(s[i], s[j]);
        }
        return s;
    }
};
// @lc code=end

