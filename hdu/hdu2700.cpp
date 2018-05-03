#include<bits/stdc++.h>
using namespace std;
char a[1024];

int main()
{
	while(~scanf("%s",a))
	{
		if(a[0]=='#') break;
		int cnt=0;
		int len=strlen(a);
		for(int i=0;i<len-1;i++)
		{
			if(a[i]=='1') cnt++;
			printf("%c",a[i]);
		}	
		if(a[len-1]=='e')
		{
			if(cnt%2==1) printf("1\n");
			else printf("0\n");
		}
		else
		{
			if(cnt%2==0) printf("1\n");
			else printf("0\n");
		}
	}	
	return 0;
}
