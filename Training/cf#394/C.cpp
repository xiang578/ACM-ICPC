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
char s[100][100];
int a[100][3];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    memset(a,0xff,sizeof a );
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]>='0'&&s[i][j]<='9')
            {
                if(a[i][0]==-1) a[i][0]=min(j,m-j);
                else a[i][0]=min(a[i][0],min(j,m-j));
            }
            else if(s[i][j]>='a'&&s[i][j]<='z')
            {
                if(a[i][1]==-1) a[i][1]=min(j,m-j);
                else a[i][1]=min(a[i][1],min(j,m-j));
            }
            else
            {
                if(a[i][2]==-1) a[i][2]=min(j,m-j);
                else a[i][2]=min(a[i][2],min(j,m-j));
            }
        }
        //printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    }
    int ans=mod;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            for(int k=0;k<n;k++)
            {
                if(i==k||k==j) continue;
                if(a[i][0]==-1||a[j][1]==-1||a[k][2]==-1) continue;
                ans=min(ans,a[k][2]+a[i][0]+a[j][1]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
