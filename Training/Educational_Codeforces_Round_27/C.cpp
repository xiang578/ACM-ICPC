/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
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
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
const int M=1e6+10;

vector<pair<int,int> >v;

bool cmp(const pair<int,int> a, const pair<int,int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    rep(i,0,n)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        v.push_back(make_pair(l,r));
    }
    sort(v.begin(),v.end(),cmp);
    int a = -1, b = -1, ok = 1;
    for (int i = 0; i < v.size(); i++) {
        if (a > b)
            swap(a,b);
        if (b < v[i].first)
            b = v[i].second;
        else if(a < v[i].first)
            a = v[i].second;
        else {
            ok = 0;
            break;
        }
    }
    if (ok) puts("YES");
    else puts("NO");
    return 0;
}
