/*
#include<bits/stdc++.h>
using namespace std;
const int N=1024;
stack<int>st;
int a[N],n,m,k;

int check()
{
    while(!st.empty()) st.pop();
    int p=1,t;
    for(int i=0;i<n;i++)
    {
        while(p<=a[i])
        {
            st.push(p);
            p++;
            if(st.size()>m) return 0;
        }
        t=st.top();
        if(t!=a[i]) return 0;
        st.pop();
    }

    return 1;
}

int main()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int _=0;_<k;_++)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(check()) puts("YES");
        else puts("NO");
    }
    return 0;
}
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int i,j,n,m,k,t,a[1200],top,b[1200];
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        while(k--)
        {
            for(i=0;i<m;i++) scanf("%d",&a[i]);
            top=0,j=0,i=1;
            while(j<m)
            {
                if(i==a[j]&&top<n)
                {
                    i++;
                    j++;
                }
                else if(top>0&&b[top]==a[j])
                {
                    j++;
                    top--;
                }
                else if(top<n-1&&i<=m)
                {
                    b[++top]=i;
                    i++;
                }
                else break;
            }
            if(j<m) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}
