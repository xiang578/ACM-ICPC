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
#include <stack>
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,t,s,sp,ov,ans;
    stack<int>st;
    scanf("%d",&n);
    sp=0;
    ov=0;
    ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d",&s);
            sp=s;
            while(!st.empty()&&st.top()<sp)
            {
                ans+=1;
                st.pop();
            }
        }
        else if(t==2)
        {
            ans+=ov;
            ov=0;
        }
        else if(t==3)
        {
            scanf("%d",&s);
            if(sp>s) {ans++;continue;}
            st.push(s);
        }
        else if(t==4)
        {
            ov=0;
        }
        else if(t==5)
        {
            while(!st.empty()) st.pop();
        }
        else if(t==6)
        {
            ov++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
