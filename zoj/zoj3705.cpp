#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;

struct node
{
    string name;
    double pts;
}p[1024];

double a[10000];
int b[1000];
int isprime(int x)
{
    if(x==1) return 0;
    if(x==2) return 1;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return 0;
    return 1;
}

int cmp1(int x,int y)
{
    return x>y;
}
int cmp(node a,node b)
{
    //if(fabs(a.pts-b.pts)<=eps)
    //    return a.name<b.name;
    //else
        return a.pts>b.pts;
}

int main()
{
    string s1,s2,s3;
    map<string,int>mp;
    int i,j,n,m,_,r,s,q,x,c,y,t;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        mp.clear();
        scanf("%d",&r);
        for(i=0;i<r;i++)
        {
            scanf("%d",&y);
            a[y]=2.5;
        }
        scanf("%d",&s);
        for(i=0;i<s;i++)
        {
            scanf("%d",&y);
            a[y]=1.5;
        }
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            cin>>s1;
            //cout<<s1<<endl;
            scanf("%d",&y);
            if(y==1) y=36;
            else if(y==2) y=27;
            else if(y==3) y=18;
            else y=0;
            mp[s1]+=y;
        }
        for(i=0;i<n;i++)
        {
            //printf("%d\n",i);
            cin>>s1>>s2>>s3;
            p[i].name=s1;
            p[i].pts=mp[s2];
            //printf("   %d\n",mp[s2]);
            if(s3=="F") p[i].pts+=33;
            scanf("%d%d",&x,&y);
            for(j=0;j<x;j++)
            {
                scanf("%d",&q);
                if(a[q]>0) p[i].pts+=a[q];
                else if(isprime(q)) p[i].pts+=1;
                else p[i].pts+=0.3;
                //printf("%.3f\n",p[i].pts);
            }
            //printf("   %.3f\n",p[i].pts);
            int mx=0;
            memset(b,0,sizeof(b));
            for(j=0;j<y;j++)
            {
                scanf("%d",&b[j]);
                //mx=max(mx,q);
            }
            sort(b,b+y,cmp1);
            p[i].pts+=max(0.0,(b[2]-1200)*1.0/100*1.5);
            //printf("%.3f\n",p[i].pts);
        }
        sort(p,p+n,cmp);
        for(i=0;i<m;i++)
        {
            cout<<p[i].name;
            printf(" %.3f\n",p[i].pts);
        }
    }
    return 0;
}
