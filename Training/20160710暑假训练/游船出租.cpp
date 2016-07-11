#include<bits/stdc++.h>
using namespace std;
int use[1024],h[1024],m[1024];
int t,ans;
char s[1024];
int main()
{
    int k,th,tm;
    memset(use,0,sizeof(use));
    ans=t=0;
    while(~scanf("%d",&k))
    {
        if(k==-1) break;
        scanf("%s",s);
        scanf("%d:%d",&th,&tm);
        if(k==0)
        {
            double a1=1.0*ans/t;
            if(t==0) a1=0;
            printf("%d %.0f\n",t,a1);
            memset(use,0,sizeof(use));
            ans=t=0;
        }
        if(s[0]=='S')
        {
            h[k]=th;
            m[k]=tm;
            use[k]=1;
        }
        else
        {
            if(use[k]==0) continue;
            t++;
            ans+=(th*60+tm)-(h[k]*60+m[k]);
        }
    }
    return 0;
}
