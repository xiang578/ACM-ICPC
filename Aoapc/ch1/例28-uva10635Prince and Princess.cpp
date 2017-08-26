#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=250+5;
const int MAX=0x7fffffff;
int num[N*N],b[N*N],s[N*N];

int main()
{
    int _,i,n,j,p,q,t,ans,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&p,&q);
        memset(num,0,sizeof(num));
        for(i=0;i<N*N;i++)
            s[i]=MAX;
        ans=0;
        for(i=1;i<=p+1;i++)
        {
            scanf("%d",&t);
            num[t]=i;
        }
        j=0;
        for(i=1;i<=q+1;i++)
        {
            scanf("%d",&t);
            if(num[t])
            {
                b[++j]=num[t];
                //printf("%d %d ",j,num[t]);
            }
        }
        //printf("  %d\n",j);
        for(i=1;i<=j;i++)
        {

            t=lower_bound(s+1,s+j+1,b[i])-s;
            if(t>ans) ans=t;
            s[t]=b[i];
            //printf("%d %d\n",t,s[t],b[i]);
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

