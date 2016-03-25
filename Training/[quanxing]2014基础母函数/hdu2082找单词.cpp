#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int _max = 10001;
int c1[_max], c2[_max];
int a[30];

int main()
{
    int n,up,ans;
    int i, j, k,_;
    scanf("%d",&_);
    while(_--)
    {
        for(i=1;i<=26;i++)
        {
            scanf("%d",a+i);
        }
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0; i<=a[1]; ++i)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        n=up=a[1];
        for(i=2; i<=26; ++i)
        {
            for(j=0; j<=n; ++j)
            {
                if(!c1[j]) continue;
                for(k=0; k<=a[i]*i; k+=i)
                {
                    c2[j+k] += c1[j];
                    up=max(up,j+k);
                }
            }
            n=up;
            if(n>=50) n=50;
            for(j=0; j<=n; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        ans=0;
        for(i=1; i<=50; i++)
        {
            //if(c1[i]) printf("%d %d\n",i,c1[i]);
            ans+=c1[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
