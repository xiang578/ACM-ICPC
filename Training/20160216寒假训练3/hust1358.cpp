/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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

char s[30]={"mwjyalzvepsfobxqgduritnkch"};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char st[1024];
    int i,len,j;
    while(gets(st))
    {
        len=strlen(st);
        for(i=0;i<len;i++)
        {
            if(st[i]>='A'&&st[i]<='Z') st[i]=st[i]-'A'+'a';
            if(st[i]>='a'&&st[i]<='z')
            {
                for(j=0;j<26;j++)
                {
                    if(s[j]==st[i])
                     {
                        st[i]='a'+j;
                        break;
                     }
                }
            }
        }
        puts(st);
    }
    return 0;
}
//in each ciphertext, there are only lower letters and spaces
//Eb amjv jeqvadrakr, rvada mda xbfc fxnad farradu mby uqmjau.
