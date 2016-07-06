#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int n,a[10000],maxx,t,i,frist,last,refrist;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        t=refrist=0;
        frist=last=maxx=-1;
        for(i=0;i<n;i++)
        {
            t+=a[i];
            if(t<0) {t=0;refrist=i+1;}
            else{
            if(t>maxx)
            {
                maxx=t;
                frist=refrist;
                last=i;
            }
            else if(t==maxx)
            {
                if(i+refrist<frist+last)
                {
                    frist=refrist;
                    last=i;
                }
            }
            }
        }
        if(frist==-1) printf("0 %d %d\n",a[0],a[n-1]);
        else printf("%d %d %d\n",maxx,a[frist],a[last]);
    }
    return 0;
}
