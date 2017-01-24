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
string s;
vector<string>v;
int a[10];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>s;
    string t="";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='!') t+="0";
        else if(s[i]=='R') t+="1";
        else if(s[i]=='B') t+="2";
        else if(s[i]=='Y') t+="3";
        else if(s[i]=='G') t+="4";
    }
    //cout<<t<<endl;
    for(int i=1; i<=4; i++) a[i]=i;
    int cnt=0;
    do
    {
        int b[10];
        memset(b,0,sizeof(b));
        int ok=1;
        for(int i=0;i<t.size();i++)
        {

            if(t[i]!='0'&&t[i]!=a[i%4+1]+'0')
            {
                ok=0;break;
            }
            if(t[i]=='0') b[a[i%4+1]]++;
        }
        if(ok)
        {
            for(int i=1;i<=4;i++)
                cout<<b[i]<<" ";
            break;
        }
    }while(next_permutation(a+1,a+5));
    //printf("%d\n",cnt);
    return 0;
}
