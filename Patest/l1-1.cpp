#include <stdio.h>
#include <string.h>
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
using namespace std;
string c[200];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,m;
    char s[2000];
    //memset(c,0,sizeof(c));
    scanf("%d",&n);
    getchar();
    gets(s);
    //n=4;
   	//s="This is a test case";
    m=strlen(s);
    int nlen = m;
    if(m%n!=0)
    {
    	nlen = (m/n+1)*n;
    	for(int i=m;i<nlen;i++)
    		s[i]=' ';
    	s[nlen]=0;
    }
    for(int i=0;i<n;i++)
    	c[i]="";
    //printf("%s#%d\n",s,nlen);
    int x=0,y=nlen/n-1;
    for(int i=0;i<nlen;i++)
    {
    	c[x]+=s[i];
    	//printf("%d %d#\n",x,y,c[x][y]);
    	x++;
    	if(x==n)
    	{

    		x=0;
    		y--;
    	}

    }
    for(int i=0;i<n;i++)
    {
    	reverse(c[i].begin(),c[i].end());
    	cout<<c[i]<<endl;
    }

    return 0;
}