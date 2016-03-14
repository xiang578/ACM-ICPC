#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int a[1024];
    int _,n,m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int i=n;i<2*n;i++)
            a[i]=a[i-n];
       int ans=0;
       int tmp;
       for(int i=0;i+m<2*n;i++)
       {
           tmp=0;
           for(int j=0;j<m;j++)
           {
               tmp+=a[i+j];
           }
           ans=max(tmp,ans);
       }
        cout<<ans<<endl;
    }
    return 0;
}
