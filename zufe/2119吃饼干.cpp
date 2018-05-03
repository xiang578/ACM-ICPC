#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int n,cnt;
    while(~scanf("%d",&n))
    {
        cnt=0;
        while(n!=0)
        {
            if(n>500) {n-=20; cnt++;}
            else if(100<n&&n<=500) {n-=10; cnt++;}
            else {n=0; cnt++;}
        }
        printf("%d\n",cnt);
    }
    return 0;
}
