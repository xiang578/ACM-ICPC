/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :10-18 19:19:20
File Name     :h2896.cpp
************************************************ */

//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <set>
//#include <map>
//#include <string>
//#include <math.h>
//#include <stdlib.h>
//#include <time.h>
#include <bits/stdc++.h>
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
	int query(char buf[],int num)
	{
		int len=strlen(buf);
		int now=root;
		int flag=0;
		for(int i=0;i<len;i++)
		{
			now=next[now][buf[i]];
			int tmp=now;
			while(tmp!=root)
			{
				if(last[tmp])
                {
                    flag=1;
                    use[last[tmp]]=1;
                }
				tmp=fail[tmp];
			}
		}
		if(!flag) return 0;
		printf("web %d:",num);
		for(int i=1;i<=n;i++)
            if(use[i])
                printf(" %d",i);
		printf("\n");
        return 1;
	}
};

char buf[10000+5];
Trie ac;

int main()
{
    int m,ans,i;
	while(~scanf("%d",&n))
	{
		ans=0;
		ac.init();
		for(i=0;i<n;i++)
		{
			scanf("%s",&buf);
			ac.insert(buf,i+1);
		}
		ac.getfail();
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s",&buf);
			memset(use,0,sizeof(use));
			if(ac.query(buf,i+1))
				ans++;
		}
		printf("total: %d\n",ans);
	}
    return 0;
}

