#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int h,m;
    scanf("%d:%d",&h,&m);
    int t = h*60+m;
    if(t<=720) printf("Only %02d:%02d.  Too early to Dang.\n",h,m);
    else 
    {
        t = h-12;
        if(m>=1) t++;
        for(int i=0;i<t;i++) cout<<"Dang";
        cout<<endl; 
    }
    return 0; 
}