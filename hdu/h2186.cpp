#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int s,t;
};
Edge edge[50000+5];
int n,m;

Addedge(int u,int v)
{

}
int main()
{
    int i,j,u,v;
    while(!scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            Addedge(u,v);
        }
    }
    return 0;
}
