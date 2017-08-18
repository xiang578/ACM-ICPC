#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,w[10000],h[10000];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",h+i);
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",w+i);
	sort(h,h+n);
	sort(w,w+m);
	int cnt=0;
	int j=0;
	for(int i=0;i<n;i++)
	{
		while(j<m&&w[j]<h[i])
		{
			j++;
		}
		if(j==m) break;
		j++;
		cnt++;
	}
	printf("%d\n",cnt);
    return 0;
}