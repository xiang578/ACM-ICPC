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
map<string,int>mp;
string a,b,c,ans;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas=0,_,n,cnt,ok;
    scanf("%d",&_);
    while(_--)
    {
        cnt=0;
        ok=1;
        scanf("%d",&n);
        cin>>a;
        cin>>b;
        cin>>ans;
        mp.clear();
        while(1)
        {
            cnt++;
            c="";
            for(int i=0;i<n;i++)
            {
                c+=b[i];
                c+=a[i];
            }
            if(c==ans) break;
            if(mp[c]==1)
            {
                ok=0;
                break;
            }
            mp[c]=1;
            a=b="";
            for(int i=0;i<n;i++)
            {
                a+=c[i];
            }
            for(int i=n;i<2*n;i++)
            {
                b+=c[i];
            }
        }
        if(ok==0) printf("%d -1\n",++cas);
        else printf("%d %d\n",++cas,cnt);
    }
    return 0;
}
