#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int pre,i,n,k,m,ans;
    while(~scanf("%d%d%d",&n,&k,&m))
    {
        pre=0;
        for(i=1;i<n;i++)
        {
            ans=(pre+k)%n;
            pre=ans;
        }
        ans=(ans-k+m+1+n)%n;
        printf("%d\n",ans);
    }
    return 0;

}
