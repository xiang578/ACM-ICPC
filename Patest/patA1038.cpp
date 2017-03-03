#include<bits/stdc++.h>
using namespace std;
string s[10000+10];
int n;
int cmp(string a,string b)
{
    return a+b<b+a;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n,cmp);

    string ans;
    for(int i=0;i<n;i++)
    {
        ans+=s[i];
    }
    int f=0;
    for(int i=0;i<ans.size();i++)
    {
        if(f==0&&ans[i]=='0') continue;
        f=1;
        printf("%c",ans[i]);
    }
    if(f==0) printf("0");
    printf("\n");
    return 0;
}
