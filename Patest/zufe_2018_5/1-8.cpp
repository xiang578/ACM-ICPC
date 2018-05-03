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
int a[1000][1000],b[1000][1000],c[1000][1000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ax,ay,bx,by;
    cin>>ax>>ay;
    for(int i=0;i<ax;i++)
    	for(int j=0;j<ay;j++)
    		scanf("%d",&a[i][j]);
    cin>>bx>>by;
    for(int i=0;i<bx;i++)
    	for(int j=0;j<by;j++)
    		scanf("%d",&b[i][j]);
    if(ay!=bx) {printf("Error: %d != %d\n",ay,bx);return 0;}
    memset(c,0,sizeof(c));
    for(int i=0;i<ax;i++)
    {
    	for(int j=0;j<ay;j++)
    	{
    		for(int k=0;k<by;k++)
    		{
    			c[i][k]+=a[i][j]*b[j][k];
    		}
    	}
    }

    cout<<ax<<" "<<by<<endl;
	for(int i=0;i<ax;i++)
		for(int j=0;j<by;j++)
			{	
				cout<<c[i][j];
				if(j==by-1) cout<<endl;
				else cout<<" ";
			}
    return 0;
}