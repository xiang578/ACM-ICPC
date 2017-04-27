#include <bits/stdc++.h>
using namespace std;
struct  name
{
	int a,b,id;
}p[123456];
int cmp(name n1,name n2)
{
	return n1.a>n2.a;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {p[i].id=i+1;cin>>p[i].a;}
	for(int i=0;i<n;i++) {p[i].id=i+1;cin>>p[i].b;}
	sort(p,p+n,cmp);
	if(n%2==0) {p[n].a=0;p[n].b=0;}
	printf("%d\n",n/2+1);
	std::vector<int> v;
	v.push_back(p[0].id);
	for(int i=1;i<n;i+=2)
	{
		if(p[i].b>p[i+1].b) v.push_back(p[i].id);
		else v.push_back(p[i+1].id);
	}
	for(int i=0;i<v.size();i++)
	{
		printf("%d ",v[i]);
	}
	return 0;
}
