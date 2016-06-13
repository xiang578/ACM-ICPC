#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;

map<ll,pair<ll,ll> >mp;
ll bs(ll x)
{
	ll ret=1;
	ll l=1;
	ll r=1e5+10;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(mid*mid*mid<=x)
		{
			ret=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ret;
}
pair<ll,ll> operator+(pair<ll,ll>a,pair<ll,ll>b)
{
	return make_pair(a.first+b.first,a.second+b.second);
}

pair<ll,ll>dfs(ll x)
{
	if(mp.find(x)!=mp.end()) return mp[x];
	if(x==0) return mp[x]=make_pair(0,0);
	ll y=bs(x);
	ll y3=y*y*y;
	return mp[x]=max(dfs(x%y3)+make_pair(x/y3,x/y3*y3),dfs(y3-1)+make_pair(x/y3-1,(x/y3-1)*y3));
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	ll m;
	mp.clear();
	scanf("%lld",&m);
	pair<ll,ll>ans=dfs(m);
	printf("%lld %lld\n",ans.first,ans.second);
    return 0;
}
