#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int n;
    int step;
    string road;
}p1,p2;

int n,m,k,km,vis[1000000+5];

void bfs()
{
    memset(vis,0,sizeof(vis));
    queue<node>q;
    p1.n=n;
    p1.step=0;
    p1.road="";
    vis[(p1.n%k+k)%k]=1;
    q.push(p1);
    while(!q.empty())
    {
        p1=q.front();
        q.pop();
        if(((n+1)%k+k)%k==((p1.n)%k+k)%k)
        {
            printf("%d\n",p1.step);
            cout<<p1.road<<endl;
            return ;
        }
        for(int i=0;i<4;i++)
        {
            p2=p1;
            p2.step++;
            if(i==0)
            {
                p2.n=(p2.n+m)%km;
                p2.road+='+';
            }
            else if(i==1)
            {
                p2.n=(p2.n-m)%km;
                p2.road+='-';
            }
            else if(i==2)
            {
                p2.n=(p2.n*m)%km;
                p2.road+='*';
            }
            else if(i==3)
            {
                p2.n=(p2.n%m+m)%m%km;
                p2.road+='%';
            }
            if(!vis[(p2.n%k+k)%k])
            {
                vis[(p2.n%k+k)%k]=1;
                q.push(p2);
            }
        }
    }
    printf("0\n");
}

int main()
{
    while(~scanf("%d%d%d",&n,&k,&m)&&n&&m&&k)
    {
        km=k*m;
        bfs();
    }
    return 0;
}
