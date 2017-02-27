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

struct node
{
    int a,b,c;
} n1,n2;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>n1.a>>n1.b>>n1.c;
        cin>>n2.a>>n2.b>>n2.c;
        if(n1.a>n2.a)printf("cpcs\n");
        else if(n1.a<n2.a)printf("javaman\n");
        else
        {
            if(n1.b>n2.b)printf("cpcs\n");
            else if(n1.b<n2.b)printf("javaman\n");
            else
            {
                if(n1.c>n2.c)printf("cpcs\n");
                else if(n1.c<n2.c)printf("javaman\n");
                else printf("same\n");
            }
        }
    }
    return 0;
}
