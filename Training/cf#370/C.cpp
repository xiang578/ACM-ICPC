#include<bits/stdc++.h>
using namespace std;
int x,y,ans1,ans;
void dfs(int a,int b,int c)
{
    printf("%d %d %d %d\n",ans1,a,b,c);
    if(a==y) return ;
    a=max(y,b/2);
    a=max(b+1-c,a);
    if(a<c) swap(a,c);
    if(a<b) swap(a,b);
    if(b<c) swap(b,c);
    ans1++;
    dfs(a,b,c);
}
int main()
{
    scanf("%d%d",&x,&y);
    ans1=0;
    dfs(x,x,x);
    printf("%d\n",ans1);
    return 0;
}
