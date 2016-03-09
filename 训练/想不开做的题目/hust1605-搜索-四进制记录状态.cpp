#include<cstdio>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
const int inf=0x7fffffff;
int n,st,ed;
char s1[100+5],s2[100+5];
map<int,int>m;
queue<int>q;
queue<int>t;
int ch(char c)
{
    if(c=='A') return 0;
    else if(c=='C') return 1;
    else if(c=='G') return 2;
    else if(c=='T') return 3;
}

int get1(int x)
{
    int a[20],i,ret=0;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        a[i]=x%4;
        x/=4;
    }
    swap(a[n-1],a[n-2]);
    for(i=n-1;i>=0;i--)
    {
        ret=ret*4+a[i];
    }
    return ret;
}

int get2(int x)
{
    int a[20],i,ret=0;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        a[i]=x%4;
        x/=4;
    }
    for(i=n-2;i>=0;i--)
    {
        ret=ret*4+a[i];
    }
    ret=ret*4+a[n-1];
    return ret;
}

int bfs(int x)
{
    int nq,nt,tmp;
    while(!q.empty()) q.pop();
    while(!t.empty()) t.pop();
     q.push(x);
     t.push(0);
     m[x]=1;
     while(!q.empty())
     {
         nq=q.front();
         nt=t.front();
         q.pop();
         t.pop();
         //printf("%d %d\n",nq,nt);
         if(nq==ed) return nt;
         tmp=get1(nq);
         if(m[tmp]==0)
         {
             m[tmp]=1;
             q.push(tmp);
             t.push(nt+1);
         }

         tmp=get2(nq);
         if(m[tmp]==0)
         {
             m[tmp]=1;
             q.push(tmp);
             t.push(nt+1);
         }
     }
     return 0;
}

int main()
{
    while(~scanf("%d",&n))
    {
        m.clear();
        scanf("%s%s",s1,s2);
        st=ed=0;
        for(int i=0;i<n;i++)
        {
            st=st*4+ch(s1[i]);
        }
        for(int i=0;i<n;i++)
        {
            ed=ed*4+ch(s2[i]);
        }
        //printf("%d %d\n",st,ed);
        m[st]=1;
        printf("%d\n",bfs(st));
    }
    return 0;
}
