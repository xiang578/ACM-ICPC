#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
const int N=500000+10;
struct node
{
	int from,next,to;
}p[N];

char s[N],c[N];


int main()
{
	int n,m,k,v,u,tmp;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		scanf("%s",s);
		scanf("%s",c);
        stack<int>st;
		for(int i=0;i<n;i++)
		{
			p[i].from=i-1;
			p[i].next=i+1;
		}
		p[n-1].next=-1;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(') st.push(i);
			else if(s[i]==')')
			{
				v=st.top();
				st.pop();
				p[v].to=i;
				p[i].to=v;
			}
		}
		k--;
		tmp=0;
		for(int i=0;i<m;i++)
		{
			if(c[i]=='R')
			{
				k=p[k].next;
			}
			else if(c[i]=='L')
			{
				k=p[k].from;
			}
			else
			{
				if(s[k]==')') k=p[k].to;
				//printf("%d\n",k);
				u=p[k].from;
				v=p[p[k].to].next;
				if(v==-1)
				{
					k=u;
					p[u].next=-1;
				}
				else if(u==-1)
				{
					k=v;
					p[v].from=-1;
					tmp=v;
				}
				else
				{
					p[u].next=v;
					p[v].from=u;
					k=v;
				}
			}
		}
        //printf("%d\n",tmp);
		while(tmp!=-1)
		{
			printf("%c",s[tmp]);
			tmp=p[tmp].next;
		}
		printf("\n");
	}
	return 0;
}
