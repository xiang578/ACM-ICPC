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
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        int a[123],b[123],t;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(a, a+n);
        // cout<<a[0]<<" "<<a[n-1]<<endl;
        if(a[0]!=a[1]) t=a[0];
        else t=a[n-1];
        for(int i=0;i<n;i++) {
            if(b[i]==t) cout<<i+1<<endl;
        }
    }  
    return 0;
}