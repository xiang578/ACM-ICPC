#include<stdio.h>
int main()
{
    int a,n,i,m;
    int s;
    while (scanf("%d%d",&a,&n)!=EOF)
    {
        s=0;m=a;
        for (i=0;i<n;i++) {s+=m;m=m*10+a;}
        printf ("%d\n",s);
    }
 return 0;
}
