#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int n,m;
int a[3000][10],b[3000][10];
struct node
{
    int a;
    int id;
}p[2048];

int cmp(node n1,node n2)
{
    return n1.a>n2.a;
}
int main()
{
    mp.clear();
    string s;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        mp[s]=i;
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][3]+=a[i][j];
        }
        a[i][3]/=4;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[j].id=j;
            p[j].a=a[j][i];
        }
        sort(p+1,p+1+n,cmp);
        int t=1;
        for(int j=1;j<=n;j++)
        {
            if(j!=1&&p[j].a==p[j-1].a)
            {
                b[p[j].id][i]=b[p[j-1].id][i];
                t++;
            }
            else
            {
                b[p[j].id][i]=t;
                t++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>s;
        if(mp[s]==0)
            puts("N/A");
        else
        {
            int mx=3;
            int k=mp[s];
            for(int j=0;j<3;j++)
            {
                if(b[k][j]<b[k][mx])
                {
                    mx=j;
                }
            }
            if(mx==0)
            {
                printf("%d C\n",b[k][mx]);
            }
            else if(mx==1)
            {
                printf("%d M\n",b[k][mx]);
            }
            else if(mx==2)
            {
                printf("%d E\n",b[k][mx]);
            }
            else if(mx==3)
            {
                printf("%d A\n",b[k][mx]);
            }
        }
    }
    return 0;
}
