#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    double a,b,n,s,t;
    int i;
    while(~scanf("%lf",&n))
    {
        if(n==-1) {printf("the end.\n");break;}
        s=0,a=1,b=2;
        for(i=0;7.7*s<n;i++)
        {
            s+=a/b;
            t=b;
            b=a+b;
            a=t;
        }
        printf("%d\n",i);
    }
    return 0;
}
