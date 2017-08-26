#include <bits/stdc++.h>
using namespace std;
const int N=500010;

struct Trie
{
    int next[N][26],fail[N],last[N];
    int root,cnt;
    int newnode()
    {
        for(int i=0;i<26;i++)
            next[cnt][i]=-1;
        last[cnt]=-1;
        cnt++;
        return cnt-1;
    }

    void init()
    {
        cnt=0;
        root=newnode();
    }

    void insert(char buf[])
    {
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            if(next[now][buf[i]-'a']==-1)
                next[now][buf[i]-'a']=newnode();
            now=next[now][buf[i]-'a'];
        }
        last[now]++;
    }

    void getfail()
    {
        queue<int>q;
        fail[root]=root;
        for(int i=0;i<26;i++)
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
            for(int i=0;i<26;i++)
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    q.push(next[now][i]);
                }
        }
    }
    int query(char buf[])
    {
        int len=strlen(buf);
        int now=root;
        int res=0;
        for(i=0;i<len;i++)
        {
            now=next[now][buf[i]-'a'];
            int tmp=now;
            while(tmp!=root)
            {
                res+=last[tmp];
                last[tmp]=0;
                tmp=fail[tmp];
            }
        }
        return res;
    }
}
char buf[1000010];
Trie ac;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        ac.init();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&buf);
            ac.insert(buf);
        }
        ac.getfail();
        scanf("%s",buf);
        printf("%d\n",ac.query(buf));
    }
    return 0;
}
