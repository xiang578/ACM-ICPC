#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <set>
#include <time.h>
#include <cmath>
using namespace std;


int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==k||k==0)
        puts("0 0");
    else
    {
        printf("1 %d\n",min(k+2,n-k));
    }
    return 0;
}
