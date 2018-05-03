#include<stdio.h>
#include<string.h>
int c;
int ci[160];
int t[160];
bool j(int n,int m)
{
    int r=1,i,j;
    ci[1]=0;
    for(i=2,j=1;r<=n-2;i=i%n+1,j=j%m+1)
    {
        while(ci[i]==0) {i=i%n+1;}
        if(j%m==0)
        {
            if(i==2) return false;
            ci[i]=0;
            j=0;
            r+=1;
        }
    }
    if(ci[2]!=0) return true;
    else return false;
}

int main()
{
    int i;
    while(~scanf("%d",&c))
    {
        if(c==0) break;
        for(i=0;i<=c;i++) ci[i]=i;
        memcpy(t,ci,sizeof(ci));
        int m;
        for(m=1; ;m++)
        {
            memcpy(ci,t,sizeof(ci));
            if(j(c,m)) break;
        }
        printf("%d\n",m);
    }
    return 0;
}
