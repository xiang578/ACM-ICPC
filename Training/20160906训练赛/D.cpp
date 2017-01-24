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

void getfail(char *p,int *f)
{
    int m=strlen(p);
    f[0]=0;
    f[1]=0;
    for(int i=1; i<m; i++)
    {
        int j=f[i];
        while(j&&p[i]!=p[j]) j=f[j];
        f[i+1]=p[i]==p[j]?j+1:0;
    }
}

int kmp(char *t,char *p,int *f)
{
    int cnt=0,i,j,n=strlen(t),m=strlen(p);
    getfail(p,f);
    for(i=0,j=0; i<n; i++)
    {
        while(j&&p[j]!=t[i]) j=f[j];
        if(p[j]==t[i]) j++;
        if(j==m)
        {
            cnt++;
            j=f[j];
        }
    }
    return cnt;
}

int main()
{
    char t[1024],p[1024];
    int f[1024];
    while(~scanf("%s",t))
    {
        if(strcmp(t,"#")==0) break;
        scanf("%s",p);
        printf("%d\n",kmp(t,p,f));
    }
    return 0;
}
