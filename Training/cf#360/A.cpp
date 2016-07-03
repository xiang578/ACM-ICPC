#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[1024];
    int n,b,ans,t,k;
    cin>>n>>b;
    ans=t=0;
    for(int i=0;i<b;i++)
    {
        scanf("%s",s);
        k=0;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='0') k=1;
        }
        if(k) t++;
        else t=0;
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}
