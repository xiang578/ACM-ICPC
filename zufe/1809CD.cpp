#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int a,b,t,i,cd[100000],m,cnt;
    while(~scanf("%d %d\n",&a,&b))
    {
        if(a==0&&b==0) break;
        memset(cd,0,sizeof(cd));
        for(i=0;i<a;i++)
        {
            scanf("%d",&t);
            cd[t]++;
        }
        cnt=0;
        for(i=0;i<b;i++)
        {
            scanf("%d",&t);
            cd[t]++;
            if(cd[t]>1) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
#include <string.h>
#include <stdio.h>

int s[1000005];

int bin(int x,int n)
{
    int l,h,m;
    l = 0;
    h = n-1;
    m = (l+h/2);
    while(l<=h)
    {
        m = (l+h)/2;
        if(x<s[m])
        h = m-1;
        else if(x>s[m])
        l = m+1;
        else
        return 1;
    }
    return 0;
}

int main()
{
    int n,m,i,j,a;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        for(i = 0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        int cnt = 0;
        for(i = 0;i<m;i++)
        {
            scanf("%d",&a);
            cnt+=bin(a,n);
        }
        printf("%d\n",cnt);
    }

    return 0;
}
*/
