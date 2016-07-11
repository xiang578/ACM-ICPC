#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[1000],b[1000];
    cin>>a>>b;
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) printf("0");
        else printf("1");
    }
    printf("\n");
    return 0;
}
