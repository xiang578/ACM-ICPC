/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Thu May  3 10:11:59 2018
File Name     :zoj4032.cpp
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
    int n,_;
    cin>>_;
    vector<int>ans;
    while(_--)
    {
        scanf("%d",&n);
        ans.clear();
        if(n%2==0)
        {
            int x = 3*(n-1);
            int y = 1;
            while(y<=n-1)
            {
                ans.push_back(x);
                ans.push_back(y);
                x-=1;
                y+=2;
            }
            x = 2*(n-1);
            y = n-2;
            while(y>=0)
            {
                ans.push_back(x);
                ans.push_back(y);
                x+=1;
                y-=2;
            }
        }
        else {
            int x = 3*(n-1);
            int y = 1;
            while(y<=n-1)
            {
                ans.push_back(x);
                ans.push_back(y);
                x-=1;
                y+=2;
            }
            x = 2*(n-1);
            y = n-3;
            while(y>=0)
            {
                ans.push_back(x);
                ans.push_back(y);
                x+=1;
                y-=2;
            }
            ans.push_back(3*n-2);
            ans.push_back(n-1);
        }
        for(int i=0;i<ans.size();i+=2)
        {
            if(i) printf(" ");
            printf("%d %d",ans[i],ans[i+1]);
        }
        puts("");
    }
    return 0;
}
