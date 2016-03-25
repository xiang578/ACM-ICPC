#include<bits/stdc++.h>
using namespace std;
int use[5000+10],ans[5000+10];

int main()
{
    int n,i,j,cnt,k;
    for(int i=2;i<=5000;i++)
    {
        n=i;
        memset(use,0,sizeof(use));
        k=1;
        cnt=1;
        j=1;
        while(n>1)
        {
            //printf("%d\n",j);
            if(k==cnt)
            {
                use[j]=1;
                cnt++;
                k=1;
                n--;
            }
            while(1)
            {
                j++;
                if(j>n) j=1;
                if(use[j]==0) break;
            }
        }
        for(j=1;j<=i;j++)
        {
            if(!use[j])
            {
                ans[i]=j;
                break;
            }
        }
        printf("%d\n",ans[i]);
    }
    ans[0]=1;
    ans[1]=1;
    /*for(i=0;i<=5000;i++)
    {
        printf("%d,",ans[i]);
    }*/
    return 0;
}
