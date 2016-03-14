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
    char s[1024];
    int i,j,st,n,m,ans,p,f;
    while(~scanf("%s%d",s,&m))
    {
        n=strlen(s);
        st=0;
        f=0;
        for(i=n-m;i>0;i--)
        {
            ans=10;
            for(j=st;j<n-i+1;j++)
            {
                if(ans>s[j]-'0')
                {
                    ans=s[j]-'0';
                    p=j+1;
                }
            }
            if(ans!=0) f=1;
            if(f==0&&ans==0) ;
            else printf("%d",ans);
            st=p;
        }
        if(f==0) printf("0");
        printf("\n");
    }
    return 0;
}
