#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct trie
{

    int cnt;
    trie *next[10];
};
int ans;
trie *rt=new trie;

void settrie(char *s)
{
    trie *p=rt,*t;
    int n=strlen(s),i,c;
    for(i=0;i<n-1;i++)
        if(s[i]!='0') break;
    for(; i<n; i++)
    {
        c=s[i]-'0';
        if(p->next[c]==NULL)
        {
            t=new trie;
            for(int j=0; j<10; j++)
            {
                t->next[j]=NULL;
            }
            t->cnt=0;
            p->next[c]=t;

        }
        p=p->next[c];
    }
    p->cnt++;
    if(p->cnt>ans)
        ans=p->cnt;
}

int main()
{
    int i,j,n;
    char s[50];
    while(~scanf("%d",&n))
    {
        ans=0;
        for(i=0;i<10;i++) rt->next[i]=NULL;
        rt->cnt=0;

        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            settrie(s);
        }
        printf("%d\n",ans);
    }
    return 0;
}
