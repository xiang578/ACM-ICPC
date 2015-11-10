#include<stdio.h>
int main()
{
    int i,n;
    int a[300001]={1,1,2};
    for(i=3;i<300001;i++)
    {
        a[i]=a[i-1]*a[i-2];
    }
    while(~scanf("%d",&n))
    {

            printf("%d\n",a[n]%10007);
    }
    return 0;
}
