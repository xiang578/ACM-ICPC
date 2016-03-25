#include<bits/stdc++.h>
using namespace std;

string a,s[1<<16];

int cnt,len;
stack<int>sta;
void dfs(int x,string st)
{
    if(x==len)
    {
        //cout<<st<<endl;
        s[cnt++]=st;
        return ;
    }
    else
    {
        dfs(x+1,st+'+'+a[x]);
        dfs(x+1,st+a[x]);
    }
}


int main()
{
    int i,j,ans,f,a1,a2,t,k;
    while(cin>>a)
    {
        if(a=="END") break;
        cnt=0;
        ans=0;
        string b;
        len=a.length();
        b=a[0];
        dfs(1,b);
        for(i=0;i<cnt;i++)
        {
            for(j=0;j<s[i].length()-1;j++)
            {
                if(s[i][j]!='+'&&s[i][j+1]!='+')
                {
                    a1=a2=0;
                    t=0;
                    for(k=0;k<=j;k++)
                    {
                        if(s[i][k]=='+') {a1+=t;t=0;}
                        else {t=t*10+s[i][k]-'0';}
                    }
                    a1+=t;

                    t=0;
                    for(k=j+1;k<s[i].length();k++)
                    {
                        if(s[i][k]=='+') {a2+=t;t=0;}
                        else {t=t*10+s[i][k]-'0';}
                    }
                    a2+=t;

                    if(a1==a2&&a1) ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
