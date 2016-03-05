#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int _max = 10001;
int c1[_max], c2[_max];
int a[10],b[10];
int main()
{
    int nNum,up;
    int i, j, k;
    while(~scanf("%d%d%d",&a[1],&a[2],&a[3]))
    {
        if(a[1]+a[2]+a[3]==0) break;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(i=0; i<=a[1]; ++i)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        b[2]=2;
        b[3]=5;
        nNum=up=a[1];
        for(i=2; i<=3; ++i)
        {
            for(j=0; j<=nNum; ++j)
            {
                if(!c1[j]) continue;
                for(k=0; k<=a[i]*b[i]; k+=b[i])
                {
                    c2[j+k] += c1[j];
                    up=max(up,j+k);
                }
            }
            nNum=up;
            for(j=0; j<=nNum; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for(i=0; i<=up; i++)
            if(c1[i]==0) break;
        printf("%d\n",i);
    }
    return 0;
}
