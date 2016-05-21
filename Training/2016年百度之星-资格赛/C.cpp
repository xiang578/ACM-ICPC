#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct trie
{
    int num;
    trie *next[26];
};
trie *rt;

void settrie(char *s)
{
    trie *p=rt,*t;
    int n=strlen(s),i,c;
    for(i=0; i<n; i++)
    {
        c=s[i]-'a';
        p->num++;
        if(p->next[c]==NULL)
        {
            t=new trie;
            t->num=0;
            for(int j=0; j<26; j++)
            {
                t->next[j]=NULL;
            }
            p->next[c]=t;
        }
        p=p->next[c];
    }
    p->num++;
}

int  get(char *s)
{
    trie *p=rt;
    int n=strlen(s),c;
    for(int i=0; i<n; i++)
    {
        c=s[i]-'a';
        if(p->next[c]==NULL)
            return 0;
        p=p->next[c];
    }
    return p->num;
}

void de(char *s,int cnt)
{
    trie *p=rt;
    int n=strlen(s),c;
    for(int i=0; i<n; i++)
    {
        p->num-=cnt;
        if(p->num==0)
        {
            for(int k=0; k<26; k++)
                p->next[k]=NULL;
            return ;
        }
        c=s[i]-'a';
        if(p->next[c]==NULL) return ;
        p=p->next[c];
    }
    p->num=0;
    /*for(int k=0; k<26; k++)
        p->next[k]=NULL;*/
}

int main()
{
    int n,i;
    char s[100],st[100];
    while(~scanf("%d",&n))
    {
        rt=new trie;
        rt->num=0;
        for(i=0; i<26; i++)
        {
            rt->next[i]=NULL;
        }
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            scanf("%s",st);
            if(s[0]=='i')
            {
                settrie(st);
            }
            else if(s[0]=='s')
            {
                if(get(st))
                    puts("Yes");
                else
                    puts("No");
            }
            else if(s[0]=='d')
            {
                int tmp=get(st);
                de(st,tmp);
            }
        }
    }
    return 0;
}
