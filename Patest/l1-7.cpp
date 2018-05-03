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

    int n;
    float x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	cin>>x>>y;
    	float p = (x-100)*0.9;
    	y=y/2;
    	float p1=p*0.9;
    	float p2=p*1.1;
    	if(y<p1) cout<<"You are tai shou le!"<<endl;
    	else if(y>p2) cout<<"You are tai pang le!"<<endl;
    	else cout<<"You are wan mei!"<<endl;
    }
    return 0;
}