#include<bits/stdc++.h>
using namespace std;
int p[150000];
vector<int>v;
int main()
{
    int i,n,m,t;
    memset(p,0,sizeof(p));
    p[1]=1;
    for(i=2; i<150000; i++)
    {
        if(p[i]) continue;
        for(int j=i+i; j<150000; j+=i)
            p[j]=1;
    }
    v.clear();
    for(i=2;i<150000;i++)
        if(!p[i]) v.push_back(i);

    //printf("%d\n",v.size());
        while(~scanf("%d%d",&n,&m))
        {
            t=0;
            for(i=n-1; i<m; i++)
            {
                if(t) printf(" ");
                t++;
                printf("%d",v[i]);
                if(t==10) {puts("");t=0;}
            }
            if(t!=0) printf("\n");
        }
    return 0;
}
