/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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

int a[1024];
vector<int>ans;
int prime(int x)
{
    if(x==1) return 0;
    if(x==2||x==3) return 1;
    for(int i=2; i*i<=x; i++)
        if(x%i==0) return 0;
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0; i<n; i++)
    {
        if(a[i]==1) ans.push_back(a[i]);
        else if(ans.size()==0) ans.push_back(a[i]);
        else
        {
            for(int j=0; j<ans.size(); j++)
            {
                if(prime(a[i]+ans[j])==0)  break;
                if(j==ans.size()-1)
                {
                    ans.push_back(a[i]);
                    break;
                }
            }
        }
    }
    vector<int>ans2;
    ans2.clear();
    for(int i=0; i<n; i++)
    {
        if(a[i]==1) continue;
        for(int j=i+1; j<n; j++)
        {
            if(prime(a[i]+a[j])==1)
            {
                ans2.push_back(a[i]);
                ans2.push_back(a[j]);
                break;
            }
        }
        if(ans2.size()==2) break;
    }
    if(ans.size()>=ans2.size())
    {
        printf("%d\n",ans.size());
        for(int i=0; i<ans.size(); i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    else
    {
        printf("2\n%d %d\n",ans2[0],ans2[1]);
    }
    return 0;
}
