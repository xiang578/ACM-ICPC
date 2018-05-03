#include<stdio.h>
int main()
{

    int n,i,a[1200]={1,2,3};
    for(i=3;i<1020;i+=3)
    {
        a[i]=a[i-3]+1;
        a[i+1]=a[i-2]+1;
        a[i+2]=a[i-1]+1;
    }
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        int s=0;
        for(i=0;i<n;i++)
        {
            s+=a[i];
        }
        printf("%d\n",s);
    }
    return 0;
}
