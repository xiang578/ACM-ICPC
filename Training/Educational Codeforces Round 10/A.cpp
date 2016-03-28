/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************ */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long  h1,h2,a,b,now,ans;
    while(~scanf("%I64d%I64d%I64d%I64d",&h1,&h2,&a,&b))
    {
        now=h1;
        ans=0;
        now+=8*a;
        if(now>=h2) {printf("%I64d\n",ans);continue;}
        now-=12*b;
        if(a<=b&&12*a+now<h2) {printf("-1\n");continue;}
        while(1)
        {
            ans++;
            now+=12*a;
            if(now>=h2) break;
            now-=12*b;
         }
        printf("%I64d\n",ans);
    }
    return 0;
}
