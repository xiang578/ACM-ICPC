#include<bits/stdc++.h>
using namespace std;
struct trie
{
    int cnt,num;
    int id;
    trie *son,*bro;
};

trie *rt=new trie;
int tot;
void settrie(char *s,int j)
{
    trie *p=rt,*t,*t1;
    int n=strlen(s),i,c;
    for(i=0; i<n; i++)
    {
        c=s[i]-'a';
        while(p->num!=-1&&p->num!=c)
        {
            t=p;
            p=p->bro;
            if(p->num>c)
            {
                p=t;
                break;
            }
        }
        //if(i==0&&c==3) printf("%d\n",++tot);
        if(p->num==-1)
        {
            p->cnt=1;
            p->num=c;
            t= new trie;
            t->id=-1;
            t->num=-1;
            t->cnt=0;
            p->bro=t;

            t= new trie;
            t->num=-1;
            t->cnt=0;
            t->id=-1;
            p->son=t;

            p->id=j;
            p=p->son;
        }
        else if(p->num==c)
        {
            if(p->id!=j) p->cnt++;
            p->id=j;
            p=p->son;
        }
        else
        {
            t= new trie;
            t->num=c;
            t->cnt=1;
            t->id=-1;
            t1= new trie;
            t1->id=-1;
            t1->num=-1;
            t1->cnt=0;
            t->son=t1;
            t->bro=p->bro;
            p->bro=t;
            p=t;
            p->id=j;
            p=p->son;
        }
    }
}


int main()
{
    int ans,c,n,i,j,len;
    char s[50];
    trie *p,*t;
    while(~scanf("%d",&n))
    {
        rt=new trie;
        rt->num=-1;
        rt->cnt=0;
        rt->id=-1;
        tot=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            len=strlen(s);
            for(j=0; j<len; j++)
                settrie(s+j,i);
        }
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            len=strlen(s);
            p=rt;
            ans=0;
            for(j=0; j<len; j++)
            {
                c=s[j]-'a';
                while(p->num!=-1&&p->num!=c)
                {
                    t=p;
                    p=p->bro;
                    if(p->num>c)
                    {
                        p=t;
                        break;
                    }
                }
                if(p->num==c)
                {
                    ans=p->cnt;
                    p=p->son;
                }
                else break;
            }
            if(j!=len) ans=0;
            printf("%d\n",ans);
        }
    }
    return 0;
}
