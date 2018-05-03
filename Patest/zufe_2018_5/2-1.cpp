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

string v[10000];
struct node
{
	int id=0;
	int k;
	int cnt=0;
	double r=0.0;
}p[10000];

int cmp(node a,node b)
{
	if(a.cnt==b.cnt)
		{return a.k<b.k;}
	return a.cnt>b.cnt;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>v[i];
    	p[i].id=i;
    	cin>>p[i].k;
    	p[i].cnt=0;
    	set<int>st;
    	for(int j=0;j<p[i].k;j++)
    	{
    		cin>>t;
    		st.insert(t);
    	}
    	p[i].cnt=st.size();
    	p[i].r=p[i].cnt/p[i].k;
    }
    sort(p,p+n,cmp);
    vector<int>ans;
    for(int i=0;i<min(n,3);i++)
    	{ ans.push_back(p[i].id);}//rintf("%d %d\n",p[i].id,p[i].cnt);}

    if(ans.size()==3) 
    	cout<<v[ans[0]]<<" "<<v[ans[1]]<<" "<<v[ans[2]]<<endl;
    if(ans.size()==2) 
    	cout<<v[ans[0]]<<" "<<v[ans[1]]<<" -"<<endl;
    if(ans.size()==1) 
    	cout<<v[ans[0]]<<" - -"<<endl;
    if(ans.size()==0) 
    	cout<<"- - -"<<endl;

    return 0;
}
