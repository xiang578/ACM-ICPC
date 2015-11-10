#include "stdio.h"
int main()
{
    int n,j,i,cnt,x1[150],x2[150],y1[150],y2[150];
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
            scanf("%d%d%d%d",&x1[i],&x2[i],&y1[i],&y2[i]);
        cnt=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j) continue;
                if(x1[i]>=x1[j]&&x2[i]<=x2[j]&&y1[i]>=y1[j]&&y2[i]<=y2[j])
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n",cnt );
    }
    return 0;
}
