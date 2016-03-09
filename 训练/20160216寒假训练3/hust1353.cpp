/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
int a[120],use[120],x[120],y[120];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,n,ans,tmp,m,cnt,l,r,f1,f2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        l=1;
        r=n;
        m=n/2;
        cnt=0;
        f1=0;
        f2=1;
        for(i=1; i<=m; i++)
        {
            if(!f1)
            {
                x[i]=l;
                y[i]=r;
                f1=1;
            }
            else
            {
                x[i]=r;
                y[i]=l;
                f1=0;
            }
            l++;
            r--;
            cnt+=2;
            if(cnt==n) break;
            if(!f2)
            {
                x[m-i+1]=l;
                y[m-i+1]=r;
                f2=1;
            }
            else
            {
                x[m-i+1]=r;
                y[m-i+1]=l;
                f2=0;

            }
            l++;
            r--;
            cnt+=2;
            if(cnt==n) break;

        }


        //for(i=1; i<=m; i++)
        //printf("%d %d\n",x[i],y[i]);

        tmp=0;
        cnt=1;
        for(i=1; i<=m; i++)
        {
            a[cnt]=x[i];
            cnt++;
            a[cnt]=y[i];
            cnt++;
        }
        a[n+1]=a[1];
        a[n+2]=a[2];
        //for(i=1; i<=n; i++)
          //  printf("%d ",a[i]);
        //printf("\n");
        for(i=1; i<=n; i++)
            tmp+=(a[i]-a[i+2])*(a[i]-a[i+2]);
        for(i=1; i<=n/2; i++)
            tmp+=(a[2*i-1]-a[2*i])*(a[2*i-1]-a[2*i]);
        printf("%d\n",tmp);
    }
    return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
int a[120];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,n,ans,tmp;
    //for(n=6;n<=100;n+=2)
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            a[i]=i;
        a[n+1]=a[1];
        a[n+2]=a[2];
        ans=0;
        do
        {
            tmp=0;
            a[n+1]=a[1];
            a[n+2]=a[2];
            for(i=1;i<=n;i++)
                tmp+=(a[i]-a[i+2])*(a[i]-a[i+2]);
            for(i=1;i<=n/2;i++)
                tmp+=(a[2*i-1]-a[2*i])*(a[2*i-1]-a[2*i]);
            if(tmp>ans)
            {
                ans=tmp;
                printf("%d  ",ans);
                for(int j=1;j<=n;j++)
                    printf("%d ",a[j]);
                printf("\n");
            }
        }while(next_permutation(a+1,a+n+1));
        //printf("a[%d]=%d;\n",n,ans);
    }
    return 0;
}
*/
