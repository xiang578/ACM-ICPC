#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    double a,b;
    while(~scanf("%d",&n))
    {
        double sum=0;
        for(int i=0;i<n;i++) {scanf("%lf",&a);sum+=a;}
        scanf("%d",&m);
        for(int i=0;i<m;i++) {scanf("%lf",&b);}
        if(n==m)  {if(sum==0)printf("0.00\n");else printf("inf\n");}
        else printf("%.2f\n",sum/(n-m));
    }
    return 0;
}
