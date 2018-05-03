#include<stdio.h>
int main()
{
    int m,a,n,t,i,s;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        scanf("%d",&n);
        m=9999999;
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            s+=a;
            if(m>a&&a!=0) m=a;
        }
        printf("%d\n",s-m);
    }
    return 0;
}
