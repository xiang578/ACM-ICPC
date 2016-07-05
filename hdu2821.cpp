#include<bits/stdc++.h>
using namespace std;
int n,m,flag;
char g[100][100],gx[a][b];
stack<char>st;
int dfs(int x,int y)
{
    int k;
    //up
    for(int i=y-1;i>=0;i--)
    {
        if(gx[x][i]=='.') continue;
        else
        {
          k=gx[x][i]-'a'
        }
    }

    //down

    //left

    //right

}

int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%d",&m);
        flag=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",g[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]=='.')
                {
                    st.clear();
                    for(int a=0;a<n;a++)
                        for(int b=0;b<m;b++)
                    {
                        gx[a][b]=g[a][b];
                    }
                    flag=dfs(i,j);
                }
                if(flag)
                {
                    printf("%d\n",i);
                    printf("%d\n",j);
                    stack<char>ans;
                    while(!st.empty())
                    {
                        ans.push_back(st.top);
                        st.pop();
                    }
                    while(!ans.empty())
                    {
                        printf("%c",ans.top());
                        ans.pop();
                    }
                    printf("\n");
                    break;
                }
            }
            if(flag) break;
        }
    }
    return 0;
}
