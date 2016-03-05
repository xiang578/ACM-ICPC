#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int _max = 10001;
int c1[_max], c2[_max];
int e[20];
int main()
{
    int nNum;
    int i, j, k;
    while(scanf("%d",&nNum)!=EOF)
    {
        if(nNum==0) break;
        for(i=0; i<=nNum; ++i)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for(i=2; i<=17; ++i)
        {

            for(j=0; j<=nNum; ++j)
                for(k=0; k+j<=nNum; k+=i*i)
                {
                    c2[j+k] += c1[j];
                }
            for(j=0; j<=nNum; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout << c1[nNum] << endl;
    }
    return 0;
}
