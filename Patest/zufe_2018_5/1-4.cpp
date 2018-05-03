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
    int n,m=0;
    string s;
    scanf("%d",&n);
    while(cin>>s)
    {
    	if(s=="End") break;
    	if(m==n)  cout<<s<<endl,m=0;
    	else {
    		m++;
    		if(s=="ChuiZi") cout<<"Bu"<<endl;
    		else if(s=="Bu") cout<<"JianDao"<<endl;
    		else if(s=="JianDao") cout<<"ChuiZi"<<endl;
     	}
    }
    return 0;
}
