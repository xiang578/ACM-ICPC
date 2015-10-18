#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct data
{
    int x,c,t;
}b[10000+5];
int cmp(data n1,data n2)
{
    return n1.x<n2.x;
}
struct node
{
    int i;
    int x;
    int bi;
}a[10000+5];

int c1(node n1,node n2)
{
    return n1.x<n2.x;
}

int c2(node n1,node n2)
{
    return n1.i<n2.i;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,l,t,n,i;
    char cmd[10];
    scanf("%d",&_);
    for(int __=1;__<=_;__++)
    {
        scanf("%d%d%d",&l,&t,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %s",&a[i].x,cmd);
            a[i].i=i;
            if(cmd[0]=='R')
            {
                b[i].x=a[i].x+t;
                b[i].c=1;
            }
            else
            {
                b[i].x=a[i].x-t;
                b[i].c=0;
            }
        }
        sort(b,b+n,cmp);
        for(i=0;i<n;i++)
            b[i].t=0;
        for(i=1;i<n;i++)
            if(b[i-1].x==b[i].x) b[i-1].t=b[i].t=1;
        sort(a,a+n,c1);
        for(i=0;i<n;i++)
            a[i].bi=i;
        sort(a,a+n,c2);
        printf("Case #%d:\n",__);
        for(i=0;i<n;i++)
        {
            int k=a[i].bi;
            if(b[a[i].bi].x<0||b[a[i].bi].x>l) printf("Fell off\n");
            else
            {
                if(b[k].t==1) printf("%d Turning\n",b[a[i].bi].x);
                else if(b[a[i].bi].c==1) printf("%d R\n",b[a[i].bi].x);
                else printf("%d L\n",b[a[i].bi].x);
            }
        }
        printf("\n");
    }
    return 0;
}
