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
char a[M],b[M];
int c[M];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%s",a);
    scanf("%s",b);
    int n=strlen(a);
    int m=strlen(b);
    for(int i=n;i>0;i--)
    {
        a[i]=a[i-1];
    }
    for(int j=m;j>0;j--)
    {
        b[j]=b[j-1];
    }
    c[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='1') c[i]=c[i-1]+1;
        else c[i]=c[i-1];
        //printf("%c %d\n",a[i],c[i]);
    }
    ll ans=0;
    int l,r;
    for(int i=1;i<=m;i++)
    {
        if(i+n-1<=m) l=1;
        else l=n-(m-i);

        if(i>=n) r=n;
        else r=i;

        int k=c[r]-c[l-1];
        if(b[i]=='1') ans+=(r-l+1)-k;
        else ans+=k;
        //printf("%d %d %d %d %d\n",k,l,r,c[r],c[l-1]);
    }
    cout<<ans<<endl;
    return 0;
}
