/* ***********************************************
Author        :xiang578
Email         :xiang578@foxmail.com
Blog          :https://www.xiang578.com
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
// #include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=500 + 5;
const int M=1e6+10;


int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,l,r,s;
        int a[N];
        memset(a, 0, sizeof(a));
        scanf("%d%d%d%d", &n, &l, &r, &s);
        l--;
        r--;
        int x = r - l + 1;
        int sx = (1+x)*x/2;
        int mx = (n + n - x + 1) * x/2;
        if(s<sx||s>mx) {printf("-1\n");continue;}
        int t = (s-sx)%x==0?(s-sx)/x:(s-sx)/x+1;
        int now = (t+1+t+x)*(x)/2;
        int g = now-s;
        // printf("%d %d %d %d\n", s, sx, t, g);
        vector<int>ans1;
        for(int i=t+1;i<=t+x;i++) {
            int p = i;
            if(g!=0&&p-g>=1) {
                if(a[p-g]!=1) {p=p-g; g=0;}
            }
            a[p]=1;
            ans1.push_back(p);
            // cout<<p<<endl;
        }
        if(g!=0) {printf("-1\n");continue;}
        vector<int>ans;
        t = 1;
        for(int i=0;i<l;i++) {
            while(a[t]) t++;
            ans.push_back(t);
            t++;
        }
        for(int i=l;i<=r;i++) {
            ans.push_back(ans1[i-l]);
        }
        for(int i=r+1;i<n;i++) {
            while(a[t]) t++;
            ans.push_back(t);
            t++;
        }
        for(auto b:ans) {
            printf("%d ", b);
        }
        printf("\n");
    }
    return 0;
}