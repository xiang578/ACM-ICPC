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
const int N=1e5+10;
const int M=1e4+10;
struct node
{
    string s;
    int id,a;
};
vector<node>g[M];
int cmp(node n1,node n2)
{
    return n1.a>n2.a;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        node t;
        cin>>t.s>>t.id>>t.a;
        g[t.id].push_back(t);
    }
    for(int i=1;i<=m;i++)
    {
        sort(g[i].begin(),g[i].end(),cmp);
        if(g[i].size()<=2)
        {
            if(g[i][0].s<g[i][1].s) cout<<g[i][0].s<<" "<<g[i][1].s<<endl;
            else cout<<g[i][1].s<<" "<<g[i][0].s<<endl;
        }
        else
        {
            if(g[i][1].a==g[i][2].a) cout<<"?"<<endl;
            else if(g[i][0].s<g[i][1].s) cout<<g[i][0].s<<" "<<g[i][1].s<<endl;
            else cout<<g[i][1].s<<" "<<g[i][0].s<<endl;
        }
    }
    return 0;
}
