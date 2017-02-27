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
const int M=1e5+10;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    cin>>_;
    while(_--)
    {
        int n;
        cin>>n;
        cout<<n;
        int t=(n/10)%10;
        if(t==1) printf("th\n");
        else if(n%10==1) printf("st\n");
        else if(n%10==2) printf("nd\n");
        else if(n%10==3) printf("rd\n");
        else printf("th\n");
    }
    return 0;
}
