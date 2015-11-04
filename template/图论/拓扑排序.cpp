#include<bits/stdc++.h>
using namespace std;
struct arcnode
{
    int to;
    struct arcnode *next;
};

int n,m;
arcnode *l[100];
int cnt[100];
char output[100];

void topsort()
{
    int i,top=-1;
    arcnode *temp;
    bool becycle=0;
    int pos=0;
    for(i=0; i<n; i++)
    {
        if(cnt[i]==0)
        {
            cnt[i]=top;
            top=i;
        }
    }
    for(i=0; i<n; i++)
    {
        if(top==-1)
        {
            becycle=1;
            break;
        }
        else
        {
            int j=top;
            top=cnt[top];
            pos+=sprintf(output+pos,"%d ",j+1);
            temp=l[j];
            while(temp!=NULL)
            {
                int k=temp->to;
                if(--cnt[k]==0)
                {
                    cnt[k]=top;
                    top=k;
                }
                temp=temp->next;
            }
        }
    }
    if(becycle) printf("network has a cycle!\n");
    else
    {
        int len=strlen(output);
        output[len-1]=0;
        printf("%s\n",output);
    }
}

int main()
{
    int i,u,v;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        memset(l,0,sizeof(l));
        memset(cnt,0,sizeof(cnt));
        memset(output,0,sizeof(output));
        arcnode *temp;
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            cnt[v]++;
            temp=new arcnode;
            temp->to=v;
            temp->next=NULL;
            if(l[u]==NULL)
                l[u]=temp;
            else
            {
                temp->next=l[u];
                l[u]=temp;
            }
        }
        topsort();
        for(i=0; i<n; i++)
        {
            temp=l[i];
            while(temp!=NULL)
            {
                l[i]=temp->next;
                delete temp;
                temp=l[i];
            }
        }
    }
    return 0;
}
