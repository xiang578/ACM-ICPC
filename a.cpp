/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Wed May 23 19:29:22 2018
File Name     :a.cpp
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
#include <utility>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int l=0,r=n;
    int ok = 0;
    double ans = 0;
    while(!ok)
    {
        int x = (l+r)/2;
        int y = (n+m)/2+1-x;
        vector<int>t;
        if(x-1>=0) t.push_back(nums1[x-1]);
        if(x-2>=0) t.push_back(nums1[x-2]);
        if(y-1>=0) t.push_back(nums2[y-1]);
        if(y-2>=0) t.push_back(nums2[y-2]);
        sort(t.begin(),t.end());
        int p=0x7fffffff;
        if(x<n) p = min(nums1[x],p);
        if(y<m) p = min(nums2[y],p);
        if(p>=t[t.size()-1])
        {
            ok = 1;
            if((n+m)%2) ans = (t[t.size()-1] + t[t.size()-2])*0.5;
            else ans = t[t.size()-1];
        }
        else{
            if(x>=n) {
                r=x;
            }
            else if(y>=m){
                l=x;
            }
            else{
                if(nums1[x]>nums2[y]){
                    r=x;
                }
                else{
                    l=x;
                }
            }
        }
    }
    return ans;
}
