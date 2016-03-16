#include<bits/stdc++.h>
using namespace std;
map<int,string>m1;
map<string,int>m2;

int main()
{
    int a,b,n;
    string s;
    while(~scanf("%d",&n))
    {
        m1.clear();
        m2.clear();
        for(int i=0;i<n;i++)
        {
            cin>>s>>a>>b;
            m2[s]=b;
            m1[a]=s;
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            s=m1[a];
            b=m2[s];
            cout<<s<<" "<<b<<endl;
        }
    }
    return 0;
}
