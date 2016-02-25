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
char s[123456];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,n,k,a1,a2;

    while(~scanf("%d%d",&n,&k))
    {
        scanf("%s",s);
        int len=strlen(s);
        for(i=0; i<len; i++)
        {
            a1=s[i]-'a';
            a2='z'-s[i];
            if(a1<=k&&a2<=k)
            {
                if(a1>=a2)
                {
                    s[i]='a';
                    k-=a1;
                }
                else
                {
                    s[i]='z';
                    k-=a2;
                }
            }
            else
            {
                if(a1<k)
                {
                    s[i]=s[i]+k;
                }
                else
                {
                    s[i]=s[i]-k;
                }
                k=0;
            }
            if(k==0) break;
        }
        if(k) puts("-1");
        else printf("%s\n",s);
    }
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
char s[123456];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,n,k,a1,a2,sum=0;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int len=strlen(s);
    for(i=0; i<len; i++)
        sum+=max(s[i]-'a','z'-s[i]);
    if(sum<k) printf("-1\n");
    else
    {
        for(i=0; i<len; i++)
        {
            //if(k==0) break;
            sum=max('z'-s[i],s[i]-'a');
            if(sum<=k)
            {
                k-=sum;
                if('z'-s[i]>s[i]-'a') s[i]='z';
                else s[i]='a';
            }
            else
            {
                sum=s[i]+k;
                if(sum>'z') sum=s[i]-k;
                s[i]=sum;
                k=0;
            }
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
*/
