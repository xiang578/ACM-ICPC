#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int _max = 100000+5;
int c1[_max], c2[_max];
int main()
{
    //int n,i,j,k;
    int n;   //
    int i, j, k;

    int _;
    cin>>_;
    while(_--)
    {
        scanf("%d",&n);
        for(i=0; i<=n; ++i)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for(i=2; i<=15; ++i)
        {

            for(j=0; j<=n; ++j)
                for(k=0; k+j<=n; k+=i)
                {
                    c2[j+k] += c1[j];
                    c2[j+k]%=mod;
                }
            for(j=0; j<=n; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout << c1[n] << endl;
    }
    return 0;
}
