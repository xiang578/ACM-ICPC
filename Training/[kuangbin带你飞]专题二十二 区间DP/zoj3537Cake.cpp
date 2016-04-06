#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int top,s[10024];

struct data
{
    int x,y;
} p[10024],temp;

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

int pt,dp[1024][1024],c[1024][1024];

int cost(int i,int j)
{
    int t1=p[i].x+p[j].x;
    int t2=p[i].y+p[j].y;
    if(t1<0) t1=-t1;
    if(t2<0) t2=-t2;
    return t1*t2%pt;
}

int main()
{
    int n,i,j,k,u,r;
    while(~scanf("%d%d",&n,&pt))
    {
        for(i=0; i<n; i++) scanf("%d%d",&p[i].x,&p[i].y);
        u=0;
        for(i=0; i<n; i++)
        {
            if(p[i].y<p[u].y||((p[i].y==p[u].y)&&p[i].x<p[u].x))
                u=i;
        }
        temp=p[u];
        p[u]=p[0];
        p[0]=temp;
        qsort(&p[1],n-1,sizeof(int)*2,cmp);
        for(i=0; i<=2; i++) s[i]=i;
        top=2;
        for(i=3; i<n; i++)
        {
            while(corss(p[s[top-1]],p[s[top]],p[i])<=0) top--;
            s[++top]=i;
        }
        if(top!=n-1)
        {
            printf("I can't cut.\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                dp[i][j]=inf;
            dp[i][(i+1)%n]=0;
        }
        memset(c,0,sizeof(c));
        for(i=0; i<n; i++)
            for(j=i+2; j<n; j++)
                c[j][i]=c[i][j]=cost(s[i],s[j]);

        for(r=2;r<=n;r++)
        {
            for(i=0;i<=n-r;i++)
            {
                j=i+r-1;
                for(k=i+1;k<=j-1;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+c[i][k]+c[k][j]);
            }
        }
        printf("%d\n",dp[0][n-1]);
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

#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
int top,s[10024];

struct data
{
    int x,y;
} p[10024],temp;

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
    int m;
    data *p1,*p2;
    p1=(data *)a;
    p2=(data *)b;
    m=corss(p[0],*p1,*p2);
    if(m<0) return 1;
    else if(m==0&&(dis(p[0],*p1)<dis(p[0],*p2)))
        return 1;
    else return -1;
}

int pt,dp[1024][1024],c[1024][1024];

int cost(int i,int j)
{
    int t1=p[i].x+p[j].x;
    int t2=p[i].y+p[j].y;
    if(t1<0) t1=-t1;
    if(t2<0) t2=-t2;
    return t1*t2%pt;
}

int get(int s,int t)
{
    if(dp[s][t]!=inf) return dp[s][t];
    int ans=inf;
    for(int k=s+1;k<t;k++)
        ans=min(ans,get(s,k)+get(k,t)+c[s][k]+c[k][t]);
    return dp[s][t]=ans;
}

int main()
{
    int n,i,j,k,u,r;
    while(~scanf("%d%d",&n,&pt))
    {
        for(i=0; i<n; i++) scanf("%d%d",&p[i].x,&p[i].y);
        u=0;
        for(i=0; i<n; i++)
        {
            if(p[i].y<p[u].y||((p[i].y==p[u].y)&&p[i].x<p[u].x))
                u=i;
        }
        temp=p[u];
        p[u]=p[0];
        p[0]=temp;
        qsort(&p[1],n-1,sizeof(int)*2,cmp);
        for(i=0; i<=2; i++) s[i]=i;
        top=2;
        for(i=3; i<n; i++)
        {
            while(corss(p[s[top-1]],p[s[top]],p[i])<=0) top--;
            s[++top]=i;
        }
        if(top!=n-1)
        {
            printf("I can't cut.\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            for(j=i; j<n; j++)
                dp[i][j]=inf;
            dp[i][(i+1)%n]=0;
        }
        memset(c,0,sizeof(c));
        for(i=0; i<n; i++)
            for(j=i+2; j<n; j++)
                c[j][i]=c[i][j]=cost(s[i],s[j]);

        printf("%d\n",get(0,n-1));
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int top,s[10024];

struct data
{
    int x,y;
} p[10024],temp;

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

int pt,dp[1024][1024],c[1024][1024];

int cost(int i,int j)
{
    int t1=p[i].x+p[j].x;
    int t2=p[i].y+p[j].y;
    if(t1<0) t1=-t1;
    if(t2<0) t2=-t2;
    return t1*t2%pt;
}

int main()
{
    int n,i,j,k,u,r;
    while(~scanf("%d%d",&n,&pt))
    {
        for(i=0; i<n; i++) scanf("%d%d",&p[i].x,&p[i].y);
        u=0;
        for(i=0; i<n; i++)
        {
            if(p[i].y<p[u].y||((p[i].y==p[u].y)&&p[i].x<p[u].x))
                u=i;
        }
        temp=p[u];
        p[u]=p[0];
        p[0]=temp;
        qsort(&p[1],n-1,sizeof(int)*2,cmp);
        for(i=0; i<=2; i++) s[i]=i;
        top=2;
        for(i=3; i<n; i++)
        {
            while(corss(p[s[top-1]],p[s[top]],p[i])<=0) top--;
            s[++top]=i;
        }
        if(top!=n-1)
        {
            printf("I can't cut.\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                dp[i][j]=inf;
            dp[i][(i+1)%n]=0;
        }
        memset(c,0,sizeof(c));
        for(i=0; i<n; i++)
            for(j=i+2; j<n; j++)
                c[j][i]=c[i][j]=cost(s[i],s[j]);

        for(i=n-3;i>=0;i--)
            for(j=i+2;j<n;j++)
                for(k=i+1;k<=j-1;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+c[i][k]+c[k][j]);
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
*/

/*
²âÊÔÊý¾Ý£º
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
