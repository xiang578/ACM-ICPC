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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t,o=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        if(t%2==1)
        {
            if(o==-1) o=2;
            else if(o==1) o=1;
            else if(o==2) o=2;
        }
        else
        {
            if(o==-1) o=1;
            else if(o==1) o=2;
            else if(o==2) o=1;
        }
        printf("%d\n",o);
    }
    return 0;
}
