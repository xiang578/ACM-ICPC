#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;


char f[1000000+10],a[1000000+10],b[1000000+10];
int main()
{
    int i,j,l,la,lb;
    scanf("%s",f);
    l=strlen(f);
    for(i=0,j=0; i<l; i++)
    {
        if(f[i]=='0'&&j==0) continue;
        a[j++]=f[i];
    }
    a[j]=0;

    scanf("%s",f);
    l=strlen(f);
    for(i=0,j=0; i<l; i++)
    {
        if(f[i]=='0'&&j==0) continue;
        b[j++]=f[i];
    }
    b[j]=0;
    //printf("%s %s\n",a,b);
    la=strlen(a),lb=strlen(b);
    if(la==lb)
    {
        int flag=0;
        for(i=0;i<la;i++)
        {
            if(a[i]>b[i]) {flag=1;break;}
            else if(a[i]<b[i]) {flag=-1;break;}
        }
        if(flag==0) printf("=\n");
        else if(flag==1) printf(">\n");
        else if(flag==-1) printf("<\n");
    }
    else if(la>lb)
        printf(">\n");
    else
        printf("<\n");
    return 0;
}
