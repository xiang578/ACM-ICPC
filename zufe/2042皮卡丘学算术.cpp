#include<stdio.h>
int main()
{
    int t,a,b;
    while(~scanf("%d",&t))
    {
        while(t--){
        scanf("%d%d",&a,&b);
        a=a%100;b=b%100;
        int k=a+b;
        k=k%100;
        printf("%d\n",k);
    }
    }
        return 0;
}
