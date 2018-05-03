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
using namespace std;

int main()
{
    int x,y,w,n,ans,i,tp;
    while(~scanf("%d%d%d%d",&x,&y,&w,&n))
    {
        i=1;
        ans=tp=0;
        while(i<n)
        {
            if(ans+w<tp+x)
            {
                ans+=w;
                i++;
            }
            else if(ans+w==tp+x)
            {
                i++;
                tp+=x;
                ans=tp;
                if(i==n) break;
                i++;
                tp+=y;
                ans=tp;
            }
            else if(ans+w>tp+x)
            {
                i++;
                tp=tp+x+y;
                ans=tp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
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
using namespace std;

int main()
{
    int x,y,w,n,ans,i,tp;
    while(~scanf("%d%d%d%d",&x,&y,&w,&n))
    {
        i=1;
        ans=tp=0;
        while(i<n)
        {
            if(ans+w<tp+x)
            {
                ans+=w;
                i++;
            }
            else if(ans+w==tp+x)
            {
                i++;
                tp+=x;
                ans=tp;
                if(i==n) break;
                i++;
                tp+=y;
                ans=tp;
            }
            else if(ans+w>tp+x)
            {
                i++;
                tp=tp+x+y;
                ans=tp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
