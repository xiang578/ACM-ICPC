#include<bits/stdc++.h>
using namespace std;

int top,s[10024];

struct data
{
    int x,y;
}p[10024],temp;

int corss(data a,data b,data c)
{
    return ((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}

double dis(data a,data b)
{
    int t=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(1.0*t);
}

int cmp(const void *a,const void  *b)
{
    double m;
    data *p1,*p2;
    p1=(data *)a;
    p2=(data *)b;
    m=corss(p[0],*p1,*p2);
    if(m<0) return 1;
    else if(m==0&&(dis(p[0],*p1)<dis(p[0],*p2)))
        return 1;
    else return -1;
}

int pt,dp[1024][1024];

int cost(int i,int j)
{
    int t1=p[i].x-p[j].x;
    int t2=p[j].y-p[j].y;
    if(t1<0) t1=-t1;
    if(t2<0) t2=-t2;
    return t1*t2%pt;
}

int main()
{
    int n,i,j,k,u,r;
    while(~scanf("%d%d",&n,&pt))
    {
        for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        if(n==3) {printf("0\n");continue;}
        u=0;
        for(i=0;i<n;i++)
        {
            if(p[i].y<p[u].y||((p[i].y==p[u].y)&&p[i].x<p[u].x))
                u=i;
        }
        temp=p[u];p[u]=p[0];p[0]=temp;
        qsort(&p[1],n-1,sizeof(int)*2,cmp);
        for(i=0;i<=2;i++) s[i]=i;
        top=2;
        for(i=3;i<n;i++)
        {
            while(corss(p[s[top-1]],p[s[top]],p[i])<=0) top--;
            s[++top]=i;
        }
        if(top<n) {printf("I can't cut.\n");continue;}
        for(i=1;i<=n;i++)
            dp[i][i]=0;
        for(r=2;r<=n;r++)
        {
            for(i=1;i<=n-r-1;i++)
            {
                int j=i+r-1;
                dp[i][j]=dp[i+1][j]+cost(i+1,j);

                for(k=i+1;k<j;k++)
                {
                    u=dp[i][k]+dp[k+1][j]+cost(i,k)+cost(k,j);
                    dp[i][j]=min(dp[i][j],u);
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
/*
测试数据：
3 3
0 0
1 1
0 2

4 100
0 0
1 0
0 1
1 1

4 100
0 0
3 0
0 3
1 1

OutPut:
0
1
I can't cut.
*/
