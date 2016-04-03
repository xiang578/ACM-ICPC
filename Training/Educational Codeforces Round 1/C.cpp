#include<bits/stdc++.h>
using namespace std;
typedef long double ldb;
const ldb pi=3.1415926535897932384626433832795028841971;

struct node
{
    int id;
    ldb arc;
    bool operator < (const node &a1) const
    {
        return arc<a1.arc;
    }
};

vector<node>v;

int main()
{
    int n,i,ans;
    double x,y;
    ldb mi=1e9;
    scanf("%d",&n);
    v.resize(n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&x,&y);
        v[i].id=i+1;
        v[i].arc=atan2(y,x);
    }
    sort(v.begin(),v.end());
    v.push_back(v[0]);
    v[n].arc+=2*pi;
    for(i=0;i<n;i++)
    {
        if(mi>v[i+1].arc-v[i].arc)
        {
            mi=v[i+1].arc-v[i].arc;
            ans=i;
        }
    }
    printf("%d %d\n",v[ans].id,v[ans+1].id);
    return 0;
}
