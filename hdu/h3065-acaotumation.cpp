/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :10-18 19:19:20
File Name     :h2896.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int use[1024],n;
struct Trie
{
    int next[500000][128],fail[500000],last[500000];
    int root,cnt;
    int newnode()
    {
        for(int i=0;i<128;i++)
            next[cnt][i]=-1;
        last[cnt]=0;
        cnt++;
        return cnt-1;
    }

    void init()
    {
        cnt=0;
        root=newnode();
    }

    void insert(char buf[],int num)
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(next[now][buf[i]]==-1)
                next[now][buf[i]]=newnode();
            now=next[now][buf[i]];
        }
        last[now]=num;
    }

    void getfail()
    {
        queue<int>q;
        fail[root]=root;
        for(int i=0;i<128;i++)
            if(next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                q.push(next[root][i]);
            }
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int i=0;i<128;i++)
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    q.push(next[now][i]);
                }
        }
    }
    void query(char buf[])
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            now=next[now][buf[i]];
            int tmp=now;
            while(tmp!=root)
            {
                if(last[tmp])
                    use[last[tmp]]++;
                tmp=fail[tmp];
            }
        }
    }
};

char buf[2000000+5];
char s[1024][55];
Trie ac;

int main()
{
    int m,ans,i;
    while(~scanf("%d",&n))
    {
        ac.init();
        for(i=0;i<n;i++)
        {
            scanf("%s",&s[i]);
            ac.insert(s[i],i+1);
        }
        ac.getfail();
        scanf("%s",&buf);
        memset(use,0,sizeof(use));
        ac.query(buf);
        for(i=1;i<=n;i++)
            if(use[i]>0)
                printf("%s: %d\n",s[i-1],use[i]);
    }
    return 0;
}
