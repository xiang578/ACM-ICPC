/*
 * @lc app=leetcode.cn id=1707 lang=cpp
 *
 * [1707] 与数组中元素的最大异或值
 */

// @lc code=start
class Solution {
public:
    struct E{
        int l,r,v;
    }e[7123456];
    int cnt;

    void build(int v, int k, int i) {
        e[i].v = min(e[i].v, v);
        if(k==-1) return;
        int t = v & (1<<k);
        if(t == 0) {
            if(e[i].l == -1) {
                cnt ++;
                e[i].l = cnt;
                e[cnt].l = -1;
                e[cnt].r = -1;
                e[cnt].v = 1e9+7;
            }
            build(v, k-1, e[i].l);
        }
        else {
            if(e[i].r == -1) {
                cnt ++;
                e[i].r = cnt;
                e[cnt].l = -1;
                e[cnt].r = -1;
                e[cnt].v = 1e9+7;
            }
            build(v, k-1, e[i].r);
        }
    }

    int query(int v, int m, int i, int k) {
        if (k==-1) return v^e[i].v;
        if(e[i].v > m) return -1;
        // cout<<v<<", k="<<k<<", v="<<e[i].v<<endl;
        int t = v & (1<<k);
        if (t==0) {
            if (e[i].r != -1 && e[e[i].r].v <= m) return query(v, m, e[i].r, k-1);
            else return query(v, m, e[i].l, k-1);
        }else {
            if (e[i].l != -1 && e[e[i].l].v <= m) return query(v, m, e[i].l, k-1);
            else return query(v, m, e[i].r, k-1);
        }

    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        e[0].l = -1;
        e[0].r = -1;
        e[0].v = 1e9+7;
        cnt = 0;
        for(auto i: nums) {
            build(i, 29, 0);
        }
        vector<int> ans;
        for(auto i: q) {
            ans.push_back(query(i[0], i[1], 0, 29));   
        }
        return ans;
    }
};
// @lc code=end

