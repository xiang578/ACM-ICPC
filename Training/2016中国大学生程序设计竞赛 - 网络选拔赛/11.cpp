#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

char num[maxn];
int flag[30];

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		scanf("%s",num);
		printf("Case #%d: ",cas++);
		memset(flag,0,sizeof(flag));
		int n=strlen(num);
		int cnt=0;
		for(int i=0;i<n;i++)
		{
		    if(cnt==26) break;
		    if(flag[num[i]-'a']==0)
			flag[num[i]-'a']=1,cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
