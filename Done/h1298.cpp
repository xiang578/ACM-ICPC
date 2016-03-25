
#include<bits/stdc++.h>
struct trie
{
    int cnt;
    char str[100+5];
    trie *next[26];
};

trie *rt=new trie;
int mx;
char  ans[100+5],a[100+5];

void settrie(char *s,int cnt)
{
    int len=strlen(s),i,c,j;
    char str[100+5];
    trie *p,*t;
    p=rt;
    for(i=0;i<len;i++)
    {
        c=s[i]-'a';
        if(p->next[c]==NULL)
        {
            t=new trie;
            for(j=0;j<26;j++)
                t->next[j]=NULL;
            t->cnt=0;
            p->next[c]=t;
        }
        p=p->next[c];
        p->cnt+=cnt;
        str[i]=s[i];
        str[i+1]=0;
        strcpy(p->str,str);
    }
}

void dfs(trie *p,int cur ,int ed)
{
    if(cur==ed)
    {
        if(p->cnt>mx)
        {
            mx=p->cnt;
            strcpy(ans,p->str);
        }
    }
    int i,j,k,n,z;
    k=a[cur+1]-'0';
    if(k==7||k==9) n=4;
    else n=3;
    if(k==8) z=19;
    else if(k==9) z=22;
    else z=(k-2)*3;

    for(i=0;i<n;i++)
    {
        if(p->next[i+z]==NULL) continue;
        dfs(p->next[i+z],cur+1,ed);
    }
}

int main()
{
    int i,j,_,n,m,t;
    scanf("%d",&_);
    for(int k=1;k<=_;k++)
    {
        scanf("%d",&n);
        for(i=0;i<26;i++)
            rt->next[i]=NULL;
        rt->cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%s%d",a,&t);
            settrie(a,t);
        }
         printf("Scenario #%d:\n",k);
        scanf("%d",&m);
        for(int q=1;q<=m;q++)
        {
            scanf("%s",&a);
            for(j=0;a[j]!='1';j++)
            {
                mx=-1;
                dfs(rt,-1,j);
                if(mx==-1) printf("MANUALLY\n");
                else printf("%s\n",ans);
            }
            if(q!=m) printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}

#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct trie
{
    int cnt;
    char str[105];
    trie *next[26];
};

trie *rt=new trie;
int mx;
char st[100+5],ans[100+5];

void settrie(char *s,int cnt)
{
    trie *p=rt,*t;
    int len=strlen(s),i,j,c,m;
    char str[105];
    for(i=0; i<len; i++)
    {
        c=s[i]-'a';
        if(p->next[c]==NULL)
        {
            t=new trie;
            for(j=0; j<26; j++) t->next[j]=NULL;
            t->cnt=0;
            p->next[c]=t;
        }
        p=p->next[c];
        p->cnt+=cnt;
        str[i]=s[i];
        str[i+1]=0;
        strcpy(p->str,str);
    }
}

void dfs(trie *p,int cur ,int ed)
{
    if(cur==ed)
    {
        if(p->cnt>mx)
        {
            mx=p->cnt;
            strcpy(ans,p->str);
        }
        return ;
    }
    int i,j,k,n,z;
    printf("%d\n",cur);
    k=st[cur+1]-'0';
    z=(k-2)*3;
    if(k==8) z=19;
    else if(k==9) z=22;
    if(k==7||k==9) n=4;
    else n=3;

    for(i=0;i<n;i++)
    {
        if(p->next[i+z]!=NULL)
        {
            dfs(p->next[i+z],cur+1,ed);
        }
    }
}

int main()
{
    int _,__,i,j,n,m,t,len,c,f,mx,k;
    scanf("%d",&_);
    for(__=1; __<=_; __++)
    {
        for(i=0; i<26; i++) rt->next[i]=NULL;
        rt->cnt=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%s%d",st,&t);
            settrie(st,t);
        }
        printf("Scenario #%d:\n",__);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",st);
            len=strlen(st);
            for(i=0; st[i]!='1'; i++)
            {
                mx=-1;
                memset(ans,0,sizeof(ans));
                dfs(rt,-1,i);
               if(mx==-1)  printf("MANUALLY\n");
                else
                    printf("%s\n",ans);
            }
            if(m!=0) printf("\n");
        }
        //if(__!=_)
            printf("\n\n");
    }
    return 0;
}


/*#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct trie
{

    int num;
    int c;
    int cnt;
    trie *next[10];
};
trie *rt=new trie;

char dic[1024][100+5];

int idx(char c)
{
    if(c=='a'||c=='b'||c=='c') return 2;
    else if(c=='d'||c=='e'||c=='f') return 3;
    else if(c=='g'||c=='h'||c=='i') return 4;
    else if(c=='j'||c=='k'||c=='l') return 5;
    else if(c=='m'||c=='n'||c=='o') return 6;
    else if(c=='p'||c=='q'||c=='r'||c=='s') return 7;
    else if(c=='t'||c=='u'||c=='v') return 8;
    else if(c=='w'||c=='x'||c=='y'||c=='z') return 9;
}

void settrie(char *s,int cnt,int num)
{
    trie *p=rt,*t;
    int n=strlen(s),i,j,c,m;
    for(i=0; i<n; i++)
    {
        c=s[i]-'a';
        m=idx(s[i]);
        if(p->next[m]==NULL)
        {
            t=new trie;
            for(j=0; j<10; j++)
                t->next[j]=NULL;
            t->num=-1;
            t->cnt=-1;
            t->c=-1;
            p->next[m]=t;
        }
        p=p->next[m];
        if(p->cnt<cnt)
        {
            p->cnt=cnt;
            p->num=num;
            p->c=c;
        }
        else if(p->cnt==cnt&&p->c>c)
        {
            p->cnt=cnt;
            p->num=num;
            p->c=c;
        }
    }
}

int main()
{
    int _,__,i,j,n,m,t,len,c,f;
    trie *p;
    char s[100+5];
    scanf("%d",&_);
    for(__=1; __<=_; __++)
    {
        for(i=0; i<10; i++) rt->next[i]=NULL;
        rt->c=-1;
        rt->num=-1;
        rt->cnt=0;

        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%s%d",dic[i],&t);
            settrie(dic[i],t,i);
        }
        printf("Scenario #%d:\n",__);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",s);
            len=strlen(s);
            p=rt;
            f=0;
            for(i=0;i<len;i++)
            {
                c=s[i]-'0';
                if(c==1) break;
                if(p->next[c]==NULL||f)
                {
                    printf("MANUALLY\n");
                    f=1;
                }
                else
                {
                    p=p->next[c];
                    for(j=0;j<=i;j++)
                        printf("%c",dic[p->num][j]);
                    printf("\n");
                }
            }
            if(m!=0) printf("\n");
        }
        if(__!=_) printf("\n\n");
    }
    return 0;
}
*/
