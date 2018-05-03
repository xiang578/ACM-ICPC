#include<stdio.h>
#include<math.h>
int prime(int x)
{
    int k=sqrt(x),i;
    for(i=2;i<k;i++)
    {
        if(x%i==0)
            break;
    }
    if(i>k) return 1;
    else return 0;
}
int main()
{
    int m,n,i,s;
    while(~scanf("%d%d",&m,&n))
    {
        s=0;
        for(i=m;i<=n;i++)
        {
            if(prime(i)==1) s+=i;
        }
        printf("%d\n",s);
    }
    return 0;
}
