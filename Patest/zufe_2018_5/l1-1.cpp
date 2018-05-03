/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Fri Mar 30 15:59:43 2018
File Name     :l1-1.cpp
************************************************ */

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
    int ans=-1,d;
    char s;
    int t=0;
	while(scanf("%d",&d))
	{
		s=getchar();
		t++;
		if(d==250&&ans==-1) ans=t;
		if(s!=' ') break;
	}
	cout<<ans<<endl;
    return 0;
}
