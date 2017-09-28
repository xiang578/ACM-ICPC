/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
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
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
const int M=1e6+10;
map<string,string>mp[100000+10];
map<string,int>ssid;
char c[2000000+10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    int now=1;
		ssid.clear();
		for(int i=0;i<100000+10;i++)
				mp[i].clear();
    while(_--)
    {
        gets(c);
        string cmd,s1,s2;
        cmd="";
        s1="";
        s2="";
				int len=strlen(c);
				int k=0;
				for(;c[k]!=' ';k++)
				{
						cmd+=c[k];
				}
				k++;
				for(;c[k]!=' '&&k<len;k++)
				{
						s1+=c[k];
				}
				if(k<len)
				{
						k++;
						for(;k<len;k++)
						{
								s2+=c[k];
						}
				}

        if(cmd=="put")
        {
            mp[now][s1]=s2;
        }
        else if(cmd=="mkss")
        {
					ssid[s1]=now;
					map<string,string>::iterator it = mp[now].begin();
					for(;it!=mp[now].end();++it)
					{
							mp[now+1][it->first]=it->second;
					}
					now++;
        }
				else if(cmd=="get")
				{
						if(s2=="")
						{
								if(mp[now][s1]=="") cout<<"(NULL)"<<endl;
								else cout<<mp[now][s1]<<endl;
						}
						else
						{
								if(ssid.count(s2)==0) cout<<"(UNKNOW_SSID)"<<endl;
								else if(mp[ssid[s2]][s1]=="") cout<<"(NULL)"<<endl;
								else cout<<mp[ssid[s2]][s1]<<endl;
						}
				}
				else
				{
						mp[now][s1]="";
				}

    }
    return 0;
}
