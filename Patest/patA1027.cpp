#include<bits/stdc++.h>
using namespace std;
void get(int x)
{
    if(x<10) printf("%d",x);
    else printf("%c",x-10+'A');
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("#");
    get(a/13);
    get(a%13);
    get(b/13);
    get(b%13);
    get(c/13);
    get(c%13);
    printf("\n");
    return 0;
}
