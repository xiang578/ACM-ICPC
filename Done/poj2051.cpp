#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int N=1024;

struct Q
{
    int id,preiod,t;
};

int cmp(Q n1,Q n2)
{
    if(n1.t==n2.t) return n1.id>n2.id;
    else return n1.t>n2.t;
}

int main()
{
    char s[1024];
    int tot=0;
    vector<Q>q;
    Q tmp;
    while(~scanf("%s",&s))
    {
        if(s[0]=='#') break;
        scanf("%d%d",&tmp.id,&tmp.preiod);
        tmp.t=tmp.preiod;
        q.push_back(tmp);
    }
    int k;
    scanf("%d",&k);
    make_heap(q.begin(),q.end(),cmp);
    for(int i=0;i<k;i++)
    {
        Q now=q.front();
        printf("%d\n",now.id);
        pop_heap(q.begin(),q.end(),cmp);
        q[q.size()-1].t+=q[q.size()-1].preiod;
        push_heap(q.begin(),q.end(),cmp);
    }
    return 0;
}
