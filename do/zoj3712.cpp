#include<bits/stdc++.h>
using namespace std;

int main()
{
    int _,a,b,c,mx,mi,i;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&a,&b,&c);
        mi=mx=0;
        for(i=0;i<c;i++)
            mi+=50*(i*2+1);
        for(i=c;i<c+b;i++)
            mi+=100*(i*2+1);
        for(i=c+b;i<c+b+a;i++)
            mi+=300*(i*2+1);

        for(i=a+b;i<a+b+c;i++)
            mx+=50*(i*2+1);
        for(i=a;i<a+b;i++)
            mx+=100*(i*2+1);
        for(i=0;i<a;i++)
            mx+=300*(i*2+1);
        printf("%d %d\n",mx,mi);
    }
    return 0;
}
