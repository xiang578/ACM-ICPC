#include<stdio.h>
int main()
{
    const int n=8;
    const int m=4;
    int a[9]={0,1,2,3,4,5,6,7,8};
    int r=1;
    int i;
    int j;
    for(i=1,j=1;r<=7;i=i%n+1,j=j%m+1)
    {
        while(a[i]==0) {i=i%n+1;}
        if(j%m==0)
        {
            printf("a[%d]=%d\n",i,a[i]);
            a[i]=0;
            j=0;
            r+=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i+1]!=0) printf("%d\n",a[i+1]);
    }
    return 0;
}
