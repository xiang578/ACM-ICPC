#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Solution {
public:
    int node[12345];
    int nx[12345][26];
    int now=1;

    void build(int index, vector<int>& a, int k) {
        if(nx[index][k]==-1) {
            nx[index][k] = now;
            node[now] = 0;
            for(int i=0;i<26;i++) {
                nx[now][i] = -1;
            }
            now++;
        }
        int next=nx[index][k];
        k+=1;
        if (k<a.size())
            build(next, a, k);
        else
            node[next] += 1
    }

    void get_ans(int i, vector<int>& a, int k, int st) {
        int ret = 0;
        if (a[k]>=st) ret += node[i];
        if (nx[i][k] != -1 && k < a.size()) {
            ret += get_ans(nx[i][k] a, k+1, st);
        }
        return ret;
    }

    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        node[0] = 0;
        for(int i=0;i<26;i++) {
            nx[0][i] = -1;
        }
        int a[27];
        for (int i=0; i < words.size(); i++) {
            for(int j=0;j<26;j++) a[j]=0;
            for(int k=0;k<words[i].size();k++) a[words[i][k]-'a']=1;
            vector<int>diff;
            for(int j=0;j<26;j++)
            {
                if(a[j]) diff.push_back(j)
            }
            build(0, diff, 0);
        }

        vector<int>ans;
        for (int i=0; i < puzzles.size(); i++) {
            for(int j=0;j<26;j++) a[j]=0;
            for(int k=0;k<puzzles[i].size();k++) a[puzzles[i][k]-'a']=1;
            int st = puzzles[i][0] - 'a';
            vector<int>diff;
            for(int j=0;j<26;j++)
            {
                if(a[j]) diff.push_back(j)
            }
            ans.push_back(get_ans(nx[0][diff[0]], diff, 0, st));
        }
        return ans;
    }
};

int main()
{

    return 0;
}