#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;

double c[2000];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&c[i]);
		}
		if(n==1)
        {
            printf("%.6f\n",c[1]);
            continue;
        }
		double ans=0,tmp;
        for(int i=1;i<=n;i++)
        {
            tmp=0;
            if(i==1||i==n)
            {
                for(int j=1;j<=n;j++)
                {
                    tmp+=1.0*(j-1)/(n-1);
                }

            }
            else
            {
                for(int j=1;j<=n;j++)
                {
                    tmp+=1.0*(j-1)*(j-2)/(n-1)/(n-2);
                }
            }
            tmp/=n;
            ans=ans+c[i]*tmp;
        }
		printf("%.6f\n",ans);
	}
	return 0;
}
