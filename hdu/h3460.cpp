#include<bits/stdc++.h>
using namespace std;
int ans;
struct trie
{
    int num;
    trie *next[26];
};
trie *rt=new trie;

void settrie(char *s)
{
    trie *p=rt,*t;
    int n=strlen(s),i,c;
    if(n>p->num) p->num=n;
    for(i=0; i<n; i++)
    {
        c=s[i]-'a';
        if(p->next[c]==NULL)
        {
            ans+=2;
            t=new trie;
            for(int j=0; j<26; j++)
            {
                t->next[j]=NULL;
            }
            p->next[c]=t;
        }
        p=p->next[c];
    }
}

int main()
{
    int n,i;
    char s[100];
    while(~scanf("%d",&n))
    {
         rt->num=0;
        for(i=0; i<26; i++)
        {
            rt->next[i]=NULL;
        }
        ans=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            settrie(s);
            ans++;
        }
        ans=ans-rt->num;
        printf("%d\n",ans);
    }
    return 0;
}
