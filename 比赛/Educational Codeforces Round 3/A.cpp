#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;


int cmp(int a,int b)
{
    return a>b;
}

int a[1024];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,n)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    int ans=0;
    rep(i,0,n)
    {
        if(m<=0) break;
        m-=a[i];
        ans++;
        //if(m<=0) break;
        //cout<<m<<endl;
    }
    printf("%d\n",ans);
    return 0;
}



