#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

int a[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int cnt=0,sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]&1)
            {
                cnt++;
                a[i]-=1;
            }
            sum+=a[i];
        }
        if(cnt==0)
        {
            printf("%d\n",sum);
            continue;
        }
        sum/=2;
        int tt=sum/cnt;
        printf("%d\n",tt*2+1);

    }
    return 0;
}
