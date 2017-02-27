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
int n,l,r;
struct node
{
    int id;
    int a;
    int p;
    int b;
}t[M];

int cmp(node n1,node n2)
{
    return n1.p>n2.p;
}

int cmp2(node n1,node n2)
{
    return n1.id<n2.id;
}
map<int,int>mp;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)
    {
        t[i].id=i;
        cin>>t[i].a;
    }
    for(int i=0;i<n;i++)
    {
        cin>>t[i].p;
    }
    int ok=1;
    sort(t,t+n,cmp);
    mp.clear();
    int c=r+1;
    for(int i=0;i<n;i++)
    {
        c--;
        int k=c+t[i].a;
        if(k<l) {ok=0;break;}
        if(k>r) k=r;
        t[i].b=k;
        c=k-t[i].a;
    }
    if(!ok) puts("-1");
    else
    {
        sort(t,t+n,cmp2);
        for(int i=0;i<n;i++) printf("%d ",t[i].b);
    }
    return 0;
}
