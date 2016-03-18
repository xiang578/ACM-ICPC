#include <stdio.h>
using namespace std;
const int N=100000+10;
__int64 a[N],l[N],r[N],tmp;

int main()
{
    int n,i;
    while(~scanf("%d",&n)&&n)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            l[i]=r[i]=i;
        }
        a[0]=a[n+1]=-1;
        for(i=1; i<=n; i++)
        {
            while(a[l[i]-1]>=a[i]) l[i]=l[l[i]-1];
        }
        __int64 ans=0;
        for(i=n; i>=1; i--)
        {
            while(a[r[i]+1]>=a[i]) r[i]=r[r[i]+1];
            tmp=(r[i]-l[i]+1)*a[i];
            if(tmp>=ans) ans=tmp;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
