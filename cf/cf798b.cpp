#include<bits/stdc++.h>
using namespace std;
string s[100];
int a[100];

int main()
{
    int n,ans=1e9;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>s[i];
    int ok=0;
    for(int r=1; r<=n; r++)
    {
        for(int i=1; i<=n; i++)
        {
            a[i]=0;
            if(r==i) continue;
            string t="";
            if(s[i]==s[r]) continue;
            ok=-1;
            for(int j=0; j<s[i].size(); j++)
            {
                t="";
                for(int k=j; k<s[i].size(); k++)
                {
                    t+=s[i][k];
                }
                for(int k=0; k<j; k++)
                {
                    t+=s[i][k];
                }

                //cout<<t<<endl;
                if(t==s[r])
                {
                    ok=1;
                    break;
                }

                a[i]++;
            }
            if(ok==-1)
            {
                break;
            }
        }
        if(ok==-1) continue;
        int tmp=0;
        for(int i=1; i<=n; i++)
            tmp+=a[i];
        ans=min(tmp,ans);
    }
    if(ans==1e9) ans=-1;
    cout<<ans<<endl;
    return 0;
}
