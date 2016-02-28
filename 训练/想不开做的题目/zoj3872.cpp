#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int a[40];
int b[100000+5];

int get(int x)
{
    int i=0;
    while(x)
    {
        x/=2;
        i++;
    }
    return i-1;
}

int main()
{
    int n,_,ans,t,i,j,cnt;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        cnt=0;
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            a[get(b[i])]++;
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            t=b[i];
            j=0;
            while(t)
            {
                if(t%2==0) ans+=a[j];
                t/=2;
                j++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
