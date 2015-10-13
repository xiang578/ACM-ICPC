#include<stdio.h>
int main()
{
    int n,a;
    while(~scanf("%d",&n))
{
    int i,t=1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a%13==0&&t==1) {printf("%d",a);t++;}
        else if(a%13==0) printf(" %d",a);
    }
    printf("\n");
}
return 0;
}
