#include<stdio.h>
int main()
{
    int n,a[100],i;
    double s;
    while(~scanf("%d",&n))
    {
        s=0;
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        s=1.0*s/n;
        printf("%.2f\n",s);
    }
    return 0;
}
